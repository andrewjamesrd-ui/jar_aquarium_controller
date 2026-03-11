#include <Arduino.h>
#include "setup.h"
#include "lighting.h"

static const uint8_t WHITE_CHANNEL = 2;
static const uint8_t RGB_CHANNEL = 3;

static const uint16_t PWM_FREQ = 20000;
static const uint8_t PWM_RESOLUTION = 12;

static uint16_t whiteLevel = 0;
static uint16_t rgbLevel = 0;

void initLighting()
{
  ledcSetup(WHITE_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(WHITE_LED_MOSFET_PIN, WHITE_CHANNEL);

  ledcSetup(RGB_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(RGB_LED_MOSFET_PIN, RGB_CHANNEL);

  ledcWrite(WHITE_CHANNEL, 0);
  ledcWrite(RGB_CHANNEL, 0);
}

void setWhiteLight(uint16_t level)
{
  if (level > 4095) level = 4095;

  whiteLevel = level;
  ledcWrite(WHITE_CHANNEL, whiteLevel);
}

void setRGBLight(uint16_t level)
{
  if (level > 4095) level = 4095;

  rgbLevel = level;
  ledcWrite(RGB_CHANNEL, rgbLevel);
}

void updateLighting()
{
  // placeholder for sunrise/sunset logic later
}