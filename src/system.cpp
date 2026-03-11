#include <Wire.h>
#include "RTClib.h"
#include "system.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "flow.h"
#include "setup.h"

OneWire oneWire(WATER_TEMP_PIN);
DallasTemperature waterSensor(&oneWire);

RTC_DS3231 rtc;

SystemState systemState;

unsigned long lastRTC = 0;

void initSystem()
{
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  waterSensor.begin();

  if (!rtc.begin()) {
    Serial.println("RTC not found");
  }
}

void updateSystem()
{
  if (millis() - lastRTC >= 1000)
  {
    lastRTC = millis();

    DateTime now = rtc.now();

    systemState.hour = now.hour();
    systemState.minute = now.minute();
    systemState.second = now.second();

    float tempC = rtc.getTemperature();
    systemState.rtcTempF = (tempC * 9.0 / 5.0) + 32.0;

    systemState.flowGPH = getFlowRate();
  }

  waterSensor.requestTemperatures();
  float tempC = waterSensor.getTempCByIndex(0);
  systemState.waterTempF = tempC * 9.0 / 5.0 + 32.0;
}