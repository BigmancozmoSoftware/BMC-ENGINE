#include "DownloadResources.h"

void DownloadResources::download()
{
	wchar_t path[1024];

	cout << "Checking if resources exist..." << endl;

	GetModuleFileName(NULL, path, 1024);

	wstring ws(path);
	string path_string(ws.begin(), ws.end());
	string dir_string = path_string;
	vector<string> split = splitString(dir_string);

	cout << "EXE path is " << path_string << endl;
	cout << "EXE directory is " << dir_string << endl << endl;
	cout << "Downloading resources..." << endl;

	const char* res_zip_url = "https://183a102d-add9-4b1e-8bff-30e434d3a98b-00-l26a1tv83v43.janeway.replit.dev/resources.zip";
	CURL* curl;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, res_zip_url);

	cout << endl;
}

vector<string> DownloadResources::splitString(string str)
{
	vector<string> strings;
	istringstream f(str);
	string s;
	while (getline(f, s, '\\')) {
		cout << s << endl;
		strings.push_back(s);
	}
	return strings;
}
