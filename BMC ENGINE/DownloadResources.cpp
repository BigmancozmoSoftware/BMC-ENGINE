#include "DownloadResources.h"

void join(const vector<string>& v, char c, string& s) {

	s.clear();

	for (vector<string>::const_iterator p = v.begin();
		p != v.end(); ++p) {
		s += *p;
		if (p != v.end() - 1)
			s += c;
	}
}

void DownloadResources::download()
{
	wchar_t path[1024];

	cout << "Checking if resources exist..." << endl;

	GetModuleFileName(NULL, path, 1024);

	wstring ws(path);
	string path_string(ws.begin(), ws.end());
	vector<string> split_path = splitString(path_string);
	string dir_string;

	split_path.pop_back();
	join(split_path, '\\', dir_string);

	// big print lots info
	cout << endl << "EXE path is " << path_string << endl << "EXE directory is " << dir_string << endl << endl << "Downloading resources..." << endl;

	const wchar_t* res_zip_url = L"https://183a102d-add9-4b1e-8bff-30e434d3a98b-00-l26a1tv83v43.janeway.replit.dev/resources.zip";
	wstring w_dir_string = std::wstring(dir_string.begin(), dir_string.end()) + L"\\resources.zip";
	const wchar_t* d_str = w_dir_string.c_str();
	URLDownloadToFile(NULL, res_zip_url, d_str, 0, NULL);

	cout << "Finished downloading!" << endl << "Extracting...";
	cout << endl;
}

vector<string> DownloadResources::splitString(string str)
{
	vector<string> strings;
	istringstream f(str);
	string s;
	while (getline(f, s, '\\')) {
		strings.push_back(s);
	}
	return strings;
}
