#pragma once

#include "Kaleidoscope.h"
#include "MouseKeyDefs.h"
#include "MouseWarpModes.h"

class MouseKeys_ : public kaleidoscope::Plugin {
 public:
  MouseKeys_(void) {}

  static uint8_t speed;
  static uint16_t speedDelay;
  static uint8_t accelSpeed;
  static uint16_t accelDelay;
  static uint8_t wheelSpeed;
  static uint16_t wheelDelay;

  static void setWarpGridSize(uint8_t grid_size);
  static void setSpeedLimit(uint8_t speed_limit);

  kaleidoscope::EventHandlerResult onSetup();
  kaleidoscope::EventHandlerResult beforeReportingState();
  kaleidoscope::EventHandlerResult afterEachCycle();
  kaleidoscope::EventHandlerResult onKeyswitchEvent(Key &mappedKey, byte row, byte col, uint8_t keyState);

 private:
  static uint8_t mouseMoveIntent;
  static uint32_t endTime;
  static uint32_t accelEndTime;
  static uint32_t wheelEndTime;

  static void scrollWheel(uint8_t keyCode);
};

extern MouseKeys_ MouseKeys;
