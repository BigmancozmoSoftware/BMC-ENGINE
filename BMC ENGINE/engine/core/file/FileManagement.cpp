#include "FileManagement.h"

std::string FileManager::ReadFile(const char* path)
{
	std::cout << ((std::string)"Reading file " + (std::string)path) << std::endl;

	std::string currentLine;
	std::string text = "";
	std::ifstream readFile(path);

	while (std::getline(readFile, currentLine)) {
		text = text + currentLine + "\n";
	}

	readFile.close();

	return text;
}

void FileManager::WriteFile(const char* path, const char* text)
{
	// TODO
}
