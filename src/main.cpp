#include <Arduino.h>
// assign Pin's
#define tmosgate 3
#define led 2
#define pwm_signal 0
#define taster1 4

#define dc 1  // shortest duty cycle (1% equ. 2.55)
#define minutes 2
#define seconds 60

const unsigned long DUR1 = 540UL*seconds;
const unsigned long DUR2 = 540UL*60*minutes;

volatile int Dac = 0;
volatile int Cycle = 0;

long myTimer1 = 0;
bool timer1_enable = false;
long myTimer2 = 0;
bool timer2_enable = false;

// Overflow interrupt
ISR(TIMER1_OVF_vect) {
  static int remain;
  if (Cycle == 0) remain = Dac;
  if (remain >= 256) {
    OCR1A = 255; // high (Table 12-2)
    remain = remain - 256;
  } else {
    OCR1A = remain;
    remain = 0;
  }
  Cycle = (Cycle + 1) & 0x0F;
}

void pin2Interrupt(void)
{
  //is called for every PWM-Signal change
}

void analogWrite12(int value) {
  cli();
  Dac = value;
  sei();
}

void setup() {
  pinMode(taster1, INPUT_PULLUP);
  pinMode(pwm_signal, INPUT);
  pinMode(tmosgate, OUTPUT);
  digitalWrite(tmosgate, LOW);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  // Top value for high (Table 12-2)
  OCR1C = 255;
  // Timer/Counter1 doing PWM on OC1A (PB1)
  TCCR1 = 1 << PWM1A    // Pulse Width Modulator A Enable
          | 1 << COM1A0 // OC1x cleared on compare match. Set when TCNT1 = $00
          | 1 << CS10;  // PWM clock = CK
  TIMSK |= 1 << TOIE1; // Timer/Counter1 Overflow Interrupt Enable
  pinMode(1, OUTPUT);

 //attachInterrupt(digitalPinToInterrupt(IR_RECEIVE_PIN), pin2Interrupt, RAISING);

}

void pwm_on() {
  digitalWrite(led, HIGH);
  analogWrite12(dc);
  myTimer1 = millis();
  timer1_enable = true;
}

void tmos_on() {
  digitalWrite(tmosgate, HIGH);
  myTimer2 = millis();
  timer2_enable = true;
}

void pwm_off() {
  analogWrite12(0);
  digitalWrite(led, LOW);
  timer1_enable = false;
}

void tmos_off() {
  digitalWrite(tmosgate, LOW);
  timer2_enable = false;
}

void loop() {
  if (millis() > (DUR2 + myTimer1) && timer1_enable) {
    pwm_off();
  }
  if (millis() > (DUR1 + myTimer2) && timer2_enable) {
    tmos_off();
  }
  if (digitalRead(led) == LOW && digitalRead(taster1) == LOW) {
    pwm_on(); 
  }
  if (digitalRead(pwm_signal) == HIGH){
    tmos_on();
  }
}