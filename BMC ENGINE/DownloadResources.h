#pragma once
#include <Windows.h>
#include "curl/curl.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "zip/zip.h"

class DownloadResources
{
public:
	static void download();
private:
	static std::vector<std::string> splitString(std::string str);
};
