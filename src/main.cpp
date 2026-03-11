#include <Arduino.h>

#include "display.h"
#include "ui.h"
#include "system.h"
#include "flow.h"
#include "scheduler.h"
#include "pump.h"
#include "lighting.h"

// ============================
// Hardware Initialization
// ============================
void initHardware()
{
  initDisplay();
  initSystem();
  initFlowSensor();
  initUI();
  initPump();
  initLighting();
}

// ============================
// Task Scheduling
// ============================
void initTasks()
{
  addTask(updateSystem, 500);
  addTask(updateFlow, 200);
  addTask(updateUI, 250);
  addTask(updatePump, 100);
  addTask(updateLighting, 500);
}

void setup()
{
  Serial.begin(115200);

  initScheduler();
  initHardware();

  startPump(800);   // ~20% running power

  initTasks();
}

void loop()
{
  runScheduler();
}