#include <Arduino.h>
#include <Bounce2.h>
#include <Timer.h>

#define dc 1  // shortest duty cycle (1% equ. 2.55)
#define taster1 4
#define led 2
#define lenable 0 // PWM for marker
#define minutes 20
const unsigned long DUR1 = 1000UL*60*minutes;
// Instantiate a Bounce object
Bounce debouncer = Bounce();
Timer t;  // Init Timer

void setup() {
        pinMode(taster1, INPUT_PULLUP);
        pinMode(led, OUTPUT);
        analogWrite(lenable, 0);
        digitalWrite(led, LOW);
        // After setting up the button, setup the Bounce instance :
        debouncer.attach(taster1);
        debouncer.interval(20); // interval in ms

/* Changing the PWM frequency
   Setting  Divisor   Frequency
   0x01     1        62500
   0x02   8        7812.5
   0x03   64       976.5625   <--DEFAULT
   0x04     256     244.140625
   0x05     1024    61.03515625

   TCCR0B = (TCCR0B & 0b11111000) | <setting>;
        TCCR0B = (TCCR0B & 0b11111000) | 0x02; // set to divide-by-8 prescale
 */

}

void pwm_on()
{
        analogWrite(lenable, dc);
        digitalWrite(led, HIGH);
}

void pwm_off()
{
        analogWrite(lenable, 0);
        digitalWrite(led, LOW);
}

void loop() {
        // Update the debouncer
        debouncer.update();
        t.update();
        if(digitalRead(led) == LOW)
        {
                if(debouncer.read() == LOW)
                {
                        pwm_on();
                        t.after(DUR1, pwm_off);
                }
        }
}
