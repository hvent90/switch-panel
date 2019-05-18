#include "TwoPositionLatchingSwitch.h"
// #include <Bounce.h>

TwoPositionLatchingSwitch::TwoPositionLatchingSwitch()
{
}

void TwoPositionLatchingSwitch::init(int pin)
{
  // _bounce = Bounce(pin, 10); // 10 = 10 ms debounce time
  pinMode(pin, INPUT_PULLUP);
  
  _pin = pin;
  _alternatePin = pin + 1;
  _toggle = true;
}

void TwoPositionLatchingSwitch::onUpdate()
{
//  _bounce.update();
  resetJoystickInput();

  int state = digitalRead(_pin);

  if (state && _lastState != 1) {
    on();
  }

  if (state && _lastState != 0) {
    off();
  }
}

void TwoPositionLatchingSwitch::resetJoystickInput()
{
  if (_toggle) {
    _activate(_pin, 0);
  } else {
    _activate(_alternatePin, 0);
    Joystick.button(_alternatePin, 0);
  }
}

void TwoPositionLatchingSwitch::on()
{
  activate(_pin, 1);

  _lastState = 1;
}

void TwoPositionLatchingSwitch::off()
{
  if (_toggle) {
    activate(_pin, 1);
  } else {
    activate(_alternatePin, 1);
  }

  _lastState = 0;
}

void TwoPositionLatchingSwitch::activate(int pin, int value)
{
  // Joystick.button(pin, value);
  Serial.println('pin: ' + pin + ', value: ' + value);
}

void TwoPositionLatchingSwitch::nextAvailablePin()
{
  if (_toggle) {
    return _pin + 1;
  } else {
    return _alternatePin + 1; 
  }
}
