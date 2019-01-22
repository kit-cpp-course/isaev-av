#include <iostream>
#include <cstring>
#include "Menu.h"

void Menu::getAllPaths(int argc, char * argv[])
{
	if ((argc != 5 && argc != 3) || argc == 1)
	{
		if (argc != 1) std::cout << "There could be only 0, 2 or 4 arguments.\nPlease, enter both paths manually:\n";

		enterOldDirMessage();
		enterNewDirMessage();
		return;
	}

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-old") == 0) writeDownOldDirectory(argv[++i]);
		else if (strcmp(argv[i], "-new") == 0) writeDownNewDirectory(argv[++i]);
		else i++;
	}

	if (!haveOldDir) enterOldDirMessage();
	if (!haveNewDir) enterNewDirMessage();
}

void Menu::enterOldDirMessage()
{
	std::cout << "Please, enter the path to the folder with the audio files to be cataloged or type <<exit>> to quit." << std::endl;
	std::cout << "Path: ";
	std::getline(std::cin, oldDirectory);
	haveOldDir = true;

	if (oldDirectory == "exit") exit(0);
}

void Menu::enterNewDirMessage()
{
	std::cout << std::endl << "Please, enter the path to location of a new folder to be created or type <<exit>> to quit." << std::endl;
	std::cout << "Path: ";
	std::getline(std::cin, newDirectory);
	haveNewDir = true;

	if (newDirectory == "exit") exit(0);
}

void Menu::endMessage()
{
	std::cout << "\nAll audio files successfully moved to a new directory!\n";
	system("pause");
}

void Menu::showErrorMessage(const std::exception& exc)
{
	std::cout << "\nFatal error!\n";
	std::cout << exc.what() << "\n";
	system("pause");
}
