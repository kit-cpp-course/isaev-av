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
		AllAudioFilesList * fileList = new AllAudioFilesList(menu.getOldDiretory());
		std::vector<std::string> audioFilesList = fileList->getAllMp3FileList();
		delete fileList;

		CatalogAudioToNewDir * catalogFiles = new CatalogAudioToNewDir(menu.getNewDiretory(), audioFilesList);
		catalogFiles->MoveAndCatalogFiles();
	}
	catch (const std::exception& e)
	{
		menu.showErrorMessage(e);
		exit(1);
	}

	menu.endMessage();

	return 0;
}
