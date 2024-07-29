#include <iostream>
#include <string>
#include <algorithm>
#include "../include/Definitions.h"
#include "../include/Menus.h"

using namespace std;

int menuIndex = MAIN_MENU_INDEX;
bool mainLoop = true;

MainMenu mainMenu;

void printMenu(Menu* _menu) {
	_menu->displayMenu();
}

// Function to get integer input and check if input is valid
int getIntInput(int _validInputs[]) {

	string _input;
	int _inputInt;

	while (true)
	{
		cout << "> ";

		getline(cin, _input);

		try {
			_inputInt = stoi(_input);
			if (std::any_of(std::begin(_validInputs), std::end(_validInputs), [=](int n) {return n == _inputInt; })) {
				std::cout << "found match/" << std::endl;
			}
		}
		catch (invalid_argument e) {
			cout << "Invalid input! Input must be of integer type!" << endl;
		}

		

	}
	return _inputInt;
}

// Function to get string input and check if input is valid
//string getStringInput(string _validKeyWords) {
//	return 0;
//}

void menuController() {
	static int lastMenuIndex;

	switch (menuIndex) {
	case(MAIN_MENU_INDEX):
		printMenu(&mainMenu);

		int _input = getIntInput(1);

		switch (_input) {
		case(MAIN_ADD_NOTE):
			menuIndex = ADD_NOTE_INDEX;
			break;
		case(MAIN_VIEW_NOTES):
			menuIndex = VIEW_NOTES_INDEX;
			break;
		case(MAIN_EXIT):
			mainLoop = false;
			break;
		}
		break;
	}
}

int main() {
	cout << "Hello World" << std::endl;

	static int lastMenuIndex = 0;

	printMenu(&mainMenu);

	while (mainLoop == true) {

		if (lastMenuIndex != menuIndex)
		{
			cout << "Menu controller updating" << endl;
			menuController();

		}
		lastMenuIndex = menuIndex;
	}
	return 0;


}