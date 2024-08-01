#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include "Definitions.h"

using namespace std;

// Base class for a menu
class Menu {
public:
	Menu();
	Menu(string title, string options[], int optionCount);
	virtual ~Menu();

	virtual void displayMenu() const;
protected:
	string title;
	string* options;
	int optionCount;
};

class MainMenu: public Menu {
public:
	MainMenu();
	MainMenu(string title, string options[], int optionCount);

private:

};

class AddNoteTitleMenu : public Menu {
public:
	AddNoteTitleMenu();
	AddNoteTitleMenu(string title, string options[], int optionCount);

private:
};

#endif