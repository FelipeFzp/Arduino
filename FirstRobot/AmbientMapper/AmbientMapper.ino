#include <Wire.h>

#define myAdress 0x08

const int ledPin = 13;
boolean ambientMap[186][186];

void setup() {
  Wire.begin(myAdress);
  Wire.onReceive(receiveEvent);
  pinMode(ledPin, OUTPUT);
}

void loop() {

}

void receiveEvent(int howMany) {
  char data[255] = {};
  int index = 0;
  while (Wire.available()) {
    char rawData = Wire.read();
    data[index] = rawData;
    index++;
  }
  if (sizeof(data) == 3) {
    saveCoordinates((int)data[0],(int)data[1],(boolean)data[2]);
  }
}
void saveCoordinates(int currentX, int currentY, boolean state)
{
  for (int column = 0; column <= currentX; column++)
    for ( int row = 0; row <= currentY; row++)
    {
      if (ambientMap[currentX][currentY] != NULL)
      {
        ambientMap[currentX][currentY] = state;
      }
    }
}
