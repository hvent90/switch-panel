#ifndef TwoPositionLatchingSwitch_h
#define TwoPositionLatchingSwitch_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

/*
 * Connected to a single pin with value of {int}.
 * on(): => Joystick.button(pin, 1)
 * off(): => Joystick.button(pin + 1, 0)
 */
class TwoPositionLatchingSwitch {
  public:
    TwoPositionLatchingSwitch();

    // Configure the pins for input mode with pullup resistors.
    // The pushbuttons connect from each pin to ground.  When
    // the button is pressed, the pin reads LOW because the button
    // shorts it to ground.  When released, the pin reads HIGH
    // because the pullup resistor connects to +5 volts inside
    // the chip.  LOW for "on", and HIGH for "off" may seem
    // backwards, but using the on-chip pullup resistors is very
    // convenient.  The scheme is called "active low", and it's
    // very commonly used in electronics... so much that the chip
    // has built-in pullup resistors!
    void init(int pin);

    // Put onLoop() in loop{}
    void onUpdate();

    void resetJoystickInput();
    void on();
    void off();
    void activate(int pin, int value);

    int nextAvailablePin();

  private:
    // The associated pin on the Teensy board.
    // Determines the joystick button when switch is set to "on"
    unsigned int _pin;

    // The button to trigger on the Joystick when set to the "off" position on a switch set NOT to toggle
    unsigned int _alternatePin;
    
    // The last recorded reading (high or low) of the pin. Used to prevent multiple firings of on() or off().
    unsigned int _lastState;

    bool _toggle;
    
    // Create Bounce objects for each button.  The Bounce object
    // automatically deals with contact chatter or "bounce", and
    // it makes detecting changes very simple.
    // Bounce _bounce;
};

#endif
