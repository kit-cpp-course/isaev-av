#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "Menu.h"
#include "AllAudioFilesList.h"
#include "CatalogAudioToNewDir.h"

int main(int argc, char * argv[])
{
	Menu menu;
	menu.getAllPaths(argc, argv);

	try
	{ 
		AllAudioFilesList fileList(menu.getOldDiretory());
		std::vector<std::string> audioFilesList = fileList.getAllMp3FileList();

		CatalogAudioToNewDir catalogFiles(menu.getNewDiretory(), audioFilesList);
		catalogFiles.MoveAndCatalogFiles();
	}
	catch (const std::exception& e)
	{
		menu.showErrorMessage(e);
		exit(1);
	}

	menu.endMessage();

	return 0;
}
