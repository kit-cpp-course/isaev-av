#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <direct.h>
#include <cstdio>
#include "InfoFromAudio.h"
#include <errno.h>

struct BufferForMetadata
{
	std::string bufferPath;
	std::string bufferArtist;
	std::string bufferAlbum;
	std::string bufferFileName;
	std::string bufferSingnature;

};

class CatalogAudioToNewDir
{
	std::string newDirPath;
	std::vector<std::string> audioFilesPathList;
	InfoFromAudio metadataGetter;
	Metadata metadata;
	BufferForMetadata buffer;

	bool createCoreDirectory();
	const char * createCalalogPath(std::string filePath);
	void prepareBuffer();
	void clearBuffer();

public:
	CatalogAudioToNewDir(std::string path, std::vector<std::string> list) { newDirPath = path; audioFilesPathList = list; }
	void MoveAndCatalogFiles();
};

class CantCreateDirectoryException : public std::exception
{
	virtual const char* what() const throw() { return "Can not create new directory! Ñheck the entered path."; }
};

