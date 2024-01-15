#include "DownloadResources.h"

void DownloadResources::download()
{
	wchar_t dir[1024];

	cout << "Checking if resources exist..." << endl;

	GetModuleFileName(NULL, dir, 1024);

	wstring ws(dir);
	string dir_string(ws.begin(), ws.end());

	cout << "EXE dir is " << dir_string << endl;
	cout << "Downloading resources..." << endl;

	curl_easy_init();

	cout << endl;
}
