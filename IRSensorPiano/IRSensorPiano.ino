#include <IRremote.h>

int receiverPin = 11;
int ledPin = 13;
int soundPin = 9;
int timeMls = 500;

IRrecv irReceiver(receiverPin);
decode_results result;

void setup() {
  Serial.begin(9600);
  pinMode(soundPin, OUTPUT);
  irReceiver.enableIRIn();
}

void loop() {
  if (irReceiver.decode(&result))
  {
    Serial.println(result.value, HEX);
    irReceiver.resume();
    if (result.value == 0xFD6897) //INCREMENT TIME
    {
      digitalWrite(ledPin, HIGH);
      timeMls = timeMls + 250;
      Serial.println(timeMls);
      digitalWrite(ledPin, LOW);

    }
    if (result.value == 0xFD58A7) //DECREMENT TIME
    {
      digitalWrite(ledPin, HIGH);
      if(timeMls > 250)
        timeMls = timeMls - 250;
      Serial.println(timeMls);
      digitalWrite(ledPin, LOW);

    }
    if (result.value == 0xFDA857) //RESET TIME
    {
      digitalWrite(ledPin, HIGH);
      timeMls = 250;
      digitalWrite(ledPin, LOW);

    }
    if (result.value == 0xFD00FF)//DÓ
    {
      digitalWrite(ledPin, HIGH);
      tone(soundPin, 264, timeMls);
      digitalWrite(ledPin, LOW);

    }
    if (result.value == 0xFD807F)//RÉ
    {
      digitalWrite(ledPin, HIGH);
      tone(soundPin, 297, timeMls);
      digitalWrite(ledPin, LOW);

    }
    if (result.value == 0xFD40BF)//MI
    {
      digitalWrite(ledPin, HIGH);
      tone(soundPin, 330, timeMls);
      digitalWrite(ledPin, LOW);

    }
    if (result.value == 0xFD20DF)//FA
    {
      digitalWrite(ledPin, HIGH);
      tone(soundPin, 352, timeMls);
      digitalWrite(ledPin, LOW);

    }
    if (result.value == 0xFDA05F)//SOL
    {
      digitalWrite(ledPin, HIGH);
      tone(soundPin, 396, timeMls);
      digitalWrite(ledPin, LOW);

    }
        if (result.value == 0xFD609F)//LA
    {
      digitalWrite(ledPin, HIGH);
      tone(soundPin, 440, timeMls);
      digitalWrite(ledPin, LOW);

    }
        if (result.value == 0xFD10EF)//SI
    {
      digitalWrite(ledPin, HIGH);
      tone(soundPin, 495, timeMls);
      digitalWrite(ledPin, LOW);

    }
  }
}
