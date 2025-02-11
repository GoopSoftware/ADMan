#pragma once
class EnemySpawner
{

public:
	EnemySpawner();
	~EnemySpawner();


	float spawnTimer = 0.0f;
	float spawnInterval = 2.0f;
	void update(float deltaTime);
	bool spawnEnemy = false;

private:



};

