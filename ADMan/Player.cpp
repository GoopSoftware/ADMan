#include "Player.h"



Player::Player(Texture2D runningTexture, Texture2D attackTexture) : 
runningTexture(runningTexture), attackTexture(attackTexture)
{

}


Player::~Player() {

}


void Player::update(float deltaTime) {
	
	timer += deltaTime;

	if (IsKeyPressed(KEY_SPACE)) {
		// Attacking logic
		std::cout << "Player Attack" << std::endl;
		state = PlayerState::ATTACKING;
		currentFrame = 0;
		timer = 0.0f;
	}
	if (IsKeyPressed(KEY_E)) {
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

			if (currentFrame == frameCount - 1) {
				state = PlayerState::RUNNING;
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

}
