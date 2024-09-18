// SPDX-License-Identifier: CC0-1.0

#include <stdbool.h>

#include <raylib.h>

#include "World.h"
#include "Game.h"

static double last_update_time = 0;

static bool event_triggered(double interval)
{
        double cur_time = GetTime();
        if (cur_time - last_update_time >= interval) {
                last_update_time = cur_time;
                return true;
        }
        return false;
}

int main (void)
{
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raySnake");
        SetTargetFPS(60);
        InitAudioDevice();

        Game * game = Game_create();

        while (!WindowShouldClose()) {
                // update elements
                if (event_triggered(0.2)) {
                        Game_update(game);
                }

                if (IsKeyPressed(KEY_UP) && game->snake->direction.y != 1) {
                        game->snake->direction = (Vector2){ 0, -1 };
                        game->running = true;
                } else if (IsKeyPressed(KEY_DOWN) && game->snake->direction.y != -1) {
                        game->snake->direction = (Vector2){ 0, 1 };
                        game->running = true;
                } else if (IsKeyPressed(KEY_LEFT) && game->snake->direction.x != 1) {
                        game->snake->direction = (Vector2){ -1, 0 };
                        game->running = true;
                } else if (IsKeyPressed(KEY_RIGHT) && game->snake->direction.x != -1) {
                        game->snake->direction = (Vector2){ 1, 0 };
                        game->running = true;
                }

                // draw frame
                BeginDrawing();
                Game_draw(game);
                EndDrawing();
        }

        Game_destroy(game);
        CloseAudioDevice();
        CloseWindow();
        return 0;
}