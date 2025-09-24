#pragma once

#include <SDL3/SDL.h>


class Screen
{
public:
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	
private:
	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32 color = 0;
	SDL_Event event;
	double motion = 0;

public:
	Screen();
	void setColor(Uint8, Uint8, Uint8);
	bool processEvents();
	void setBackgroundColor(Uint8, Uint8, Uint8);
	void drawObject();
	void initializeScreen();
	void updateScreen();
	void deleteScreen();
	
};

