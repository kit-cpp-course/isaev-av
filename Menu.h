#pragma once

#include <string>
#include <exception>

class Menu
{
	std::string oldDirectory;
	std::string newDirectory;

public:
	void writeDownOldDirectory(char * oldDir) { oldDirectory = oldDir; }
	void writeDownNewDirectory(char * newDir) { newDirectory = newDir; }
	void enterOldDirMessage();
	void enterNewDirMessage();
	std::string getOldDiretory() { return oldDirectory; }
	std::string getNewDiretory() { return newDirectory; }
	void endMessage();
	void showErrorMessage(const std::exception& exc);
};

