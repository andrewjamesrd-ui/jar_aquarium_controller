#include <Arduino.h>
#include "Display.h"
#include <TFT_eSPI.h>
#include "setup.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

void initDisplay()
{
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  sprite.createSprite(320, 240);
  sprite.fillSprite(TFT_BLACK);

  sprite.setTextColor(TFT_WHITE, TFT_BLACK);
  sprite.drawString("DISPLAY OK", 20, 20, 4);

  sprite.pushSprite(0, 0);
}