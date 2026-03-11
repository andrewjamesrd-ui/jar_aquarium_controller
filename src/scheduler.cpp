#include "scheduler.h"

struct ScheduledTask
{
  TaskCallback callback;
  uint32_t intervalMs;
  uint32_t lastRunMs;
  bool enabled;
};

static const uint8_t MAX_TASKS = 10;
static ScheduledTask tasks[MAX_TASKS];

void initScheduler()
{
  for (uint8_t i = 0; i < MAX_TASKS; i++)
  {
    tasks[i].callback = nullptr;
    tasks[i].intervalMs = 0;
    tasks[i].lastRunMs = 0;
    tasks[i].enabled = false;
  }
}

bool addTask(TaskCallback callback, uint32_t intervalMs)
{
  if (callback == nullptr || intervalMs == 0)
  {
    return false;
  }

  for (uint8_t i = 0; i < MAX_TASKS; i++)
  {
    if (!tasks[i].enabled)
    {
      tasks[i].callback = callback;
      tasks[i].intervalMs = intervalMs;
      tasks[i].lastRunMs = millis();
      tasks[i].enabled = true;
      return true;
    }
  }

  return false;
}

void runScheduler()
{
  uint32_t now = millis();

  for (uint8_t i = 0; i < MAX_TASKS; i++)
  {
    if (!tasks[i].enabled)
    {
      continue;
    }

    if (now - tasks[i].lastRunMs >= tasks[i].intervalMs)
    {
      tasks[i].lastRunMs += tasks[i].intervalMs;
      tasks[i].callback();
    }
  }
}
