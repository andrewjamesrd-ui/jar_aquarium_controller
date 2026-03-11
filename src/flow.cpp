#include "Arduino.h"
#include "setup.h"
#include "flow.h"

volatile uint32_t pulseCount = 0;

float flowRateGPH = 0.0;
unsigned long lastFlowCalc = 0;

void IRAM_ATTR flowISR()
{
  pulseCount++;
}

void initFlowSensor()
{
  pinMode(FLOW_SENSOR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), flowISR, RISING);
}

void updateFlow()
{
  unsigned long now = millis();

  if (now - lastFlowCalc >= 1000)
  {
    detachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN));

    uint32_t pulses = pulseCount;
    pulseCount = 0;

    attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), flowISR, RISING);

    float frequency = pulses;  // pulses per second

    float flowLmin = frequency / 7.5;

    flowRateGPH = flowLmin * 15.8503;

    lastFlowCalc = now;
  }
}

float getFlowRate()
{
  return flowRateGPH;
}