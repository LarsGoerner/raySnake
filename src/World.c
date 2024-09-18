// SPDX-License-Identifier: CC0-1.0

#include <inttypes.h>

#include <raylib.h>

#include "colors.h"
#include "World.h"
#include "Game.h"

void World_draw(const Game * const game)
{
        ClearBackground(G1_COLOR);
        DrawRectangleLinesEx((Rectangle){ 
                .x = GAME_FIELD_OFFSET - 5, 
                .y = GAME_FIELD_OFFSET - 5,
                .width = CELL_SIZE * CELL_COUNT_X + 10,
                .height = CELL_SIZE * CELL_COUNT_Y + 10 },
                5, G0_COLOR);
        DrawText("raySnake", GAME_FIELD_OFFSET, 4, 24, G0_COLOR);
        DrawText(TextFormat("Score %" PRIu32, game->score), 
                 GAME_FIELD_OFFSET, GAME_FIELD_OFFSET + CELL_SIZE * CELL_COUNT_Y + 4,
                 24, G0_COLOR);
        return;
}