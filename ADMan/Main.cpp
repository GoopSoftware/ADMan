#include <iostream>
#include <cmath>
#include <cstdlib>

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"

#include "UI.h"
#include "EngagementManager.h"
#include "AssetManager.h"
#include "EnemySpawner.h"


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


Ideas:
	- Make it a rhythm game


Assets Ideas:
	- https://luizmelo.itch.io/monsters-creatures-fantasy


*/

/* 
TODO:
	- Add boss class with boss enemy
	- Add flying eye fly away if projectile isnt deflected

BUGS:
	1. enemy hurtbox not following gameSpeed ( Maybe we keep this in order to give player more time to hit successfully
	2. If projectile doesnt have a clean deflection it gets stuck on the player (I'm assuming its the deflection logic angle)
	

*/



int main() {

	const int screenWidth = 1280;
	const int screenHeight = 640;
	InitWindow(screenWidth, screenHeight, "ADMan");
	SetTargetFPS(60);
	
	float gameSpeed = 1.0f;

	AssetManager assets;
	UI ui(assets.BG, assets.MG, assets.FG, assets.WW, screenWidth, screenHeight);

	std::vector<Enemy*> enemies;

	EnemySpawner enemySpawner;

	Player player(assets.playerRun, assets.playerAttack, enemies);
	srand(time(0));


	while (!WindowShouldClose()) {

		EngagementManager EM(player, enemies);

		float deltaTime = GetFrameTime();

		if (IsKeyDown(KEY_LEFT)) {
			gameSpeed -= .1f;
			std::cout << "GS: " << gameSpeed << std::endl;

		}
		if (IsKeyDown(KEY_RIGHT)) {
			gameSpeed += .1f;
			std::cout << "GS: " << gameSpeed << std::endl;
		}

		// Handles logic to spawn enemy and push_back enemies vector
		enemySpawner.update(deltaTime, enemies, assets, screenWidth);


		// Handles update logic of all entities
		player.update(deltaTime, gameSpeed);
		for (auto enemy : enemies) {
			enemy->update(deltaTime, gameSpeed, player);
		}

		// Handles all collisions between player and enemies vector
		EM.collisionManager(enemies);


		BeginDrawing();
		ClearBackground(RAYWHITE);

		// All UI elements
		ui.parallaxBackground(deltaTime, gameSpeed);


		// All entity animations
		for (auto& enemy : enemies) {
			enemy->draw(deltaTime, gameSpeed);
		}
		player.draw(deltaTime, gameSpeed);


		EndDrawing();
	}
	for (auto enemy : enemies) {
		delete enemy;
	}
	
	CloseWindow();

	return 0;
}