#pragma once
#include "raylib.h"

class Entity
{

public:
	virtual ~Entity() {};


	virtual void update(float deltaTime) {};
	virtual void draw() {};



private:




};

