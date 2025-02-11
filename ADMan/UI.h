#pragma once

#include <iostream>
#include "raylib.h"


class UI
{

public:

	UI(Texture2D BG, Texture2D MG, Texture2D FG, Texture2D WW, const int screenWidth, const int screenHeight);
	~UI();

	const int screenWidth;
	const int screenHeight;


	void parallaxBackground(float deltaTime, float gameSpeed);


	float bgScrollSpeed = .05f;
	float mgScrollSpeed = 1.5f;
	float fgScrollSpeed = 10.f;
	float wwScrollSpeed = 200.f;



private:

	Texture2D BG;
	Texture2D MG;
	Texture2D FG;
	Texture2D WW;

	
	float bgOffset = 0.0f;
	float mgOffset = 0.0f;
	float fgOffset = 0.0f;
	float wwOffset = 0.0f;

	float scale = 2.0f;
	float bgScale = 3.45f;


};

