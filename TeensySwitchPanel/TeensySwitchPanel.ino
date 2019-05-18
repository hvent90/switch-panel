/* Buttons to USB Joystick Example

   You must select Joystick from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include "TwoPositionLatchingSwitch.h"

//TwoPositionLatchingSwitch twoPositionLatchingSwitches[1] = {
//  TwoPositionLatchingSwitch()
//};

TwoPositionLatchingSwitch twoPositionLatchingSwitch = TwoPositionLatchingSwitch();

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
//  for (int i = 0; i < twoPositionLatchingSwitches.size(); i++) {
//    twoPositionLatchingSwitches[i].init(i);
//  }

  twoPositionLatchingSwitch.init(2);
}

void loop() {
//  for (int i = 0; i < twoPositionLatchingSwitches.size(); i++) {
//    twoPositionLatchingSwitches[i].onUpdate();
//  }

  twoPositionLatchingSwitch.onUpdate();

  delay(1);
}
