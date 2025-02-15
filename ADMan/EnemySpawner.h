#pragma once
#include "AssetManager.h"
#include "Enemy.h"


class EnemySpawner
{

public:
	EnemySpawner();
	~EnemySpawner();


	float spawnTimer = 0.0f;
	float spawnInterval = 2.0f;
	void update(float deltaTime, std::vector<Enemy*>& enemies, const AssetManager& assets, const int screenWidth);
	bool spawnEnemy = false;

private:



};

