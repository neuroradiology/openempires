#pragma once

#include "Unit.h"

// Units, when alligned in a grid, must be referenced
// to their true linear unit array (defined in Units.[ch]).
// Sometimes, more than one unit will occupy a single grid location,
// and so the unit stack can reference any number of units on a single tile.

typedef struct
{
    Unit** reference;
    int32_t count;
    int32_t max;
}
Stack;

Stack Stack_Build(const int32_t max);

void Stack_Append(Stack* const, Unit* const);

void Stack_Free(const Stack);

bool Stack_IsWalkable(const Stack);

int32_t Stack_GetMaxPathIndex(const Stack, Unit* const);
