#pragma once

#include "Entity.h"
#include <iostream>
#include <vector>
#include "enemy.h"


enum class PlayerState {
	RUNNING,
	ATTACKING,
	DODGE
};

class Player : Entity
{

public:
	Player(Texture2D runningTexture, Texture2D attackTexture, std::vector<Enemy*> enemies);
	~Player();

	

	void update(float deltaTime, float gameSpeed) override;
	void draw(float deltaTime, float gameSpeed) override;
	Rectangle getDest() { return dest; }
	Rectangle getHurtBox() { return hurtBox; }
	Rectangle getHitBox() { return hitBox; }
	//PlayerState getState() { return state; }
	std::vector<Enemy*> enemies;

	PlayerState state = PlayerState::RUNNING;


private:

	float timer = 0.0f;
	float gameSpeed{};
	int frameWidth{ 80 };
	int frameHeight{ 64 };
	int frameCount = 8;
	int currentFrame = 0;
	float frameTime = 0.06f;


	Texture2D runningTexture;
	Texture2D attackTexture;
	Texture2D texture = runningTexture;


	Rectangle source{ 0, 0, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
	Rectangle dest{ 300, 445, static_cast<float>(frameWidth * 3), static_cast<float>(frameHeight * 3) };

	Vector2 origin = { dest.width / 2, dest.height / 2 };

	float xMult = .9f;
	float yMult = .92f;
	Rectangle hurtBox = { static_cast<float>(dest.x * xMult),
						  static_cast<float>(dest.y * yMult),
						  static_cast<float>(dest.width - 172),
						  static_cast<float>(dest.height - 88) 
						};

	Rectangle hitBox = {};

	


};

