#include "FileManagement.h"

string FileManager::ReadFile(const char* path)
{
	string text;
	ifstream readFile(path);

	while (getline(readFile, text)) {
		cout << text;
	}

	readFile.close();

	return text;
}

void FileManager::WriteFile(const char* path, const char* text)
{
}
