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

static void* _lzmaAlloc(ISzAllocPtr, size_t size) {
	return new uint8_t[size];
}
static void _lzmaFree(ISzAllocPtr, void* addr) {
	if (!addr)
		return;

	delete[] reinterpret_cast<uint8_t*>(addr);
}

static ISzAlloc _allocFuncs = {
	_lzmaAlloc, _lzmaFree
};

std::unique_ptr<uint8_t[]> lzmaDecompress(const uint8_t* input, uint32_t inputSize, uint32_t* outputSize) {
	if (inputSize < 13)
		return NULL; // invalid header!

	// extract the size from the header
	UInt64 size = 0;
	for (int i = 0; i < 8; i++)
		size |= (input[5 + i] << (i * 8));

	if (size <= (256 * 1024 * 1024)) {
		auto blob = std::make_unique<uint8_t[]>(size);

		ELzmaStatus lzmaStatus;
		SizeT procOutSize = size, procInSize = inputSize - 13;
		int status = LzmaDecode(blob.get(), &procOutSize, &input[13], &procInSize, input, 5, LZMA_FINISH_END, &lzmaStatus, &_allocFuncs);

		if (status == SZ_OK && procOutSize == size) {
			*outputSize = size;
			return blob;
		}
	}

	return NULL;
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

	//fclose(fp);

	//curl_easy_cleanup(curl);
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
