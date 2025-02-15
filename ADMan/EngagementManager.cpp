#include "EngagementManager.h"


EngagementManager::EngagementManager(Player& player, std::vector<Enemy*> enemies) :
	player(player), enemies(enemies)
{

}

EngagementManager::~EngagementManager() {

}

void EngagementManager::collisionManager() {

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

}