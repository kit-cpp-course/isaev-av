#include "AllAudioFilesList.h"

void AllAudioFilesList::makeList(std::string Path, std::vector<std::string> &fileList)
{
	std::string searchPath = Path + "\\*.*";
	WIN32_FIND_DATA fd;
	HANDLE handle = FindFirstFile(searchPath.c_str(), &fd);

	if (handle == INVALID_HANDLE_VALUE)
	{
		 InvalidInputPathException invalidInputPathExc;
		 throw invalidInputPathExc;
	}

	do {
		searchPath = fd.cFileName;
		if (searchPath != "." && searchPath != "..")
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
			{
				searchPath = Path + "\\" + searchPath;
				if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) makeList(searchPath, fileList);
				else if (fd.nFileSizeLow != 0 || fd.nFileSizeHigh != 0)
				{
					if (searchPath.find(".mp3") != std::string::npos) fileList.push_back(searchPath);
					else if (searchPath.find(".wav") != std::string::npos) fileList.push_back(searchPath);
					else if (searchPath.find(".flac") != std::string::npos) fileList.push_back(searchPath);
					else if (searchPath.find(".ogg") != std::string::npos) fileList.push_back(searchPath);
					else if (searchPath.find(".m4a") != std::string::npos) fileList.push_back(searchPath);
					else if (searchPath.find(".wma") != std::string::npos) fileList.push_back(searchPath);
				}
			}
		}
	} while (FindNextFile(handle, &fd));

	FindClose(handle);
}

std::vector<std::string> AllAudioFilesList::getAllMp3FileList()
{
	makeList(searchPath, AllAudioFileList);

	return AllAudioFileList;
}