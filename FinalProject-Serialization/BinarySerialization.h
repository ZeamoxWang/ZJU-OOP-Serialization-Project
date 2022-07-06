#pragma once
#include "XMLSerialization.h"
#include <cstdio>

namespace BinarySerialization{

	// This function could encode the tmpfile to base64 document;
	void encodeTmpFile2File(const std::string& path);
	// This function could decode the base64 document to a tempfile;
	void decodeFile2TmpFile(const std::string& path);

	template <typename T>
	void serialize(const T& object, const std::string& path) {
		XMLSerialization::serialize_xml(object, "binary", path + "tmp");
		// binary-to-text encoding, it will generate a file named path;
		encodeTmpFile2File(path);
		remove((path + "tmp").c_str());
	}

	template <typename T>
	void deserialize(T& object, const std::string& path) {
		// text-to-binary decoding, it will generate a file named path+"tmp";
		decodeFile2TmpFile(path);
		XMLSerialization::deserialize_xml(object, "binary", path + "tmp");
		remove((path + "tmp").c_str());
	}
};

