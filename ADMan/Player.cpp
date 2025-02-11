#include "Player.h"



Player::Player(Texture2D runningTexture, Texture2D attackTexture, std::vector<Enemy*> enemies) : 
runningTexture(runningTexture), attackTexture(attackTexture), enemies(enemies)
{

}


Player::~Player() {

}


void Player::update(float deltaTime, float gameSpeed) {
	
	timer += deltaTime * gameSpeed;


	if (IsKeyPressed(KEY_A)) {
		// Attacking logic
		std::cout << "Player Attack" << std::endl;
		state = PlayerState::ATTACKING;
		currentFrame = 0;
		timer = 0.0f;
		
		
	}
	if (IsKeyPressed(KEY_D)) {
		// Dodge/Parry Logic
		std::cout << "Player Dodge/Parry" << std::endl;
		state = PlayerState::RUNNING;
		currentFrame = 0;
		timer = 0.0f;
	}

	switch (state) {
		case PlayerState::RUNNING:
			texture = runningTexture;
			frameCount = 8;

			source.width = static_cast<float>(frameWidth);
			source.height = static_cast<float>(frameHeight);

			break;

		case PlayerState::ATTACKING:
			// Maybe we split the texture up and alternate katana swings per space bar press
			texture = attackTexture;
			frameCount = 8;
			source.width = static_cast<float>(frameWidth);
			source.height = static_cast<float>(frameHeight);
			hitBox = {
					static_cast<float>(dest.x * xMult) + 60.f,
					static_cast<float>(dest.y * yMult) - 15.f,
					static_cast<float>(dest.width - 165),
					static_cast<float>(dest.height - 138)
			};
			if (currentFrame == frameCount - 1) {
				state = PlayerState::RUNNING;
				hitBox = {};
			}
			
			break;
	}


	if (timer >= frameTime) {
		currentFrame++;
		timer = 0.0f;
		if (currentFrame >= frameCount) {
			currentFrame = 0;
		}

		source.x = currentFrame * frameWidth;
	}

}


void Player::draw() {

	DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
	DrawRectangleLines(hurtBox.x, hurtBox.y, hurtBox.width, hurtBox.height, GREEN);
	DrawRectangleLines(hitBox.x, hitBox.y, hitBox.width, hitBox.height, RED);

}
