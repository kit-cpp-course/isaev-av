#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <direct.h>
#include <cstdio>
#include "InfoFromAudio.h"
#include <errno.h>

// Структура, описывающая буфер метаданных одного файла в виде строк типа string для упрощения работы класса CatalogAudioFiles.
struct BufferForMetadata
{
	// Буфер пути к определенному файлу.
	std::string bufferPath;

	// Буфер исполнителя.
	std::string bufferArtist;

	// Буфер альбома.
	std::string bufferAlbum;

	// Буфер имени файла.
	std::string bufferFileName;

	// Буфер подписи (главного тега) файла.
	std::string bufferSingnature;

};


// Класс, отвечающий за составление аудио файлам в списке пути к их новому расположению
// в соответсвии с их метаданными и за их перемещение по этим адресам.
class CatalogAudioToNewDir
{
	// Строка, хранящая путь к новому корневому каталогу аудио файлов, который будет создан.
	std::string newDirPath;

	// Вектор, хранящий список путей к аудио файлам, которые будут обрабатываться классом.
	std::vector<std::string> audioFilesPathList;

	// Указатель на экземпляр класса, отвечающий за считывание метаданных из аудио файлов.
	InfoFromAudioFactory * metadataGetter;

	// Экземпляр структуры, хранящий метаданные файла в виде строго заданных массивов типа char.
	Metadata metadata;

	// Экземпляр структуры, описывающий буфер для метаданных и хранящий метаданные файла в виде строк типа string.
	BufferForMetadata buffer;

	// Метод совершает попытку создать новый корневой каталог для аудио файлов.
	// В случае успеха или если такой каталог уже существует, возвращает true.
	// В случае ошибки при создании возращает false.
	bool createCoreDirectory();

	// Составляет новый путь к файлу на основе его метаданных.
	// @param filePath - прежний путь к файлу.
	const char * createCalalogPath(std::string filePath);

	// Заполняет буфер метаданных новыми значениями на основе данных из поля metadata.
	void prepareBuffer();

	// Очищает от данных все поля буфера.
	void clearBuffer();

public:
	// Конструктор.
	// @param path - путь к новому корневому каталогу аудио файлов, который будет создан.
	// @param list - вектор, представляющий собой список путей к аудио файлам, которые будут обрабатываться классом.
	CatalogAudioToNewDir(std::string path, std::vector<std::string> list) { newDirPath = path; audioFilesPathList = list; }

	// Перемещение аудио файлов, полученных классом, по новому адресу и их каталогизация.
	void MoveAndCatalogFiles();
};

// Класс, переопределяющий виртуальный метод исключения what() для корректной обработки возможного исключения
// в ходе попытки создания объектом класса CatalogAudioToNewDir нового корневого каталога.
class CantCreateDirectoryException : public std::exception
{
	virtual const char* what() const throw() { return "Can not create new directory! Сheck the entered path."; }
};

