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
	~Note();

	int getId() const { return id; }

	void display();

protected:
	void _save();
	void _load();
};

#endif