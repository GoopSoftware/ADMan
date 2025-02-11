#include "Enemy.h"


Enemy::Enemy(Texture2D runningTexture) :
runningTexture(runningTexture)
{

}

Enemy::~Enemy() {

}


void Enemy::update(float deltaTime, float gameSpeed) {

	timer += deltaTime * gameSpeed;

	// animates enemy
	if (timer >= frameTime) {
		currentFrame++;
		timer = 0.0f;
		if (currentFrame >= frameCount) {
			currentFrame = 0;
		}
		source.x = currentFrame * frameWidth;
	}

	// Moves enemy left
	hurtBox = { static_cast<float>(dest.x + 20),
				static_cast<float>(dest.y + 34),
				static_cast<float>(dest.width - 370),
				static_cast<float>(dest.height - 370)};
	dest.x -= 7.f * gameSpeed;
	if (dest.x < 0 - 50) {
		dest.x = 1280;
	}
	
}


void Enemy::draw() {

	DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
	DrawRectangleLines(hurtBox.x, hurtBox.y, hurtBox.width, hurtBox.height, GREEN);

}