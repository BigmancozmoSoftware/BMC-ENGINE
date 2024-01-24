#pragma once
#include "curl/curl.h"
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "LZMA/LzmaDec.h"

using namespace std;

class DownloadResources
{
public:
	static void download();
private:
	static vector<string> splitString(string str);
};
