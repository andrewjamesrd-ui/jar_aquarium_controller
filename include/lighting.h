#pragma once
#include <stdint.h>

void initLighting();

void setWhiteLight(uint16_t level);
void setRGBLight(uint16_t level);

void updateLighting();