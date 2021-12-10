#include "HX711.h"

HX711 scale;

uint8_t dataPin = 3;
uint8_t clockPin = 2;

uint32_t start, stop;
volatile float f;

void setup()
{
  Serial.begin(115200);
  scale.begin(dataPin, clockPin);

  // TODO find a nice solution for this calibration..
  // load cell factor 20 KG
  // scale.set_scale(127.15);
  // load cell factor 5 KG
  scale.set_scale(1000);       // TODO you need to calibrate this yourself.
  // reset the scale to zero = 0
  scale.tare();
}


void loop()
{
  // continuous scale 4x per second
  f = scale.get_units(5);
  Serial.println(f);
  delay(100);
}
