#include "EnemySpawner.h"
#include <cmath>
#include <cstdlib>
#include <vector>

#include <random>



EnemySpawner::EnemySpawner() {

}

EnemySpawner::~EnemySpawner() {

}




void EnemySpawner::update(float deltaTime, float gameSpeed, std::vector<Enemy*>& enemies, const AssetManager& assets, const int screenWidth) {
	spawnTimer += deltaTime * gameSpeed;
	if (spawnTimer >= spawnInterval) {
		spawnTimer = 0.0f;
		spawnEnemy = true;
	}

	if (spawnEnemy) {
		spawnEnemy = false;

		Enemy* newEnemy = new Enemy(assets.flyingEye, assets.flyingEyeAttack);
		int result = rand() % 2;
		if (result == 0) {
			newEnemy->setAttackState(EnemyState::ATTACK);
		}
		else {
			newEnemy->setAttackState(EnemyState::AIRATTACK);
		}
		newEnemy->setPosition({ static_cast<float>(screenWidth) + 150, 345, static_cast<float>(150 * 3), static_cast<float>(150 * 3) });
		enemies.push_back(newEnemy);
	}


}