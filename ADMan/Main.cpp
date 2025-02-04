#include <iostream>

#include "raylib.h"
#include "Player.h"
#include "UI.h"
#include "AssetManager.h"

/*
Genre: Soul-like
	- Collects score and when dies leaves score where died
	- Infinitely scrolling and boosting in complexity
	- Dim corridors, lighting elements

Rule: Two button controls
	- Attack
	- Dodge/Parry
	- Stamina balancing
		
Setting: Military
	- Tank https://bdragon1727.itch.io/pixel-tank-part-1
	- 

Theme: Pursuit
	- Player either pursues or is being pursued

*/

/* 
TODO:
	1. Change attack animations

*/



int main() {


	const int screenWidth = 1280;
	const int screenHeight = 640;
	InitWindow(screenWidth, screenHeight, "ADMan");
	SetTargetFPS(60);


	AssetManager assets;

	UI ui(assets.BG, assets.MG, assets.FG, assets.WW, screenWidth, screenHeight);

	Player player(assets.playerRun, assets.playerAttack);

	while (!WindowShouldClose()) {


		float deltaTime = GetFrameTime();
		player.update(deltaTime);

		
		if (IsKeyDown(KEY_A)) {
			ui.wwScrollSpeed -= 5.0f;
			std::cout << "WW: " << ui.wwScrollSpeed << std::endl;
	
		}
		if (IsKeyDown(KEY_D)) {
			ui.wwScrollSpeed += 5.0f;
			std::cout << "WW: " << ui.wwScrollSpeed << std::endl;
			

		}
		
		
		BeginDrawing();
		ClearBackground(RAYWHITE);

		ui.parallaxBackground(deltaTime);


		player.draw();

		EndDrawing();

		

	}
	
	CloseWindow();

	return 0;
}