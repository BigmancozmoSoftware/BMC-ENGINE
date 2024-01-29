#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileManager
{
public:
	std::string ReadFile(const char* path);
	void WriteFile(const char* path, const char* text);
};