#pragma once

struct Metadata
{
	char signature[3];
	char name[30];
	char artist[30];
	char album[30];
	char year[4];
	char description[30];
	unsigned short ganre;
};
