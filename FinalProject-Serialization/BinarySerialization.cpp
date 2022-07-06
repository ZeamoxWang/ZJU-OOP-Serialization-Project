#include "BinarySerialization.h"

namespace BinarySerialization {

	const char* base64char = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	const int base64int[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							  0, 0, 0,62, 0, 0, 0,63,52,53,
							 54,55,56,57,58,59,60,61, 0, 0,
							  0, 0, 0, 0, 0, 0, 1, 2, 3, 4,
							  5, 6, 7, 8, 9,10,11,12,13,14,
							 15,16,17,18,19,20,21,22,23,24,
							 25, 0, 0, 0, 0, 0, 0,26,27,28,
							 29,30,31,32,33,34,35,36,37,38,
							 39,40,41,42,43,44,45,46,47,48,
							 49,50,51 };

	void encodeTmpFile2File(const std::string& path)
	{
		FILE* fp, *newfp;
		fopen_s(&fp, (path + "tmp").c_str(), "r");
		fopen_s(&newfp, path.c_str(), "wb");
		std::vector<char> Three2Four;
		char tmp;
		while (!feof(fp)){
			if (Three2Four.size() < 3) {
				tmp = fgetc(fp);
				if (tmp == -1) {
					break;
				}
				Three2Four.push_back(tmp);
			}
			else {
				fputc(base64char[Three2Four[0] >> 2], newfp);
				fputc(base64char[((Three2Four[0] << 4) & 0x3F) + (Three2Four[1] >> 4)], newfp);
				fputc(base64char[((Three2Four[1] << 2) & 0x3F) + (Three2Four[2] >> 6)], newfp);
				fputc(base64char[Three2Four[2] & 0x3F], newfp);
				Three2Four.clear();
			}
		}

		switch (Three2Four.size()) {
		case 0:
			break;
		case 1:
			fputc(base64char[Three2Four[0] >> 2], newfp);
			fputc(base64char[(Three2Four[0] << 4) & 0x3F], newfp);
			fputc('=', newfp);
			fputc('=', newfp);
			break;
		case 2:
			fputc(base64char[Three2Four[0] >> 2], newfp);
			fputc(base64char[((Three2Four[0] << 4) & 0x3F) + (Three2Four[1] >> 4)], newfp);
			fputc(base64char[(Three2Four[1] << 2) & 0x3F], newfp);
			fputc('=', newfp);
			break;

		}
		fclose(fp);
		fclose(newfp);
	}

	void decodeFile2TmpFile(const std::string& path) {
		FILE* fp, * newfp;
		fopen_s(&newfp, (path + "tmp").c_str(), "wb");
		fopen_s(&fp, path.c_str(), "r");
		std::vector<int> Four2Three;
		char tmp;
		while (!feof(fp)) {
			if (Four2Three.size() < 4) {
				tmp = fgetc(fp);
				if (tmp == '=' || tmp == -1) {
					break;
				}
				else {
					Four2Three.push_back(base64int[tmp]);
				}
			}
			else {
				fputc((Four2Three[0] << 2) + (Four2Three[1] >> 4), newfp);
				fputc((Four2Three[1] << 4) + (Four2Three[2] >> 2), newfp);
				fputc((Four2Three[2] << 6) + Four2Three[3], newfp);
				Four2Three.clear();
			}
		}
		switch (Four2Three.size()) {
		case 0:
			break;
		case 1:
			std::cout << "ERROR!" << std::endl;
			break;
		case 2:
			fputc((Four2Three[0] << 2) + (Four2Three[1] >> 4), newfp);
			break;
		case 3:
			fputc((Four2Three[0] << 2) + (Four2Three[1] >> 4), newfp);
			fputc((Four2Three[1] << 4) + (Four2Three[2] >> 2), newfp);
			break;
		}
		fclose(fp);
		fclose(newfp);
	}
};