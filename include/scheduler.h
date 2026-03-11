#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

typedef void (*TaskCallback)();

void initScheduler();
bool addTask(TaskCallback callback, uint32_t intervalMs);
void runScheduler();

#endif
