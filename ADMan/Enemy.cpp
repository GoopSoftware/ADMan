#include "Enemy.h"
#include "Player.h"


Enemy::Enemy(Texture2D runningTexture) :
runningTexture(runningTexture)
{

}

Enemy::~Enemy() {

}


void Enemy::update(float deltaTime, float gameSpeed, Player &player) {

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

	switch (state) {

		case EnemyState::ATTACK:
			updateAttack(gameSpeed);
			break;
		

		case EnemyState::AIRATTACK:
			updateAirAttack(deltaTime, gameSpeed);
			break;


		}
	updateProjectile(deltaTime, gameSpeed, player);
}

void Enemy::updateAttack(float gameSpeed) {
	std::cout << "UpdateAttack" << std::endl;
	hurtBox = {
				static_cast<float>(dest.x + 20),
				static_cast<float>(dest.y + 34),
				static_cast<float>(dest.width - 370),
				static_cast<float>(dest.height - 370)
	};

	dest.x -= 7.f * gameSpeed;
	if (dest.x < 0 - 50) {
		dest.x = 1280;
	}
	
}

void Enemy::updateAirAttack(float deltaTime, float gameSpeed) {
	
	hurtBox = {
				static_cast<float>(dest.x + 20),
				static_cast<float>(dest.y + 34),
				static_cast<float>(dest.width - 370),
				static_cast<float>(dest.height - 370)
	};
	if (dest.x > 600.f && dest.y > 200.f) {
		airAttackVelocity = { -1000.f * gameSpeed, -200.f * gameSpeed };
		dest.x += airAttackVelocity.x * deltaTime;
		dest.y += airAttackVelocity.y * deltaTime;
	}
	
	//std::cout << "DX: " << dest.x << "DY: " << dest.y << std::endl;
	else  {
		if (!projectileActive) {
			airAttackVelocity = { 0, 0 };
			if (!fireProjectile) {
				fireProjectile = true;
				shootProjectile();
			}
		}
	}
}

void Enemy::shootProjectile(){
	//std::cout << "Shooting Projectile" << std::endl;
	
	projectilePos = { dest.x, dest.y };
	Vector2 targetPos = { 300, 445 };

	
	Vector2 direction = Vector2Subtract(targetPos, projectilePos);
	direction = Vector2Normalize(direction);
	
	float projectileSpeed = 500.f;
	projectileVelocity = Vector2Scale(direction, projectileSpeed);

	projectileActive = true;


}

void Enemy::updateProjectile(float deltaTime, float gameSpeed, Player &player) {
	if (projectileActive) {
		projectilePos = Vector2Add(projectilePos, Vector2Scale(projectileVelocity, deltaTime));
		
		
		if (CheckCollisionCircleRec(projectilePos, 50, player.getHurtBox())) {
			projectileVelocity = Vector2Scale(projectileVelocity, -1.0f);
			std::cout << "Projectile deflected" << std::endl;
		}
		
	}

	if (projectilePos.x < 0 || projectilePos.x > 1280 ||
		projectilePos.y < 0 || projectilePos.y > 640) {
		projectileActive = false;
	}
}


void Enemy::draw(float deltaTime, float gameSpeed) {

	DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
	DrawRectangleLines(hurtBox.x, hurtBox.y, hurtBox.width, hurtBox.height, GREEN);
	if (projectileActive) {
		DrawCircle(projectilePos.x, projectilePos.y, 25, RED);
	}
}