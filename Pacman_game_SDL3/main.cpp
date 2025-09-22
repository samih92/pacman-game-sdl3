

#include <iostream>
#include "Screen.h"

using namespace std;

int main() {

	Screen screen;
	int greenies = 0;

	while (true) {

		greenies++;
		if (greenies > 255) {
			greenies = 0;
		}
		screen.setColor(0, greenies, 0);
		screen.setBuffer();
		screen.updateScreen();

		if (screen.processEvents() == true) {
			cout << "break while loop" << endl;
			break;
		}
	}

	screen.deleteScreen();

	return 0;
}




