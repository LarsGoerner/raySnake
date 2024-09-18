// SPDX-License-Identifier: CC0-1.0

#include <raylib.h>
#include <raymath.h>

#include "Game.h"
#include "World.h"
#include "Food.h"
#include "Snake.h"

static void Game_check_collision_food(Game * game)
{
        if (Vector2Equals(game->snake->body_buf[0], game->food->position)) {
                bool invalid_position = false;
                do {
                        game->food->position = Food_gen_new_pos();
                        for (size_t i = 0; i < game->snake->body_len; i++) {
                                if (Vector2Equals(game->snake->body_buf[i], 
                                                  game->food->position)) {
                                        invalid_position = true;
                                        break;
                                } else {
                                        invalid_position = false;
                                }
                        }
                } while (invalid_position);
                Snake_grow(game->snake);
                game->score++;
                PlaySound(game->eat_sound);
        }
}

static void Game_over(Game * game)
{
        Snake_reset(game->snake);
        game->running = false;
        game->score = 0;
}

static void Game_check_collision_wall(Game * game)
{
        Vector2 snake_head = game->snake->body_buf[0];
        if (snake_head.x >= CELL_COUNT_X || snake_head.x < 0 ||
            snake_head.y >= CELL_COUNT_Y || snake_head.y < 0) {
                PlaySound(game->wall_sound);
                Game_over(game);
        }
}

static void Game_check_collision_tail(Game * game)
{
        Vector2 head = game->snake->body_buf[0];
        for (size_t i = 1; i < game->snake->body_len; i++) {
                Vector2 tail_elem = game->snake->body_buf[i];
                if (Vector2Equals(head, tail_elem)) {
                        Game_over(game);
                        break;
                }
        }
}

Game * Game_create(void)
{
        Game * game = MemAlloc(sizeof(Game));
        game->food = Food_create(Food_gen_new_pos(), FOOD_IMG_XTRA_RARE_PATH);
        game->snake = Snake_create();
        game->running = true;
        game->score = 0;
        game->eat_sound = LoadSound(SOUND_PATH_EAT);
        game->wall_sound = LoadSound(SOUND_PATH_WALL);

        return game;
}

void Game_destroy(Game * game)
{
        Food_destroy(game->food);
        Snake_destroy(game->snake);
        UnloadSound(game->eat_sound);
        UnloadSound(game->wall_sound);
        MemFree(game);
}

void Game_draw(const Game * const game)
{
        World_draw(game);
        Food_draw(game->food);
        Snake_draw(game->snake);
}

void Game_update(Game * const game)
{
        if (game->running) {
                Snake_update(game->snake);
                Game_check_collision_food(game);
                Game_check_collision_wall(game);
                Game_check_collision_tail(game);
        }
}