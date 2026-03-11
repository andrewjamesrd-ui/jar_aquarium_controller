#include <Arduino.h>
#include "setup.h"
#include "pump.h"

static const uint8_t PUMP_PWM_CHANNEL = 1;
static const uint16_t PWM_FREQ = 20000;
static const uint8_t PWM_RESOLUTION = 12;

static const uint16_t START_POWER = 2867; // ~70%
static const uint32_t START_TIME_MS = 3000;

static uint16_t targetPower = 0;
static uint32_t startTime = 0;

enum PumpState
{
    PUMP_OFF,
    PUMP_STARTING,
    PUMP_RUNNING
};

static PumpState state = PUMP_OFF;

void initPump()
{
    ledcSetup(PUMP_PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(PUMP_MOSFET_PIN, PUMP_PWM_CHANNEL);

    ledcWrite(PUMP_PWM_CHANNEL, 0);
}

void startPump(uint16_t runPower)
{
    if (runPower > 4095)
        runPower = 4095;

    targetPower = runPower;

    ledcWrite(PUMP_PWM_CHANNEL, START_POWER);

    startTime = millis();
    state = PUMP_STARTING;
}

void stopPump()
{
    ledcWrite(PUMP_PWM_CHANNEL, 0);
    state = PUMP_OFF;
}

void updatePump()
{
    if(state == PUMP_STARTING)
    {
        if(millis() - startTime >= START_TIME_MS)
        {
            ledcWrite(PUMP_PWM_CHANNEL, targetPower);
            state = PUMP_RUNNING;
        }
    }
}