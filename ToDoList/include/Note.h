#ifndef NOTE_H
#define NOTE_H

#include <iostream>

class Note {
public:

	bool exists;
	int id;
	std::string title;
	std::string description;
	

	Note();
	Note(bool exists, int id, std::string title, std::string description);


private:
};

#endif