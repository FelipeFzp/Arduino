#include <Servo.h>
#include <IRremote.h>

int pinServo = 9;
int pinReceiver = 10;
int pos = 0;

Servo servo;
IRrecv irReceiver(pinReceiver);
decode_results result;

void setup() {
  Serial.begin(9600);
  servo.attach(pinServo);
  irReceiver.enableIRIn();
}

void loop() {
  if (irReceiver.decode(&result))
  {
    if (result.value == 0xFD6897 && pos < 170)
    {
      servo.write(pos ++);
      Serial.println(pos);
    }//up

    if (result.value == 0xFD58A7 && pos > 0)
    {
      servo.write(pos --);
      Serial.println(pos);
    }//down
      irReceiver.resume();
  Serial.println(result.value, HEX);
  }

}
