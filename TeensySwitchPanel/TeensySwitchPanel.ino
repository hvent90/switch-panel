/* Buttons to USB Joystick Example

   You must select Joystick from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include "ToggleSwitch.h"
#include "PushButton.h"

ToggleSwitch toggleSwitch = ToggleSwitch();
PushButton pushButton = PushButton();

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pushButton.init(2);
}

void loop() {
  pushButton.onUpdate();
  
  delay(1);
}
