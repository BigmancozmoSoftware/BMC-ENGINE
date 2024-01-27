#pragma once
#include "curl/curl.h"
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "elzip/elzip.hpp"

class DownloadResources
{
public:
	static void download();
private:
	static std::vector<std::string> splitString(std::string str);
};
