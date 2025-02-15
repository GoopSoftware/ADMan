#pragma once

#include "raylib.h"
#include <vector>
#include <iostream>

class AssetManager
{

public:
	AssetManager();
	~AssetManager();


	Texture2D playerRun = LoadTexture("Assets/player katana run 80x64.png");
	Texture2D playerAttack = LoadTexture("Assets/player katana running attack.png");

	Texture2D flyingEye = LoadTexture("Assets/Flying Eye.png");
	Texture2D flyingEyeAttack = LoadTexture("Assets/Flying Eye Attack.png");

	Texture2D BG = LoadTexture("Assets/background.png");
	Texture2D MG = LoadTexture("Assets/mountains.png");
	Texture2D FG = LoadTexture("Assets/graveyard.png");
	Texture2D WW = LoadTexture("Assets/Walkway.png");


	std::vector<Texture2D> playerTextures = {playerRun, playerAttack};
	std::vector<Texture2D> enemyTextures = {flyingEye};
	std::vector<Texture2D> uiTextures = {BG, MG, FG, WW};



private:




};

