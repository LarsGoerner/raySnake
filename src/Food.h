// SPDX-License-Identifier: CC0-1.0

#ifndef RAYSNAKE_SRC_FOOD_H_
#define RAYSNAKE_SRC_FOOD_H_

#include <stdlib.h>

#include <raylib.h>

#define FOOD_MAX_COUNT          32
#define FOOD_IMG_NORMAL_PATH    "../assets/food_normal.png"
#define FOOD_IMG_RARE_PATH      "../assets/food_rare.png"
#define FOOD_IMG_XTRA_RARE_PATH "../assets/food_xtra_rare.png"

typedef struct Food {
        Vector2 position;
        Texture2D tex;
} Food;

Food * Food_create(Vector2 position, const char * img_path);
void Food_destroy(Food * f);

void Food_draw(const Food * f);
Vector2 Food_gen_new_pos(void);

#endif // RAYSNAKE_SRC_FOOD_H_