// SPDX-License-Identifier: CC0-1.0

#include <raylib.h>
#include <raymath.h>

#include "colors.h"
#include "World.h"
#include "Snake.h"

#define INIT_BODY_BUF_LEN       32
#define INIT_BODY_LEN           3
#define INIT_POSITION_0         (Vector2){ 3, 1 }
#define INIT_POSITION_1         (Vector2){ 2, 1 }
#define INIT_POSITION_2         (Vector2){ 1, 1 }
#define INIT_DIRECTION          (Vector2){ 1, 0 }

Snake * Snake_create()
{
        Snake * s = MemAlloc(sizeof(Snake));
        s->body_buf = MemAlloc(sizeof(Vector2) * INIT_BODY_BUF_LEN);
        s->body_buf_len = INIT_BODY_BUF_LEN;
        s->body_buf[0] = INIT_POSITION_0;
        s->body_buf[1] = INIT_POSITION_1;
        s->body_buf[2] = INIT_POSITION_2;

        s->body_len = INIT_BODY_LEN;
        s->direction = INIT_DIRECTION;

        return s; 
}

void Snake_destroy(Snake * s)
{
        MemFree(s->body_buf);
        MemFree(s);
}

void Snake_draw(const Snake * const s)
{
        for (size_t i = 0; i < s->body_len; i++) {
                Rectangle rect = {
                        .x = s->body_buf[i].x * CELL_SIZE + GAME_FIELD_OFFSET,
                        .y = s->body_buf[i].y * CELL_SIZE + GAME_FIELD_OFFSET,
                        CELL_SIZE, CELL_SIZE };
                DrawRectangleRounded(rect, 0.5, 6, G2_COLOR);
        }
}

void Snake_update(Snake * const s)
{
        for (size_t i = s->body_len - 1; i > 0; i-- ) {
                s->body_buf[i] = s->body_buf[i - 1];
        }
        s->body_buf[0] = Vector2Add(s->body_buf[0], s->direction);
}

void Snake_grow(Snake * s)
{
        if (s->body_len >= s->body_buf_len) {
                s->body_buf_len *= 2;
                MemRealloc(s->body_buf, s->body_buf_len);
        }

        s->body_len++;
        s->body_buf[s->body_len - 1] = s->body_buf[s->body_len - 2];
}

void Snake_reset(Snake * s)
{
        s->body_len = INIT_BODY_LEN;
        s->direction = INIT_DIRECTION;
        s->body_buf[0] = INIT_POSITION_0;
        s->body_buf[1] = INIT_POSITION_1;
        s->body_buf[2] = INIT_POSITION_2;
}