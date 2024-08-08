#include "../include/Note.h"
#include <random>
#include <fstream>
#include <string>
#include <filesystem>

Note::Note() {
	this->exists = false;
	this->id = NULL;
	this->title = "";
	this->description = "";
}

Note::Note(bool exists, int id, std::string title, std::string description) {
	this->exists = exists;
	this->id = id;
	this->title = title;
	this->description = description;
	std::cout << "Note added! Values:\t" << this->exists << "\t" << this->id << "\t" << this->title << "\t" << this->description << std::endl;
}

void Note::_save() {
	std::ofstream saveFile;
	saveFile.open(std::to_string(this->id) + ".note.txt");
	saveFile << this->title << "\n" << this->description;
	saveFile.close();
	std::cout << "Note saved:\t" << this->id << std::endl;
	std::cout << "Savefile path:\t" << std::filesystem::current_path() << std::endl;
}

void Note::_load() {
	std::ifstream saveFile(this->id + "save.txt");

	if (saveFile.is_open() == false) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}
	
	int lineCount = 0;
	std::string line;
	while (std::getline(saveFile, line)) {
		lineCount++;
		std::cout << "Linecount: " << lineCount << std::endl;

		if (lineCount <= 1) {
			this->title = line;
		}
		else {
			this->description = line;
		}
	}

}

Note::~Note() {
	this->_save();
}

void Note::display() {
	std::cout << "Note:\t" << this->id << "\t" << this->title << "\t" << this->description << std::endl;
}