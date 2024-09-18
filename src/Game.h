// SPDX-License-Identifier: CC0-1.0

#ifndef RAYSNAKE_SRC_GAME_H_
#define RAYSNAKE_SRC_GAME_H_

#include "Food.h"
#include "Snake.h"

#define SOUND_PATH_EAT  "../assets/success-48018.mp3"
#define SOUND_PATH_WALL "../assets/error-sound-39539.mp3"

typedef struct Game {
        Sound eat_sound;
        Sound wall_sound;
        Snake * snake;
        Food * food;
        unsigned score;
        bool running;
} Game;

Game * Game_create(void);
void Game_destroy(Game * game);

void Game_draw(const Game * game);
void Game_update(Game * game);

#endif // RAYSNAKE_SRC_GAME_H_