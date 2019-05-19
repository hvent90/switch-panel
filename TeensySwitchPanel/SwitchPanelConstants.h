#ifndef SwitchPanelConstants_h
#define SwitchPanelConstants_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

enum DigitalReadState {
  ON = 0,
  OFF = 1
};

enum JoystickButtonState {
  JOY_ON = 1,
  JOY_OFF = 0
};

#endif
