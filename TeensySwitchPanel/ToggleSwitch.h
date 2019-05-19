#ifndef ToggleSwitch_h
#define ToggleSwitch_h
 
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
class ToggleSwitch {
  public:
    ToggleSwitch();

    // Configure the pins for input mode with pullup resistors.
    void init(int pin);

    // Put onUpdate() in loop{}
    void onUpdate();

  private:
    // The associated pin on the Teensy board.
    // Determines the joystick button when switch is set to "on"
    unsigned int _pin;
    
    // The last recorded reading (high or low) of the pin. Used to prevent multiple firings of on() or off().
    int _lastState;

    unsigned int _joystickButtonNumber;
    unsigned long _flickerDelay;
    unsigned long _lastActivatedTime;
};

#endif
