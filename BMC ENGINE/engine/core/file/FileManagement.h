#pragma once
#include <iostream>
#include <fstream>

class FileManager
{
public:
	const char* ReadFile(const char* path);
	void WriteFile(const char* path, const char* text);
};