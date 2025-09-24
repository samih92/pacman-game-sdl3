

#include <iostream>
#include "Screen.h"

using namespace std;

int main() {

	Screen screen;
	

	while (true) {
		screen.setBackgroundColor(255,255,255);
		screen.drawObject();

		screen.updateScreen();

		if (screen.processEvents() == true) {
			break;
		}
	}

	screen.deleteScreen();

	return 0;
}




