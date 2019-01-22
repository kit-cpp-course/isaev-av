#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <direct.h>
#include <cstdio>
#include "InfoFromAudio.h"
#include <errno.h>

// ���������, ����������� ����� ���������� ������ ����� � ���� ����� ���� string ��� ��������� ������ ������ CatalogAudioFiles.
struct BufferForMetadata
{
	// ����� ���� � ������������� �����.
	std::string bufferPath;

	// ����� �����������.
	std::string bufferArtist;

	// ����� �������.
	std::string bufferAlbum;

	// ����� ����� �����.
	std::string bufferFileName;

	// ����� ������� (�������� ����) �����.
	std::string bufferSingnature;

};


// �����, ���������� �� ����������� ����� ������ � ������ ���� � �� ������ ������������
// � ����������� � �� ����������� � �� �� ����������� �� ���� �������.
class CatalogAudioToNewDir
{
	// ������, �������� ���� � ������ ��������� �������� ����� ������, ������� ����� ������.
	std::string newDirPath;

	// ������, �������� ������ ����� � ����� ������, ������� ����� �������������� �������.
	std::vector<std::string> audioFilesPathList;

	// ��������� �� ��������� ������, ���������� �� ���������� ���������� �� ����� ������.
	InfoFromAudioFactory * metadataGetter;

	// ��������� ���������, �������� ���������� ����� � ���� ������ �������� �������� ���� char.
	Metadata metadata;

	// ��������� ���������, ����������� ����� ��� ���������� � �������� ���������� ����� � ���� ����� ���� string.
	BufferForMetadata buffer;

	// ����� ��������� ������� ������� ����� �������� ������� ��� ����� ������.
	// � ������ ������ ��� ���� ����� ������� ��� ����������, ���������� true.
	// � ������ ������ ��� �������� ��������� false.
	bool createCoreDirectory();

	// ���������� ����� ���� � ����� �� ������ ��� ����������.
	// @param filePath - ������� ���� � �����.
	const char * createCalalogPath(std::string filePath);

	// ��������� ����� ���������� ������ ���������� �� ������ ������ �� ���� metadata.
	void prepareBuffer();

	// ������� �� ������ ��� ���� ������.
	void clearBuffer();

public:
	// �����������.
	// @param path - ���� � ������ ��������� �������� ����� ������, ������� ����� ������.
	// @param list - ������, �������������� ����� ������ ����� � ����� ������, ������� ����� �������������� �������.
	CatalogAudioToNewDir(std::string path, std::vector<std::string> list) { newDirPath = path; audioFilesPathList = list; }

	// ����������� ����� ������, ���������� �������, �� ������ ������ � �� �������������.
	void MoveAndCatalogFiles();
};

// �����, ���������������� ����������� ����� ���������� what() ��� ���������� ��������� ���������� ����������
// � ���� ������� �������� �������� ������ CatalogAudioToNewDir ������ ��������� ��������.
class CantCreateDirectoryException : public std::exception
{
	virtual const char* what() const throw() { return "Can not create new directory! �heck the entered path."; }
};

