// SPDX-License-Identifier: CC0-1.0

#include <errno.h>

#include "World.h"
#include "Food.h"
#include "colors.h"

Food * Food_create(Vector2 position, const char * img_path)
{
        Food * f = MemAlloc(sizeof(Food));
        Image image = LoadImage(img_path);
        f->tex = LoadTextureFromImage(image);
        f->position = position;
        UnloadImage(image);
        return f;
}

void Food_destroy(Food * f)
{
        UnloadTexture(f->tex);
        MemFree(f);
}

Vector2 Food_gen_new_pos(void)
{
        return (Vector2) {
                .x = GetRandomValue(0, CELL_COUNT_X - 1),
                .y = GetRandomValue(0, CELL_COUNT_Y - 1)
        };
}

void Food_draw(const Food * const f)
{
        DrawTexture(
                f->tex,
                f->position.x * CELL_SIZE + GAME_FIELD_OFFSET,
                f->position.y * CELL_SIZE + GAME_FIELD_OFFSET,
                WHITE
        );
}