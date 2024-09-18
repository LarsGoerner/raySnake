// SPDX-License-Identifier: CC0-1.0

#ifndef RAYSNAKE_SRC_SNAKE_H_
#define RAYSNAKE_SRC_SNAKE_H_

#include <stdlib.h>

#include <raylib.h>

typedef struct Snake {
        size_t body_len;
        size_t body_buf_len;
        Vector2 direction;
        Vector2 * body_buf;
} Snake;

Snake * Snake_create();
void Snake_destroy(Snake * s);

void Snake_draw(const Snake * s);
void Snake_update(Snake * s);
void Snake_grow(Snake * s);
void Snake_reset(Snake * s);

#endif // RAYSNAKE_SRC_SNAKE_H_