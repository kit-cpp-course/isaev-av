#include "CatalogAudioToNewDir.h"

void CatalogAudioToNewDir::MoveAndCatalogFiles()
{
	if (!(createCoreDirectory()))
	{
		CantCreateDirectoryException cantCreateDirectoryException;
		throw cantCreateDirectoryException;
	}

	for (int i = 0; i < audioFilesPathList.size(); i++)
	{
		if (std::rename(audioFilesPathList.at(i).c_str(), createCalalogPath(audioFilesPathList.at(i))) < 0)
			std::cout << "Problem occured while moving #" << i << " file!\n\n";
	}
}

bool CatalogAudioToNewDir::createCoreDirectory()
{
	int check = _mkdir(newDirPath.c_str());

	if (check != 0 && errno != EEXIST) return false;
	else return true;
}

const char * CatalogAudioToNewDir::createCalalogPath(std::string filePath)
{
	metadata = metadataGetter.getInfo(filePath);

	prepareBuffer();
	buffer.bufferPath.append("\\" + buffer.bufferArtist);

	int check = _mkdir(buffer.bufferPath.c_str()); // Попытка создания папки артиста
	if (errno == ENOENT)
	{
		std::cout << "Problem creating " << buffer.bufferArtist << " directory! Path not found!\n";
		return NULL;
	}
	else if (check != 0 && errno != EEXIST)
	{
		std::cout << "Unknown problem creating " << buffer.bufferArtist << " directory!\n";
		return NULL;
	}

	if (buffer.bufferAlbum != "")
	{
		buffer.bufferPath.append("\\" + buffer.bufferAlbum);
		check = _mkdir(buffer.bufferPath.c_str());
		if (errno == ENOENT)
		{
			std::cout << "Problem creating " << buffer.bufferArtist << "- " << buffer.bufferAlbum << " directory! Path not found!\n";
			return NULL;
		}
		else if (check != 0 && errno != EEXIST)
		{
			std::cout << "Unknown problem creating " << buffer.bufferArtist << "- " << buffer.bufferAlbum << " directory!\n";
			return NULL;
		}
	}

	buffer.bufferFileName.append(filePath, filePath.rfind("\\") + 1, filePath.size() - 1);
	buffer.bufferPath += ("\\" + buffer.bufferFileName);

	return buffer.bufferPath.c_str();
}

void CatalogAudioToNewDir::prepareBuffer()
{
	clearBuffer();

	buffer.bufferPath = newDirPath;

	buffer.bufferSingnature.append(metadata.signature); // Проверить, чтоб первые три знака были TAG
	if (buffer.bufferSingnature.find("TAG") != 0)
	{
		buffer.bufferArtist = "Unknown Artists";
		buffer.bufferAlbum = "";
		return;
	}

	buffer.bufferArtist.append(metadata.artist);
	if (buffer.bufferArtist.find("  ") != std::string::npos) buffer.bufferArtist.erase(buffer.bufferArtist.find("  "));
	if (buffer.bufferArtist == "") buffer.bufferArtist = "Unknown Artists";

	buffer.bufferAlbum.append(metadata.album);
	if (buffer.bufferAlbum.find("  ") != std::string::npos) buffer.bufferAlbum.erase(buffer.bufferAlbum.find("  "));
}

void CatalogAudioToNewDir::clearBuffer()
{
	buffer.bufferFileName.clear();
	buffer.bufferAlbum.clear();
	buffer.bufferArtist.clear();
	buffer.bufferPath.clear();
	buffer.bufferSingnature.clear();
}