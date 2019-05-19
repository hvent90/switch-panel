#include "PushButton.h"

PushButton::PushButton()
{
}

void PushButton::init(int pin)
{
  pinMode(pin, INPUT_PULLUP);

  _joystickButtonNumber = pin;
  _pin = pin;
}

void PushButton::onUpdate()
{
  int state = digitalRead(_pin);

  if (state == DigitalReadState::ON) {
    Joystick.button(_joystickButtonNumber, JoystickButtonState::JOY_ON);
  }

  if (state == DigitalReadState::OFF) {
    Joystick.button(_joystickButtonNumber, JoystickButtonState::JOY_OFF);
  }
}
