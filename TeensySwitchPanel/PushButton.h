#ifndef PushButton_h
#define PushButton_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include "SwitchPanelConstants.h"

/*
 * The desired joystick button is activated for as long as the button is pressed.
 * Connected to a single pin with value of {int}.
 */
class PushButton {
  public:
    PushButton();

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
};

#endif
