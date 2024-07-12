#include "../include/Menus.h"
#include "../include/Definitions.h"

// Base class constructors and methods
Menu::Menu() {
	this->title = "Menu";
	this->optionCount = 0; 
	this->options = nullptr;
}

Menu::Menu(string title, string options[], int optionCount) {
	this->title = title;
	this->optionCount = optionCount;
	this->options = new string[optionCount];
	for (int i = 0; i < optionCount; i++) {
		this->options[i] = options[i];
	}
}

Menu::~Menu() {
	delete[] this->options;
}

void Menu::displayMenu() const {
	// Print the top line
	for (int i = 0; i < MENU_WIDTH; i++) {
		cout << '-';
	}
	cout << endl;

	// Check if the title length is greater than the menu width
	if (title.length() >= MENU_WIDTH) {
		cout << title << endl;
	}
	else {
		int padding = (MENU_WIDTH - title.length()) / 2;

		// Print the spaces
		for (int i = 0; i < padding; i++) {
			cout << ' ';
		}

		cout << title << endl;
	}

	// Print bottom line
	for (int i = 0; i < MENU_WIDTH; i++) {
		cout << '-';
	}
	cout << endl;

	// Print the menu options
	for (int i = 0; i < optionCount; i++) {
		cout << (i + 1) << ") " << options[i] << endl;
	}
}

// MainMenu class constructors
MainMenu::MainMenu() : Menu("Main Menu", new string[3]{ "Deposit", "Withdraw", "Quit" }, 3) {}

MainMenu::MainMenu(string title, string options[], int optionCount) : Menu(title, options, optionCount) {}