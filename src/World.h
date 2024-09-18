// SPDX-License-Identifier: CC0-1.0

#ifndef RAYSNAKE_SRC_WORLD_H_
#define RAYSNAKE_SRC_WORLD_H_

#include "Game.h"

#define CELL_SIZE               16
#define CELL_COUNT_X            16
#define CELL_COUNT_Y            16
#define GAME_FIELD_OFFSET       32
#define SCREEN_WIDTH            (CELL_SIZE * CELL_COUNT_X + 2 * GAME_FIELD_OFFSET)
#define SCREEN_HEIGHT           (CELL_SIZE * CELL_COUNT_Y + 2 * GAME_FIELD_OFFSET)

void World_draw(const Game * game);

#endif // RAYSNAKE_SRC_WORLD_H_