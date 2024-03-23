#include "MainGame.h"

#include <iostream>
#include <string>
void fatalError(std::string errorString) {
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	// BUILT IN FUNCTION TO QUIT SDL
	SDL_Quit();
}

MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gamestate = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	// INIT THE SYSTEMS
	initSystems();
	
	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);
	//GAME LOOP
	gameLoop();
}

void MainGame::initSystems()
{
	// INITIALIZE SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//CREATE THE WINDOW AND RETURN THE POINTER OF IT TO THE _window VARIABLE
	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

	if (_window == nullptr) {
		fatalError("SDL Window could not be created!");
	}

	// CREATE/SET UP GL CONTEXT AND LINK IT TO THE WINDOW WE CREATED
	// THIS WILL BE USEFUL WHEN COLORING ETC..
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == NULL) {
		fatalError("SDL_GL context could not be created!");
	}

	// SET UP GLEW (optional but recommended)
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialize glew!");
	}
	// THIS TELLS THE SDL THAT WE WANT A DOUBLE BUFFER
	// WE WILL HAVE TWO WINDOWS, ONE THAT IS BEING DRAWN TO WHILE THE OTHER IS BEING CLEARED
	// AND VICE VERSA. THIS KEEPS IT FROM FLICKERING
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// SET THE BACKGROUND COLOR
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void MainGame::processInput()
{
	// HAVE AN EVENT STRUCT AND LOOP OVER IT TO GET ALL QUEUED EVENTS
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:
				_gamestate = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				std::cout << "COORDINATES OF X " << evnt.motion.x << " AND Y " << evnt.motion.y << std::endl;
				break;
		}
	}
}

void MainGame::drawGame() {
	// TELLS OPENGL WHAT DEPTH IT CLEARS TO
	glClearDepth(1.0);
	// CLEARS OUR SCREEN
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_sprite.draw();
	SDL_GL_SwapWindow(_window);
}
// MAIN GAME WILL BE HERE;
void MainGame::gameLoop()
{
	while (_gamestate != GameState::EXIT)
	{
		processInput();
		drawGame();
	}
}
