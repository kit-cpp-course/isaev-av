#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <exception>
#include "Metadata.h"

class InfoFromAudio
{
	FILE * audioFl;
	Metadata * audioFileObj;
	char* buffer;
	long idv3FileOffset(FILE* audioFile);

public:
	InfoFromAudio() { audioFl = NULL; audioFileObj = NULL; }
	~InfoFromAudio() { delete audioFl; delete audioFileObj; }
	Metadata getInfo(std::string strFileName);
};

class CantOpenAudioFileForReadingException : public std::exception
{
	virtual const char* what() const throw() { return "Can not open audio file for reading!"; }
};

class CantCastInfoException : public std::exception
{
	virtual const char* what() const throw() { return "Can not cast info in struct type <<AudioFile>>!"; }
};

