#pragma once
#include <iostream>
#include <vector>

#include "Player.h"
#include "Enemy.h"

class EngagementManager
{

public:

	EngagementManager(Player& player, std::vector<Enemy*> enemies);
	~EngagementManager();

	std::vector<Enemy*> enemies;
	Player& player;

	bool isCollision = false;
	void collisionManager(std::vector<Enemy*>& enemies);

private:




};

