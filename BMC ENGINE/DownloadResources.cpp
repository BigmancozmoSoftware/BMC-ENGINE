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

	const char* res_zip_url = "https://183a102d-add9-4b1e-8bff-30e434d3a98b-00-l26a1tv83v43.janeway.replit.dev/resources.zip";
	CURL* curl;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, res_zip_url);

	cout << endl;
}

void DownloadResources::splitString()
{
	vector<string> strings;
	istringstream f("denmark;sweden;india;us");
	string s;
	while (getline(f, s, ';')) {
		cout << s << endl;
		strings.push_back(s);
	}
}
