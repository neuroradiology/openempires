#pragma once

#include "File.h"
#include "Type.h"

#include <stdbool.h>

typedef enum
{
#define FILE_X(name, file, prio, walkable, type, max_speed, accel, health, attack, width, rotatable, single_frame, multi_state) name = file,
    FILE_X_GRAPHICS
#undef FILE_X
}
Graphics;

const char* Graphics_GetString(const Graphics);

uint8_t Graphics_GetHeight(const Graphics);

bool Graphics_IsWalkable(const Graphics);

Type Graphics_GetType(const Graphics);

int32_t Graphics_GetMaxSpeed(const Graphics);

int32_t Graphics_GetAcceleration(const Graphics);

int32_t Graphics_GetHealth(const Graphics);

int32_t Graphics_GetAttack(const Graphics);

int32_t Graphics_GetWidth(const Graphics);

bool Graphics_GetRotatable(const Graphics);

bool Graphics_GetSingleFrame(const Graphics);

bool Graphics_GetMultiState(const Graphics);
