#include <Arduino.h>
#include <TaskScheduler.h>

// assign Pin's
#define tmosgate 0
#define lenable 1 // PWM for marker
#define led 2
#define pwm_signal 3
#define button 4

// other defines
#define dc 1                  // duty cycle 1% equ. 2.55
#define dur2 5 * TASK_MINUTE // Lüfter Nachlauf
#define dur1 2 * TASK_MINUTE  // Marker Leuchtdauer
byte status = false;
volatile int Dac = 0;
volatile int Cycle = 0;

Scheduler ts;

void task1Callback();
void task2Callback();
void task3Callback();
void pwm_on();
void pwm_off();

// ==== Task definitions ========================
Task t1(100 * TASK_MILLISECOND, TASK_FOREVER, &task1Callback, &ts, true);
Task t2(0,TASK_ONCE, &task2Callback, &ts, false);
Task t3(0, TASK_ONCE, &task3Callback, &ts, false);

// ==== CODE ======================================================================================


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

void setup()
{
  pinMode(pwm_signal, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(lenable, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  digitalWrite(lenable, LOW);
  // Top value for high (Table 12-2)
  OCR1C = 255;
  // Timer/Counter1 doing PWM on OC1A (PB1)
  TCCR1 = 1 << PWM1A    // Pulse Width Modulator A Enable
          | 1 << COM1A0 // OC1x cleared on compare match. Set when TCNT1 = $00
          | 1 << CS10;  // PWM clock = CK
  TIMSK |= 1 << TOIE1;  // Timer/Counter1 Overflow Interrupt Enable
}

void loop()
{
  ts.execute();
}

void task1Callback()
{
  if (digitalRead(pwm_signal)){
    t1.disable();
    digitalWrite(tmosgate, HIGH);
    t2.restartDelayed(dur2);    // Lüfter Nachlauf
  } else {
    if ((digitalRead(led) == LOW) and (digitalRead(button) == LOW))
    {
      pwm_on();
      t3.enableDelayed(dur1);   // Dauer Laser Low Energy on
    }
  }
}

void task2Callback()
{
  digitalWrite(tmosgate, LOW);
  t1.enable();
}

void task3Callback()
{
  pwm_off();
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