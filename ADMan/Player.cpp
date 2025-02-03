#include "Player.h"



Player::Player(Texture2D texture) : 
texture(texture)
{

}

Player::~Player() {

}

void Player::update(float deltaTime) {

	timer += deltaTime;

	if (timer >= frameTime) {
		currentFrame++;
		timer = 0.0f;
		if (currentFrame >= frameCount) {
			currentFrame = 0;
		}

		source.x = currentFrame * frameWidth;

	}

	


	if (IsKeyPressed(KEY_SPACE)) {
		// Attacking logic
		std::cout << "Player Attack" << std::endl;
	}
	if (IsKeyPressed(KEY_E)) {
		// Dodge/Parry Logic
		std::cout << "Player Dodge/Parry" << std::endl;

	}
	if (IsKeyPressed(KEY_A)) {
		frameTime -= 0.01f;
		std::cout << frameTime;	
	}
	if (IsKeyPressed(KEY_D)) {
		frameTime += 0.01f;
		std::cout << frameTime;
	}

}


void Player::draw() {
	DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}
//DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint); // Draw a part of a texture defined by a rectangle with 'pro' parameters
