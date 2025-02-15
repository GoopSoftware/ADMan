#include "EngagementManager.h"


EngagementManager::EngagementManager(Player& player, std::vector<Enemy*> enemies) :
	player(player), enemies(enemies)
{

}

EngagementManager::~EngagementManager() {

}

void EngagementManager::collisionManager(std::vector<Enemy*>& enemies) {

	for (auto& enemy : enemies) {
		if (CheckCollisionRecs(enemy->getHurtBox(), player.getHurtBox())) {
			std::cout << "Collision" << std::endl;
		}
	}
	for (auto& enemy : enemies) {
		if (CheckCollisionRecs(player.getHitBox(), enemy->getHurtBox())) {
			std::cout << "Attacked Enemy";
			enemy->attacked = true;
		}
			
	}
	// Interates through enemies vector to check if enemy has been attacked or projectile lands and then delete enemy
	for (auto it = enemies.begin(); it != enemies.end();) {
		if ((*it)->attacked || (*it)->projectileHitEnemy) {
			delete* it;
			it = enemies.erase(it);
		}
		else {
			++it;
		}
	}
}

