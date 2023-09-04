#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager
{
public:
	string ReadFile(const char* path);
	void WriteFile(const char* path, const char* text);
};