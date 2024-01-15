#pragma once
#include "curl/curl.h"
#include <iostream>
#include <Windows.h>
#include <filesystem>

using namespace std;

class DownloadResources
{
public:
	static void download();
};
