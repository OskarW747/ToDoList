#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "../include/Definitions.h"
#include "../include/Menus.h"

using namespace std;

int menuIndex = MAIN_MENU_INDEX;
bool mainLoop = true;

MainMenu mainMenu;
AddNoteTitleMenu addNoteTitleMenu;

void printMenu(Menu* _menu) {
	_menu->displayMenu();
}

bool checkMatch(int target, const std::vector<int>& arr) {
	for (int num : arr) {
		if (num == target) {
			return true;
		}
	}
	return false;
}

// Function to get integer input and check if input is valid
int getIntInput(const std::vector<int> _validInputs) {

	string _input;
	int _inputInt = 0;

	while (true)
	{
		cout << "> ";

		getline(cin, _input);

		try {
			_inputInt = stoi(_input);
		}
		catch (invalid_argument e) {
			cout << "Invalid input! Input must be of integer type!" << endl;
			continue;
		}

		if (checkMatch(_inputInt, _validInputs) == false) {
			cout << "Invalid input! Input must correspond with given alternatives!" << endl;
		}
		else {
			cout << "Input is valid!" << endl;
			return _inputInt;
		}
	}
	
}

// Function to get string input and check if input is valid
//string getStringInput(string _validKeyWords) {
//	return 0;
//}

void menuController() {
	switch (menuIndex) {
	case(MAIN_MENU_INDEX): {
		printMenu(&mainMenu);

		std::vector<int> validInputs = { MAIN_ADD_NOTE, MAIN_VIEW_NOTES, MAIN_EXIT };
		int _input = getIntInput(validInputs);

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
	case (ADD_NOTE_INDEX):
		printMenu(&addNoteTitleMenu);
		break;
	}
}

int main() {
	cout << "Hello World" << std::endl;

	static int lastMenuIndex = 0;

	//printMenu(&mainMenu);

	while (mainLoop == true) {
		
		if (menuIndex != lastMenuIndex)
		{
			lastMenuIndex = menuIndex;
			cout << "Menu controller updating" << endl;
			menuController();

		}
		
	}
	return 0;


}