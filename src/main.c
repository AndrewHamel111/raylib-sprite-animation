#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"

#include "animation.h"

const int screenWidth = 600;
const int screenHeight = 600;
const Vector2 screenSize = {screenWidth, screenHeight};

Texture2D _texture;
SpriteAnimation _animation;

void UpdateDrawFrame(void);

int main()
{
	srand(time(0));

	InitWindow(screenWidth, screenHeight, "Raylib Sprite Animation by Andrew Hamel");

	_texture = LoadTexture("resources/tile.png");
	_animation = CreateSpriteAnimation(_texture, 3, (Rectangle[]) {
		(Rectangle){0, 0, 32, 32},
		(Rectangle){32, 0, 32, 32},
		(Rectangle){64, 0, 32, 32},
		(Rectangle){96, 0, 32, 32},
		(Rectangle){128, 0, 32, 32},
		(Rectangle){160, 0, 32, 32}
	}, 6);

	while(!WindowShouldClose())
	{
		UpdateDrawFrame();
	}

	DisposeSpriteAnimation(_animation);
	
	CloseWindow();
	
	return 0;
}

void UpdateDrawFrame(void)
{
	BeginDrawing();

		ClearBackground(RAYWHITE);

		Rectangle dest = { 32, 32, 512, 512 };
		Vector2 origin = { 0 };
		DrawSpriteAnimationPro(_animation, dest, origin, 0, WHITE);

	EndDrawing();
}