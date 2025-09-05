
#include <iostream>
#include <SDL3/SDL.h>

using namespace std;

int main() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed" << endl;
		return 1;
	}

	SDL_Window *window=SDL_CreateWindow()

	SDL_Quit();

	return 0;
}



