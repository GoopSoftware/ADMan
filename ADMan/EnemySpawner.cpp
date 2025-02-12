#include "EnemySpawner.h"


EnemySpawner::EnemySpawner() {

}

EnemySpawner::~EnemySpawner() {

}


void EnemySpawner::update(float deltaTime) {
	spawnTimer += deltaTime;
	if (spawnTimer >= spawnInterval) {
		spawnTimer = 0.0f;
		spawnEnemy = true;
	}
}