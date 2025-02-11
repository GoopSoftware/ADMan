#include "AssetManager.h"


AssetManager::AssetManager() {

}

AssetManager::~AssetManager() {
	std::cout << "Unloading Textures" << std::endl;
	UnloadTexture(playerRun);
	UnloadTexture(playerAttack);
	UnloadTexture(BG);
	UnloadTexture(FG);
	UnloadTexture(MG);
	UnloadTexture(WW);
	UnloadTexture(flyingEye);
}

