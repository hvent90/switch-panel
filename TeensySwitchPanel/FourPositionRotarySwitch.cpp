#include "FourPositionRotarySwitch.h"

FourPositionRotarySwitch::FourPositionRotarySwitch()
{
  _flickerDelay = 100;
}

void FourPositionRotarySwitch::init(int pin1, int pin2, int pin3, int joystickButtonNumbers[4])
{
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);

  for (int i = 0; i < sizeof(joystickButtonNumbers); i++) {
    _joystickButtonNumbers[i] = joystickButtonNumbers[i];
  }
 
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
}

void FourPositionRotarySwitch::onUpdate()
{
  int state1 = digitalRead(_pin1);
  int state2 = digitalRead(_pin2);
  int state3 = digitalRead(_pin3);

  int state;

  if (state1 == DigitalReadState::ON) {
    state = 0;
  } else if (state2 == DigitalReadState::ON) {
    state = 1;
  } else if (state3 == DigitalReadState::ON) {
    state = 2;
  } else {
    state = 3;
  }

  unsigned long currentTime = millis();
  unsigned long timeSinceLastActivation = currentTime - _lastActivatedTime;

  if (timeSinceLastActivation > _flickerDelay) {
    Joystick.button(_joystickButtonNumbers[state], JoystickButtonState::JOY_OFF);
  }
  
  if (state != _lastState && timeSinceLastActivation >= _flickerDelay) {
    Joystick.button(_joystickButtonNumbers[state], JoystickButtonState::JOY_ON);
    _lastActivatedTime = currentTime;
  }
  
  _lastState = state;
}
