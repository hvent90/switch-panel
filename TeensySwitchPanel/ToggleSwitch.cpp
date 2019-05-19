#include "ToggleSwitch.h"

ToggleSwitch::ToggleSwitch()
{
  _flickerDelay = 100;
}

void ToggleSwitch::init(int pin)
{
  pinMode(pin, INPUT_PULLUP);

  _joystickButtonNumber = pin;
  _pin = pin;
}

void ToggleSwitch::onUpdate()
{
  int state = digitalRead(_pin);

    unsigned long currentTime = millis();
    unsigned long timeSinceLastActivation = currentTime - _lastActivatedTime;

    if (timeSinceLastActivation > _flickerDelay) {
      Joystick.button(_joystickButtonNumber, JoystickButtonState::JOY_OFF);
    }
    
    if (state != _lastState && timeSinceLastActivation >= _flickerDelay) {
      Joystick.button(_joystickButtonNumber, JoystickButtonState::JOY_ON);
      _lastActivatedTime = currentTime;
    }
    
    _lastState = state;
}
