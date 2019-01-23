#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <exception>
#include "Metadata.h"

class InfoFromAudioFactory
{
public:

	// ��������� ���������� ����� ����� � ���� ������������ �� ������� ��������� Metadata.
	virtual Metadata getInfo(std::string strFileName) {}

	// ������� ������ ������ InfoFromAudio � ���������� ������ �� ����.
	static InfoFromAudioFactory * createObjInfoFromAudio();
};

//�����, ���������� �� ���������� ���������� �� ����� �����.
class InfoFromAudio : public InfoFromAudioFactory
{
	// ��������� �� �������� ������.
	FILE * audioFl = NULL;

	// ��������� �� ����� ������, ���������� ���������� ����� �����.
	Metadata * audioFileObj = NULL;

	// ����� ��� �������� ���������� � �� ��������� ����. 
	char * buffer;

	// ���������� ���� �����, ������� � ������� � ����� ����� ����������� ����������.  
	// @param audioFile - ��������� �� ����������� ����.
	long idv3FileOffset(FILE * audioFile);

public:

	// ����������.
	~InfoFromAudio();

	// ��������� ���������� ����� ����� � ���� ������������ �� ������� ��������� Metadata.
	Metadata getInfo(std::string strFileName);
};

// �����, ���������������� ����������� ����� ���������� what() ��� ���������� ��������� ���������� ����������
// � ���� ������� ������� ���� ��� ������.
class CantOpenAudioFileForReadingException : public std::exception
{
	virtual const char* what() const throw() { return "Can not open audio file for reading!"; }
};

// �����, ���������������� ����������� ����� ���������� what() ��� ���������� ��������� ���������� ����������
// � ���� ������� ���������� ���������� ������ ���� char* � ���� Metadata.
class CantCastInfoException : public std::exception
{
	virtual const char* what() const throw() { return "Can not cast info in struct type <<AudioFile>>!"; }
};

