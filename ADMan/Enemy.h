#pragma once

#include "Entity.h"
#include "iostream"
#include "raylib.h"
#include "raymath.h"

class Player;


enum class EnemyState {
	ATTACK,
	AIRATTACK
};

class Enemy
{

public:
	Enemy(Texture2D runningTexture, Texture2D attackTexture);
	~Enemy();

	
	void update(float deltaTime, float gameSpeed, Player &player);
	void draw(float deltaTime, float gameSpeed);
	Rectangle getHurtBox() { return hurtBox; }
	void setPosition(Rectangle newDest) { dest = newDest; }
	Rectangle getDest() { return dest; }

	enum class FlyingPos {
		position1,
		position2,
		position3,
		position4
	};

	Vector2 getFlyingPosition(FlyingPos pos);
	


	bool attacked = false;
	bool leftScreen = false;

	bool projectileDeflected = false;
	bool projectileHitEnemy = false;
	void updateAttack(float gameSpeed);
	void updateAirAttack(float deltaTime, float gameSpeed);
	void shootProjectile(float gameSpeed);
	void projectileDeflect(float gameSpeed);
	void updateProjectile(float deltaTime, float gameSpeed, Player &player);
	void setAttackState(EnemyState newState);

private:
	
	float timer = 0.0f;
	float gameSpeed{};

	
	int frameWidth{ 150 };
	int frameHeight{ 150 };
	int frameCount = 8;
	int currentFrame = 0;
	float frameTime = 0.06f;
	//Vector2 baseCenter = { 400, 545 };

	Vector2 airAttackVelocity{};
	Vector2 flyingTarget{};
	bool airTargetChosen = false;
	bool airAttack = false;
	bool fireProjectile = false;
	bool projectileActive = false;
	Vector2 projectilePos;
	Vector2 projectileVelocity;


	Texture2D runningTexture;
	Texture2D attackTexture;
	Texture2D texture = runningTexture;






	Rectangle source{ 0, 0, -static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
	Rectangle dest{ 880, 345, static_cast<float>(frameWidth * 3), static_cast<float>(frameHeight * 3)};

	Vector2 origin = { dest.width / 3, dest.height / 3 };


	Rectangle hurtBox = {};



	EnemyState state = EnemyState::AIRATTACK;
};

