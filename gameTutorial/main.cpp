#include "MainGame.h"

// SDL REQUIRES YOU TO WRITE THE MAIN WITH THESE ARGUEMENTS
// ARGC WHICH DEFINES THE NUMBER OF THE ARGUEMENTS IN COMMAND LINE WHILE ARGV DESCRIBE AN ARRAY OF STRINGS
// THIS WILL BE THE ENTRY PROGRAM OF OUR PROGRAM WHICH WILL START OUR GAME
int main(int argc, char** argv) {
	MainGame maingame;
	maingame.run();

	return 0;
}