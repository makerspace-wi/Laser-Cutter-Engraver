#include <Arduino.h>

#define dc 1  // shortest duty cycle (1% equ. 2.55)
#define taster1 4
#define led 2
#define lenable 0 // PWM for marker
#define minutes 2
const unsigned long DUR1 = 1000UL*60*minutes;
byte status = false;
volatile int Dac = 0;
volatile int Cycle = 0;

// Overflow interrupt
ISR (TIMER1_OVF_vect) {
        static int remain;
        if (Cycle == 0)
                remain = Dac;
        if (remain >= 256) {
                OCR1A = 255; // high (Table 12-2)
                remain = remain - 256;
        }
        else {
                OCR1A = remain;
                remain = 0;
        }
        Cycle = (Cycle + 1) & 0x0F;
}

void analogWrite12 (int value) {
        cli();
        Dac = value;
        sei();
}

void setup() {
        pinMode(taster1, INPUT_PULLUP);
        pinMode(led, OUTPUT);
        digitalWrite(lenable, LOW);
        digitalWrite(led, LOW);

        // Top value for high (Table 12-2)
        OCR1C = 255;
        // Timer/Counter1 doing PWM on OC1A (PB1)
        TCCR1 = 1 << PWM1A    // Pulse Width Modulator A Enable
                | 1 << COM1A0 // OC1x cleared on compare match. Set when TCNT1 = $00
                | 1 << CS10;  // PWM clock = CK
        TIMSK |= 1 << TOIE1; // Timer/Counter1 Overflow Interrupt Enable
        pinMode(1, OUTPUT);
}

void pwm_on()
{
        analogWrite12(dc);
        digitalWrite(led, HIGH);
}

void pwm_off()
{
        analogWrite12(0);
        digitalWrite(led, LOW);
}

void loop() {
        if(digitalRead(taster1) == LOW)
        {
                status = !status;
                while(digitalRead(taster1) == LOW);
                delay(20);         // keeps a small delay
                if (status == true) {
                        pwm_on();
                } else {
                        pwm_off();
                }
        }
}
