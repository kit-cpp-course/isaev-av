#define _CRT_SECURE_NO_WARNINGS
#define ID3_MAX_SIZE 128

#include "InfoFromAudio.h"

InfoFromAudioFactory * InfoFromAudioFactory::createObjInfoFromAudio()
{
	InfoFromAudioFactory * p;
	p = new InfoFromAudio();

	return p;
}

long InfoFromAudio::idv3FileOffset(FILE* audioFile)
{
	fseek(audioFile, 0L, SEEK_END);
	return ftell(audioFile) - ID3_MAX_SIZE;
}

Metadata InfoFromAudio::getInfo(std::string strFileName)
{
	if ((audioFl = fopen(strFileName.c_str(), "r")) == NULL)
	{
		CantOpenAudioFileForReadingException cantOpenForReadingExc;
		throw cantOpenForReadingExc;
	}

	buffer = new char[ID3_MAX_SIZE];
	memset((void*)buffer, 0x00, ID3_MAX_SIZE);

	fseek(audioFl, idv3FileOffset(audioFl), SEEK_SET);
	fread(buffer, 1, ID3_MAX_SIZE, audioFl);

	if ((audioFileObj = reinterpret_cast<Metadata*>(buffer)) == NULL)
	{
		CantCastInfoException cantCastInfoExc;
		throw cantCastInfoExc;
	}

	fclose(audioFl);

	return *audioFileObj;
}
