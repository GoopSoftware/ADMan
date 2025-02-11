#include "UI.h"

UI::UI(Texture2D BG, Texture2D MG, Texture2D FG, Texture2D WW, const int screenWidth, const int screenHeight) :
	BG(BG), MG(MG), FG(FG), WW(WW), screenWidth(screenWidth), screenHeight(screenHeight)
{

}

UI::~UI() {

}

void UI::parallaxBackground(float deltaTime, float gameSpeed) {


	bgOffset += (bgScrollSpeed * deltaTime) * gameSpeed;
	mgOffset += (mgScrollSpeed * deltaTime) * gameSpeed;
	fgOffset += (fgScrollSpeed * deltaTime) * gameSpeed;
	wwOffset += (wwScrollSpeed * deltaTime) * gameSpeed;

	if (mgOffset > MG.width) mgOffset -= MG.width;
	if (fgOffset > FG.width) fgOffset -= FG.width;
	if (bgOffset > BG.width) bgOffset -= BG.width;
	if (wwOffset > WW.width) wwOffset -= WW.width;



	for (int i = -1; i < screenWidth / (BG.width * bgScale) + 2; i++) {
		Vector2 pos = { i * BG.width * bgScale - static_cast<int>(bgOffset * bgScale),
						screenHeight - BG.height * bgScale + 25 };
		DrawTextureEx(BG, pos, 0.f, bgScale, WHITE);

	}

	for (int i = -1; i < screenWidth / (MG.width * scale) + 2; i++) {
		Vector2 pos = { i * MG.width * scale - static_cast<int>(mgOffset * scale),
						screenHeight - MG.height * scale - 100
		};
		DrawTextureEx(MG, pos, 0.0f, scale, WHITE);
	}

	for (int i = -1; i < screenWidth / FG.width + 2; i++) {
		Vector2 pos = { i * FG.width * scale - static_cast<int>(fgOffset * scale),
						screenHeight - FG.height * scale - 100

		};

		DrawTextureEx(FG, pos, 0.0f, scale, WHITE);
	}

	for (int i = -1; i < (screenWidth / (WW.width * scale)) + 2; i++) {
		Vector2 pos = { i * WW.width * scale - static_cast<int>(wwOffset * scale),
						screenHeight - WW.height * scale + 137
		};
		DrawTextureEx(WW, pos, 0.0f, scale, WHITE);

	}
}

