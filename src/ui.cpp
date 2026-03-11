#include <Arduino.h>
#include <string.h>
#include "ui.h"
#include "Display.h"
#include "system.h"

Screen currentScreen = SCREEN_BOOT;

unsigned long bootTimer = 0;

static bool dashboardDrawn = false;

static char lastTime[10] = "";
static char lastRtcTemp[12] = "";
static char lastWaterTemp[12] = "";
static char lastFlow[12] = "";

static void drawBoot()
{
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Aquarium Controller", 80, 120, 4);
}

static void drawDashboardStatic()
{
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString("Time:", 40, 40, 4);

  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.drawString("RTC Temp:", 40, 100, 4);
  tft.drawString("F", 340, 100, 4);

  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.drawString("Water Temp:", 40, 160, 4);
  tft.drawString("F", 340, 160, 4);

  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  tft.drawString("Flow:", 40, 220, 4);
  tft.drawString("GPH", 340, 220, 4);
}

static void drawIfChanged(char *lastValue, const char *newValue, int x, int y, int padding, uint16_t color)
{
  if (strcmp(lastValue, newValue) == 0)
  {
    return;
  }

  tft.setTextColor(color, TFT_BLACK);
  tft.setTextPadding(padding);
  tft.drawString(newValue, x, y, 4);
  tft.setTextPadding(0);

  strcpy(lastValue, newValue);
}

static void updateDashboardValues()
{
  char timeValue[10];
  char rtcTempValue[12];
  char waterTempValue[12];
  char flowValue[12];

  snprintf(timeValue, sizeof(timeValue), "%02d:%02d:%02d",
           systemState.hour,
           systemState.minute,
           systemState.second);

  dtostrf(systemState.rtcTempF, 4, 1, rtcTempValue);
  dtostrf(systemState.waterTempF, 4, 1, waterTempValue);
  dtostrf(systemState.flowGPH, 4, 1, flowValue);

  drawIfChanged(lastTime, timeValue, 200, 40, 130, TFT_GREEN);
  drawIfChanged(lastRtcTemp, rtcTempValue, 260, 100, 80, TFT_YELLOW);
  drawIfChanged(lastWaterTemp, waterTempValue, 260, 160, 80, TFT_CYAN);
  drawIfChanged(lastFlow, flowValue, 260, 220, 80, TFT_ORANGE);
}

void initUI()
{
  bootTimer = millis();
  dashboardDrawn = false;
  lastTime[0] = '\0';
  lastRtcTemp[0] = '\0';
  lastWaterTemp[0] = '\0';
  lastFlow[0] = '\0';
  drawBoot();
}

void updateUI()
{
  if (currentScreen == SCREEN_BOOT && (millis() - bootTimer > 2000))
  {
    currentScreen = SCREEN_DASHBOARD;
  }

  if (currentScreen == SCREEN_DASHBOARD)
  {
    if (!dashboardDrawn)
    {
      drawDashboardStatic();
      dashboardDrawn = true;
    }

    updateDashboardValues();
  }
}
