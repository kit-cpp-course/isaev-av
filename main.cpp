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

	try
	{ 
		if (argc > 1) menu.writeDownOldDirectory(argv[1]);
		else menu.enterOldDirMessage();

		AllAudioFilesList * fileList = new AllAudioFilesList(menu.getOldDiretory());
		std::vector<std::string> audioFilesList = fileList->getAllMp3FileList();
		delete fileList;

		if (argc > 2) menu.writeDownNewDirectory(argv[2]);
		else menu.enterNewDirMessage();

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
