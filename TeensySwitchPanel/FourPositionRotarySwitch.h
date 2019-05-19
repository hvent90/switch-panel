#ifndef FourPositionRotarySwitch_h
#define FourPositionRotarySwitch_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include "SwitchPanelConstants.h"

/*
 * The desired Joystick button is activated for a brief moment every time the switch changes state.
 * Connected to a single pin with value of {int}.
 */
class FourPositionRotarySwitch {
  public:
    FourPositionRotarySwitch();

    // Configure the pins for input mode with pullup resistors.
    void init(int pin1, int pin2, int pin3, int joystickButtonNumbers[4]);

    // Put onUpdate() in loop{}
    void onUpdate();

  private:
    // The associated pins on the Teensy board.
    unsigned int _pin1;
    unsigned int _pin2;
    unsigned int _pin3;
    
    int _lastState;

    int _joystickButtonNumbers[];
    unsigned long _flickerDelay;
    unsigned long _lastActivatedTime;
};

#endif
