// This tab holds system values like RTC and sensors.

#ifndef SYSTEM_H
#define SYSTEM_H

struct SystemState
{
  int hour;
  int minute;
  int second;

  float rtcTempF;
  float waterTempF;
  float ph;
  float flowGPH;

};

extern SystemState systemState;

void initSystem();
void updateSystem();

#endif