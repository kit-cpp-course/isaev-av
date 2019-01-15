#include <iostream>
#include "Menu.h"

void Menu::enterOldDirMessage()
{
	std::cout << "Please, enter the path to the folder with the audio files to be cataloged or type <<exit>> to quit." << std::endl;
	std::cout << "Path: ";
	std::getline(std::cin, oldDirectory);

	if (oldDirectory == "exit") exit(0);
}

void Menu::enterNewDirMessage()
{
	std::cout << std::endl << "Please, enter the path to location of a new folder to be created or type <<exit>> to quit." << std::endl;
	std::cout << "Path: ";
	std::getline(std::cin, newDirectory);

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
