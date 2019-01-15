#pragma once

#include <vector>
#include <string>
#include <exception>
#include <Windows.h>

class AllAudioFilesList
{
	std::vector<std::string> AllAudioFileList;
	std::string searchPath;
	void makeList(std::string Path, std::vector<std::string> &fileList);

public:
	AllAudioFilesList(std::string Path) { searchPath = Path; }
	~AllAudioFilesList() { AllAudioFileList.clear(); searchPath.clear(); }
	std::vector<std::string> getAllMp3FileList();
};

class InvalidInputPathException : public std::exception
{
	virtual const char* what() const throw() { return "Invalid path! Make sure that the current folder is exist."; }
};


