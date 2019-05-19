#include "ThreePositionSwitch.h"

ThreePositionSwitch::ThreePositionSwitch()
{
  _upButton = PushButton();
  _downButton = PushButton();
}

void ThreePositionSwitch::init(int pinUp, int pinDown)
{
  _upButton.init(pinUp);
  _downButton.init(pinDown);
}

void ThreePositionSwitch::onUpdate()
{
  _upButton.onUpdate();
  _downButton.onUpdate();
}
