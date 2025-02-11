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
	1. Change attack animations
	2. Add collision detection in collision class
	3. Create combat decision logic inside engagementmanager
	5. Code enemy class
	 - Add enemy assets
	6. Add boss class
	7. Add enemy spawning and deconstructing system

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

		// Spawns a new enemy - The cleanliness of this isnt very good, We should move all logic into the update function
		enemySpawner.update(deltaTime);
		if (enemySpawner.spawnEnemy) {
			enemySpawner.spawnEnemy = false;
			Enemy* newEnemy = new Enemy(assets.flyingEye);
			newEnemy->setPosition({ screenWidth - 150, 345, static_cast<float>(150 * 3), static_cast<float>(150 * 3) });
			enemies.push_back(newEnemy);
		}

		// Handles update logic of all entities
		player.update(deltaTime, gameSpeed);
		for (auto enemy : enemies) {
			enemy->update(deltaTime, gameSpeed);
		}

		// Handles all collisions between player and enemies vector
		EM.collisionManager();
	
		for (auto it = enemies.begin(); it != enemies.end(); ) {
			if ((*it)->attacked) {
				delete* it;
				it = enemies.erase(it);
			}
			else {
				++it;
			}
		}

	
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// All UI elements
		ui.parallaxBackground(deltaTime, gameSpeed);


		// All entity animations
		for (auto& enemy : enemies) {
			enemy->draw();
		}
		player.draw();


		EndDrawing();
	}
	for (auto enemy : enemies) {
		delete enemy;
	}
	
	CloseWindow();

	return 0;
}