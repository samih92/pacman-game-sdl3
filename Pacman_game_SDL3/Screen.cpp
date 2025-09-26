
#include <iostream>
#include "Screen.h"

using namespace std;

Screen::Screen() {
	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	initializeScreen();
}

void Screen::setColor(Uint8 red, Uint8 green, Uint8 blue) {
	color = 0;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;
}

bool Screen::processEvents() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			return true;
		}
		else return false;
	}
}

void Screen::setBackgroundColor(Uint8 red, Uint8 green, Uint8 blue) {
	setColor(red, green, blue);
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = color;
	}
}

void Screen::drawObject() {
	setColor(0, 0, 0);
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (x < 700) {
				buffer[(y * SCREEN_WIDTH) + x] = color;
			}
		}
	}
	
}

void Screen::initializeScreen() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed" << endl;
	}

	 window = SDL_CreateWindow("Pacman game", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MINIMIZED);

	if (window == NULL) {
		SDL_Quit();
	}

	 renderer = SDL_CreateRenderer(window, NULL);
	 texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


	if (renderer == NULL) {
		cout << "Could not create renderer" << endl;
	}

	if (texture == NULL) {
		cout << "Could not create texture" << endl;
		deleteScreen();
	}

}

void Screen::updateScreen() {
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Screen::deleteScreen() {
	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
