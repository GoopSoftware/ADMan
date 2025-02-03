#pragma once

#include "Entity.h"
#include <iostream>



class Player : Entity
{

public:
	Player(Texture2D texture);
	~Player();


	void update(float deltaTime) override;
	void draw() override;
	void changeDest(Rectangle newDest) { dest = newDest; }



private:

	const int frameWidth = 48;
	const int frameHeight = 48;
	const int frameCount = 8;
	int currentFrame = 0;
	float frameTime = 0.06f;

	float timer = 0.0f;

	Vector2 position;
	Vector2 size;
	Texture2D texture;
	Rectangle source{ 0, 0, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
	Rectangle dest{ 300, 445, 144, 144 };
	Vector2 origin = { dest.width / 2, dest.height / 2 };

	bool isAttacking = false;
	bool isDodging = false;

};

