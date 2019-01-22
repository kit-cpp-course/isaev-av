#pragma once

#include <vector>
#include <string>
#include <exception>
#include <Windows.h>

// Класс, отвечающий за составление списока путей ко всем файлам c расширениями
// mp3, wav, flac, ogg, m4a и wma в каталоге и всех подкаталогах.
class AllAudioFilesList
{
	// Вектор для хранения адресов файлов.
	std::vector<std::string> AllAudioFileList;

	// Строка, содержащая путь к каталогу, в котором осуществляется поиск файлов.
	std::string searchPath;

	// Метод, осуществляющий составление списка.
	void makeList(std::string Path, std::vector<std::string> &fileList);

public:
	// Конструктор.
	// @param Path - сторка, содержащая путь к корневому каталогу, из которого будет составлен список.
	AllAudioFilesList(std::string Path) { searchPath = Path; }

	// Деструктор.
	~AllAudioFilesList() { AllAudioFileList.clear(); searchPath.clear(); }

	// Метод создает и возвращает список путей ко всем файлам с расширениями mp3, wav, flac, ogg, m4a и wma
	// в каталоге и всех подкаталогах.
	std::vector<std::string> getAllMp3FileList();
};

// Класс, переопределяющий виртуальный метод исключения what() для корректной обработки возможного исключения
// в ходе исполнения метода makeList класса AllAudioFiles.
class InvalidInputPathException : public std::exception
{
	// Переопределение виртуального метода what().
	virtual const char* what() const throw() { return "Invalid path! Make sure that the current folder is exist."; }
};


