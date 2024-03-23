#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "Sprite.h"

enum class GameState {PLAY, EXIT};

class MainGame
{
private:
	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	Sprite _sprite;
	SDL_Window* _window;
	GameState _gamestate;
	int _screenWidth;
	int _screenHeight;

public:
	MainGame();
	~MainGame();

	void run();

};

