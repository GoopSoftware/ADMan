#include <iostream>

#include "raylib.h"
#include "Player.h"

/*
Soul-like
	- Collects score and when dies leaves score where died
	- Infinitely scrolling and boosting in complexity
	- Dim corridors, lighting elements

Two button controls
	- Attack
	- Dodge/Parry
	- Stamina balancing
		
Military
	- Tank https://bdragon1727.itch.io/pixel-tank-part-1
	- 

Pursuit
	- Player either pursues or is being pursued

*/



int main() {


	const int screenWidth = 1280;
	const int screenHeight = 640;
	InitWindow(screenWidth, screenHeight, "ADMan");
	SetTargetFPS(60);

	Texture2D playerTex = LoadTexture("Assets/player katana run.png");


	Player player(playerTex);

	while (!WindowShouldClose()) {

		float deltaTime = GetFrameTime();
		player.update(deltaTime);
		
		
		BeginDrawing();
		ClearBackground(RAYWHITE);

		player.draw();

		EndDrawing();

		

	}

	UnloadTexture(playerTex);
	CloseWindow();

	return 0;
}