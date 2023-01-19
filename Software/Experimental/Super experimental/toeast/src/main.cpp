// #include <Arduino.h>
// #include <stdint.h>
// #include "TouchScreen.h"

// #include <USB.h>
// // Serial.begin(115200);

// #define YP 15 // must be an analog pin, use "An" notation!
// #define XM 16 // must be an analog pin, use "An" notation!
// #define YM 14 // can be a digital pin
// #define XP 13 // can be a digital pin

// // For better pressure precision, we need to know the resistance
// // between X+ and X- Use any multimeter to read it
// // For the one we're using, its 300 ohms across the X plate
// TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// void setup(void)
// {
//   USBSerial.begin(9600);
// }

// void loop(void)
// {
//   // a point object holds x y and z coordinates
//   TSPoint p = ts.getPoint();

//   // we have some minimum pressure we consider 'valid'
//   // pressure of 0 means no pressing!
//   if (p.z > 2) // ts.pressureThreshhold
//   {
//     USBSerial.print("X = ");
//     USBSerial.print(p.x);
//     USBSerial.print("\tY = ");
//     USBSerial.print(p.y);
//     USBSerial.print("\tPressure = ");
//     USBSerial.println(p.z);
//   }

//   delay(100);
// }

// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'
// This demo code returns raw readings, public domain

#include <Arduino.h>
#include <stdint.h>
#include "TouchScreen.h"
#include <USB.h>

// These are the pins for the shield!
#define YP 14 // must be an analog pin, use "An" notation!
#define XM 16 // must be an analog pin, use "An" notation!
#define YM 13 // can be a digital pin
#define XP 15 // can be a digital pin

// 14 16 13 15

#define MINPRESSURE 10
#define MAXPRESSURE 950

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 330);
// TouchScreen ts = TouchScreen(14, 13, 16, 15, 300);

void setup(void)
{
  USBSerial.begin(9600);
}

void loop(void)
{
  // a point object holds x y and z coordinates
  TSPoint p = ts.getPoint();

  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
  {
    USBSerial.print("X = ");
    USBSerial.print(p.x);
    USBSerial.print("\tY = ");
    USBSerial.print(p.y);
    USBSerial.print("\tPressure = ");
    USBSerial.println(p.z);
  }
  delay(100);
}
