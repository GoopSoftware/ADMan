#pragma once
#include "AssetManager.h"
#include "Enemy.h"


class EnemySpawner
{

public:
	EnemySpawner();
	~EnemySpawner();


	void update(float deltaTime, float gameSpeed, std::vector<Enemy*>& enemies, const AssetManager& assets, const int screenWidth);


	float spawnTimer = 0.0f;
	float spawnInterval{1.75f};
	bool spawnEnemy = false;
	

private:



};

