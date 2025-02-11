#pragma once

#include "Entity.h"

class Enemy : Entity
{

public:
	Enemy(Texture2D runningTexture);
	~Enemy();

	void update(float deltaTime, float gameSpeed) override;
	void draw() override;
	Rectangle getHurtBox() { return hurtBox; }
	void setPosition(Rectangle newDest) { dest = newDest; }
	Rectangle getDest() { return dest; }

	bool attacked = false;


private:

	float timer = 0.0f;
	float gameSpeed{};

	int frameWidth{ 150 };
	int frameHeight{ 150 };
	int frameCount = 8;
	int currentFrame = 0;
	float frameTime = 0.06f;
	//Vector2 baseCenter = { 400, 545 };


	Texture2D runningTexture;
	Texture2D texture = runningTexture;



	Rectangle source{ 0, 0, -static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
	Rectangle dest{ 880, 345, static_cast<float>(frameWidth * 3), static_cast<float>(frameHeight * 3)};

	Vector2 origin = { dest.width / 3, dest.height / 3 };


	Rectangle hurtBox = {};

};

