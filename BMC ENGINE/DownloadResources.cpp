#include "DownloadResources.h"

void join(const std::vector<std::string>& v, char c, std::string& s) {

	s.clear();

	for (std::vector<std::string>::const_iterator p = v.begin();
		p != v.end(); ++p) {
		s += *p;
		if (p != v.end() - 1)
			s += c;
	}
}

void DownloadResources::download()
{
	wchar_t path[1024];

	std::cout << "Checking if resources exist..." << std::endl;

	GetModuleFileName(NULL, path, 1024);

	std::wstring ws(path);
	std::string path_string(ws.begin(), ws.end());
	std::vector<std::string> split_path = splitString(path_string);
	std::string dir_string;

	split_path.pop_back();
	join(split_path, '\\', dir_string);

	// big print lots info
	std::cout << std::endl << "EXE path is " << path_string << std::endl << "EXE directory is " << dir_string << std::endl << std::endl << "Downloading resources..." << std::endl;

	const wchar_t* res_zip_url = L"https://183a102d-add9-4b1e-8bff-30e434d3a98b-00-l26a1tv83v43.janeway.replit.dev/resources.zip";
	std::wstring w_dir_string = std::wstring(dir_string.begin(), dir_string.end()) + L"\\resources.zip";
	const wchar_t* d_str = w_dir_string.c_str();
	URLDownloadToFile(NULL, res_zip_url, d_str, 0, NULL);

	std::cout << "Finished downloading!" << std::endl << "Extracting...";
	std::cout << std::endl;
}

std::vector<std::string> DownloadResources::splitString(std::string str)
{
	std::vector<std::string> strings;
	std::istringstream f(str);
	std::string s;
	while (std::getline(f, s, '\\')) {
		strings.push_back(s);
	}
	return strings;
}
