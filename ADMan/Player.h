#pragma once

#include "Entity.h"
#include <iostream>



class Player : Entity
{

public:
	Player(Texture2D runningTexture, Texture2D attackTexture);
	~Player();


	void update(float deltaTime) override;
	void draw() override;
	void changeDest(Rectangle newDest) { dest = newDest; }

	


private:

	int frameWidth{80};
	int frameHeight{64};
	int frameCount = 8;
	int currentFrame = 0;
	float frameTime = 0.06f;
	Vector2 baseCenter = { 400, 545 };

	float timer = 0.0f;

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
						  static_cast<float>(dest.height - 88)  };

	enum class PlayerState {
		RUNNING,
		ATTACKING,
		DODGE
	};
	PlayerState state = PlayerState::RUNNING;
};

