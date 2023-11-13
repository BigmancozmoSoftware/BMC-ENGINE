#include "FileManagement.h"

string FileManager::ReadFile(const char* path)
{
	std::cout << ((string)"Reading file " + (string)path) << endl;

	string currentLine;
	string text = "";
	ifstream readFile(path);

	while (getline(readFile, currentLine)) {
		text = text + currentLine + "\n";
	}

	readFile.close();

	return text;
}

void FileManager::WriteFile(const char* path, const char* text)
{
	// TODO
}
