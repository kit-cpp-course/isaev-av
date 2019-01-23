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

	// Возращает метаданные аудио файла в виде описывающего их объекта структуры Metadata.
	virtual Metadata getInfo(std::string strFileName) {}

	// Создает объект класса InfoFromAudio и возвращает ссылку на него.
	static InfoFromAudioFactory * createObjInfoFromAudio();
};

//Класс, отвечающий за считывание метаданных из аудио файла.
class InfoFromAudio : public InfoFromAudioFactory
{
	// Указатель на файловый объект.
	FILE * audioFl = NULL;

	// Указатель на адрес памяти, содержащей метаданные аудио файла.
	Metadata * audioFileObj = NULL;

	// Буфер для хранения метаданных в их первичном виде. 
	char * buffer;

	// Возвращает байт файла, начиная с котрого в файле могут содержаться метаданные.  
	// @param audioFile - указатель на оперируемый файл.
	long idv3FileOffset(FILE * audioFile);

public:

	// Деструктор.
	~InfoFromAudio();

	// Возращает метаданные аудио файла в виде описывающего их объекта структуры Metadata.
	Metadata getInfo(std::string strFileName);
};

// Класс, переопределяющий виртуальный метод исключения what() для корректной обработки возможного исключения
// в ходе попытки открыть файл для чтения.
class CantOpenAudioFileForReadingException : public std::exception
{
	virtual const char* what() const throw() { return "Can not open audio file for reading!"; }
};

// Класс, переопределяющий виртуальный метод исключения what() для корректной обработки возможного исключения
// в ходе попытки приведения полученных данных типа char* к типу Metadata.
class CantCastInfoException : public std::exception
{
	virtual const char* what() const throw() { return "Can not cast info in struct type <<AudioFile>>!"; }
};

