#pragma once

#include <vector>
#include <string>
#include <exception>
#include <Windows.h>

// �����, ���������� �� ����������� ������� ����� �� ���� ������ c ������������
// mp3, wav, flac, ogg, m4a � wma � �������� � ���� ������������.
class AllAudioFilesList
{
	// ������ ��� �������� ������� ������.
	std::vector<std::string> AllAudioFileList;

	// ������, ���������� ���� � ��������, � ������� �������������� ����� ������.
	std::string searchPath;

	// �����, �������������� ����������� ������.
	void makeList(std::string Path, std::vector<std::string> &fileList);

public:
	// �����������.
	// @param Path - ������, ���������� ���� � ��������� ��������, �� �������� ����� ��������� ������.
	AllAudioFilesList(std::string Path) { searchPath = Path; }

	// ����������.
	~AllAudioFilesList() { AllAudioFileList.clear(); searchPath.clear(); }

	// ����� ������� � ���������� ������ ����� �� ���� ������ � ������������ mp3, wav, flac, ogg, m4a � wma
	// � �������� � ���� ������������.
	std::vector<std::string> getAllMp3FileList();
};

// �����, ���������������� ����������� ����� ���������� what() ��� ���������� ��������� ���������� ����������
// � ���� ���������� ������ makeList ������ AllAudioFiles.
class InvalidInputPathException : public std::exception
{
	// ��������������� ������������ ������ what().
	virtual const char* what() const throw() { return "Invalid path! Make sure that the current folder is exist."; }
};


