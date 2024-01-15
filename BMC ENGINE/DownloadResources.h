#pragma once
#include "curl/curl.h"
#include <iostream>
#include <Windows.h>
#include <filesystem>
#include <sstream>
#include <vector>

using namespace std;

class DownloadResources
{
public:
	static void download();
private:
	void splitString();
};
