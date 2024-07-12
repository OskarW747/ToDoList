#include <iostream>
#include <string>
#include "../include/Definitions.h"
#include "../include/Menus.h"

using namespace std;

int menuIndex = MAIN_MENU_INDEX;
bool mainLoop = true;

MainMenu mainMenu;

void printMenu(Menu *_menu) {
	_menu->displayMenu();
}

void menuController() {
	switch (menuIndex) {
	case(MAIN_MENU_INDEX):
		printMenu(&mainMenu);

		// get input
		string _input;
		int _inputInt;
		getline(cin, _input);


		try {
			_inputInt = stoi(_input);
		}
		catch (invalid_argument e) {
			cout << "Invalid input";
		}

		switch (_inputInt) {
		case(MAIN_DEPOSIT):

		}
	}
}

int main() {
	cout << "Hello World" << std::endl;

	string input;

	printMenu(&mainMenu);

	while (mainLoop) {
		
		menuController();

	}
	return 0;


}