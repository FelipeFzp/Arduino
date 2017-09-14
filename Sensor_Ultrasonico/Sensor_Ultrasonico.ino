#include <Ultrasonic.h>

#define pin_trigger 4
#define pin_echo 5

#define pin_led_green 6
#define pin_led_red 8
#define pin_led_yellow 7

Ultrasonic ultrasonic(pin_trigger, pin_echo);

void setup() {
  Serial.begin(9600);
  pinMode(pin_led_green, OUTPUT);
  pinMode(pin_led_yellow, OUTPUT);
  pinMode(pin_led_red, OUTPUT);
}

void loop() {
  float cmMsec;
  
  long us = ultrasonic.timing();
  cmMsec = ultrasonic.convert(us, Ultrasonic::CM);
  Serial.print(cmMsec);
  Serial.println("cm");
  if(cmMsec < 10)
  {
    digitalWrite(pin_led_red, 1);
    digitalWrite(pin_led_green, 0);
    digitalWrite(pin_led_yellow, 0);
    delay(40);
  }
  if(cmMsec > 10 && cmMsec < 30)
  {
    digitalWrite(pin_led_red, 0);
    digitalWrite(pin_led_green, 0);
    digitalWrite(pin_led_yellow, 1);
    delay(40);
  }
  if(cmMsec > 30)
  {
    digitalWrite(pin_led_red, 0);
    digitalWrite(pin_led_green, 1);
    digitalWrite(pin_led_yellow, 0);
    delay(40);
  }
}
