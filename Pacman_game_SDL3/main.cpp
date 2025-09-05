
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

	SDL_Window* window = SDL_CreateWindow("Pacman game", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MINIMIZED);

	if (window == NULL) {
		SDL_Quit();
		return 2;
	}

	bool quit = false;
	SDL_Event event;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				quit = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}



