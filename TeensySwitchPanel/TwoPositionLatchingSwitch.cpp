#include "TwoPositionLatchingSwitch.h"

TwoPositionLatchingSwitch::TwoPositionLatchingSwitch()
{
  _lastDebounceTime = 0;
  _debounceDelay = 100; // Increase if output flickers
}

void TwoPositionLatchingSwitch::init(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  
  _pin = pin;
  _alternatePin = pin + 1;
  _toggle = true;
}

void TwoPositionLatchingSwitch::onUpdate()
{
  // resetJoystickInput();

  int state = digitalRead(_pin);

  if (state == DigitalReadState::ON && _lastState != DigitalReadState::ON) {
    on();
  }

  if (state == DigitalReadState::OFF && _lastState != DigitalReadState::OFF) {
    off();
  }
}

void TwoPositionLatchingSwitch::resetJoystickInput()
{
  if (_toggle) {
    activate(_pin, 0);
  } else {
    activate(_alternatePin, 0);
  }
}

void TwoPositionLatchingSwitch::on()
{
  // Serial.println("On");
  activate(_pin, 1);

  _lastState = DigitalReadState::ON;
}

void TwoPositionLatchingSwitch::off()
{
  // Serial.println("Off");
  if (_toggle) {
    activate(_pin, 1);
  } else {
    activate(_alternatePin, 1);
  }

  _lastState = DigitalReadState::OFF;
}

void TwoPositionLatchingSwitch::activate(int pin, int value)
{  
  unsigned long currentTime = millis();

  String message = (String) "Current time: " + currentTime + ", _lastDebounceTime: " + _lastDebounceTime;
  Serial.println(message);

  if (currentTime - _lastDebounceTime < _debounceDelay) {
    return;
  }

  _lastDebounceTime = currentTime;
  
  Joystick.button(pin, value);
//  message = (String)"pin: " + pin + ", value: " + value;
//  Serial.println(message);
}

int TwoPositionLatchingSwitch::nextAvailablePin()
{
  if (_toggle) {
    return _pin + 1;
  } else {
    return _alternatePin + 1; 
  }
}
