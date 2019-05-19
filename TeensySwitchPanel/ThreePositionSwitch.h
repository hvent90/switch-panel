#ifndef ThreePositionSwitch_h
#define ThreePositionSwitch_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include "SwitchPanelConstants.h"
#include "PushButton.h"

/*
 * Two joystick buttons are mapped to when the switch is pushed "upwards" and "downards". The joystick buttons
 * are activated for as long as the switch is held in the "upwards" or "downards" state.
 * Connected to a single pin with value of {int}.
 */
class ThreePositionSwitch {
  public:
    ThreePositionSwitch();

    // Configure the pins for input mode with pullup resistors.
    void init(int pinUp, int pinDown);

    // Put onUpdate() in loop{}
    void onUpdate();

  private:
    // Activated when the switch is pushed "upwards"    
    PushButton _upButton;
    
    // Activated when the switch is pushed "downards"
    PushButton _downButton;
};

#endif
