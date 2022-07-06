#pragma once
#include "Object.h"

// This macro function could write data from memory to file with the ... typename;
#define IF_FRAGMENT_MEM2FILE(...)						\
			if (object.types[i] == #__VA_ARGS__) {		\
				__VA_ARGS__* tmp = new __VA_ARGS__();	\
				(object.*funcp)((void*)tmp);			\
				memory2file(*tmp, "member", obj, doc);	\
				delete tmp;								\
				continue;								\
			}											\

// This macro function could read data from file to memory with the ... typename;
#define IF_FRAGMENT_FILE2MEM(...)						\
			if (object.types[i] == #__VA_ARGS__) {		\
				__VA_ARGS__* tmp = new __VA_ARGS__();	\
				file2memory(*tmp, obj);					\
				(object.*funcp)((void*)tmp);			\
				delete tmp;								\
				continue;								\
			}											\

namespace XMLSerialization {

	using namespace tinyxml2;

	void memory2file(const std::string& object, const std::string& type, XMLElement* root, XMLDocument& doc);

	template <typename T1, typename T2>
	void memory2file(const std::pair<T1, T2>& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* pair = doc.NewElement(type.c_str());
		memory2file(object.first, "first", pair, doc);
		memory2file(object.second, "second", pair, doc);
		root->InsertEndChild(pair);
	}

	template <typename T>
	void memory2file(const std::vector<T>& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* vector = doc.NewElement(type.c_str());
		for (int i = 0; i < object.size(); i++) {
			memory2file(object[i], "element", vector, doc);
		}
		root->InsertEndChild(vector);
	}

	template <typename T>
	void memory2file(const std::list<T>& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* list = doc.NewElement(type.c_str());
		for (std::list<T>::const_iterator it = object.begin(); it != object.end(); it++) {
			memory2file(*it, "element", list, doc);
		}
		root->InsertEndChild(list);
	}

	template <typename T>
	void memory2file(const std::set<T>& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* set = doc.NewElement(type.c_str());
		for (std::set<T>::const_iterator it = object.begin(); it != object.end(); it++) {
			memory2file(*it, "element", set, doc);
		}
		root->InsertEndChild(set);
	}

	template <typename T1, typename T2>
	void memory2file(const std::map<T1, T2>& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* map = doc.NewElement(type.c_str());
		for (std::map<T1, T2>::const_iterator it = object.begin(); it != object.end(); it++) {
			memory2file(it->first, "key", map, doc);
			memory2file(it->second, "value", map, doc);
		}
		root->InsertEndChild(map);
	}

	// This function receive any object type including user defined type;
	template <typename T>
	void memory2file(const T& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		void (T:: * funcp)(void*) const;
		// The macro functions are ugly, but useful!
		for (int i = 0; i < object.types.size(); i++) {
			funcp = object.getFunc[i];

			IF_FRAGMENT_MEM2FILE(int);
			IF_FRAGMENT_MEM2FILE(bool);
			IF_FRAGMENT_MEM2FILE(char);
			IF_FRAGMENT_MEM2FILE(long long);
			IF_FRAGMENT_MEM2FILE(double);
			IF_FRAGMENT_MEM2FILE(float);
			IF_FRAGMENT_MEM2FILE(std::string);

			IF_FRAGMENT_MEM2FILE(std::vector<int>);
			IF_FRAGMENT_MEM2FILE(std::vector<bool>);
			IF_FRAGMENT_MEM2FILE(std::vector<char>);
			IF_FRAGMENT_MEM2FILE(std::vector<long long>);
			IF_FRAGMENT_MEM2FILE(std::vector<double>);
			IF_FRAGMENT_MEM2FILE(std::vector<float>);
			IF_FRAGMENT_MEM2FILE(std::vector<std::string>);

			IF_FRAGMENT_MEM2FILE(std::set<int>);
			IF_FRAGMENT_MEM2FILE(std::set<bool>);
			IF_FRAGMENT_MEM2FILE(std::set<char>);
			IF_FRAGMENT_MEM2FILE(std::set<long long>);
			IF_FRAGMENT_MEM2FILE(std::set<double>);
			IF_FRAGMENT_MEM2FILE(std::set<float>);
			IF_FRAGMENT_MEM2FILE(std::set<std::string>);

			IF_FRAGMENT_MEM2FILE(std::list<int>);
			IF_FRAGMENT_MEM2FILE(std::list<bool>);
			IF_FRAGMENT_MEM2FILE(std::list<char>);
			IF_FRAGMENT_MEM2FILE(std::list<long long>);
			IF_FRAGMENT_MEM2FILE(std::list<double>);
			IF_FRAGMENT_MEM2FILE(std::list<float>);
			IF_FRAGMENT_MEM2FILE(std::list<std::string>);

			IF_FRAGMENT_MEM2FILE(std::map<int, int>);
			IF_FRAGMENT_MEM2FILE(std::map<int, bool>);
			IF_FRAGMENT_MEM2FILE(std::map<int, char>);
			IF_FRAGMENT_MEM2FILE(std::map<int, long long>);
			IF_FRAGMENT_MEM2FILE(std::map<int, double>);
			IF_FRAGMENT_MEM2FILE(std::map<int, float>);
			IF_FRAGMENT_MEM2FILE(std::map<int, std::string>);

			IF_FRAGMENT_MEM2FILE(std::map<bool, int>);
			IF_FRAGMENT_MEM2FILE(std::map<bool, bool>);
			IF_FRAGMENT_MEM2FILE(std::map<bool, char>);
			IF_FRAGMENT_MEM2FILE(std::map<bool, long long>);
			IF_FRAGMENT_MEM2FILE(std::map<bool, double>);
			IF_FRAGMENT_MEM2FILE(std::map<bool, float>);
			IF_FRAGMENT_MEM2FILE(std::map<bool, std::string>);

			IF_FRAGMENT_MEM2FILE(std::map<char, int>);
			IF_FRAGMENT_MEM2FILE(std::map<char, bool>);
			IF_FRAGMENT_MEM2FILE(std::map<char, char>);
			IF_FRAGMENT_MEM2FILE(std::map<char, long long>);
			IF_FRAGMENT_MEM2FILE(std::map<char, double>);
			IF_FRAGMENT_MEM2FILE(std::map<char, float>);
			IF_FRAGMENT_MEM2FILE(std::map<char, std::string>);

			IF_FRAGMENT_MEM2FILE(std::map<long long, int>);
			IF_FRAGMENT_MEM2FILE(std::map<long long, bool>);
			IF_FRAGMENT_MEM2FILE(std::map<long long, char>);
			IF_FRAGMENT_MEM2FILE(std::map<long long, long long>);
			IF_FRAGMENT_MEM2FILE(std::map<long long, double>);
			IF_FRAGMENT_MEM2FILE(std::map<long long, float>);
			IF_FRAGMENT_MEM2FILE(std::map<long long, std::string>);

			IF_FRAGMENT_MEM2FILE(std::map<double, int>);
			IF_FRAGMENT_MEM2FILE(std::map<double, bool>);
			IF_FRAGMENT_MEM2FILE(std::map<double, char>);
			IF_FRAGMENT_MEM2FILE(std::map<double, long long>);
			IF_FRAGMENT_MEM2FILE(std::map<double, double>);
			IF_FRAGMENT_MEM2FILE(std::map<double, float>);
			IF_FRAGMENT_MEM2FILE(std::map<double, std::string>);

			IF_FRAGMENT_MEM2FILE(std::map<float, int>);
			IF_FRAGMENT_MEM2FILE(std::map<float, bool>);
			IF_FRAGMENT_MEM2FILE(std::map<float, char>);
			IF_FRAGMENT_MEM2FILE(std::map<float, long long>);
			IF_FRAGMENT_MEM2FILE(std::map<float, double>);
			IF_FRAGMENT_MEM2FILE(std::map<float, float>);
			IF_FRAGMENT_MEM2FILE(std::map<float, std::string>);

			IF_FRAGMENT_MEM2FILE(std::map<std::string, int>);
			IF_FRAGMENT_MEM2FILE(std::map<std::string, bool>);
			IF_FRAGMENT_MEM2FILE(std::map<std::string, char>);
			IF_FRAGMENT_MEM2FILE(std::map<std::string, long long>);
			IF_FRAGMENT_MEM2FILE(std::map<std::string, double>);
			IF_FRAGMENT_MEM2FILE(std::map<std::string, float>);
			IF_FRAGMENT_MEM2FILE(std::map<std::string, std::string>);

			IF_FRAGMENT_MEM2FILE(std::pair<int, int>);
			IF_FRAGMENT_MEM2FILE(std::pair<int, bool>);
			IF_FRAGMENT_MEM2FILE(std::pair<int, char>);
			IF_FRAGMENT_MEM2FILE(std::pair<int, long long>);
			IF_FRAGMENT_MEM2FILE(std::pair<int, double>);
			IF_FRAGMENT_MEM2FILE(std::pair<int, float>);
			IF_FRAGMENT_MEM2FILE(std::pair<int, std::string>);

			IF_FRAGMENT_MEM2FILE(std::pair<bool, int>);
			IF_FRAGMENT_MEM2FILE(std::pair<bool, bool>);
			IF_FRAGMENT_MEM2FILE(std::pair<bool, char>);
			IF_FRAGMENT_MEM2FILE(std::pair<bool, long long>);
			IF_FRAGMENT_MEM2FILE(std::pair<bool, double>);
			IF_FRAGMENT_MEM2FILE(std::pair<bool, float>);
			IF_FRAGMENT_MEM2FILE(std::pair<bool, std::string>);

			IF_FRAGMENT_MEM2FILE(std::pair<char, int>);
			IF_FRAGMENT_MEM2FILE(std::pair<char, bool>);
			IF_FRAGMENT_MEM2FILE(std::pair<char, char>);
			IF_FRAGMENT_MEM2FILE(std::pair<char, long long>);
			IF_FRAGMENT_MEM2FILE(std::pair<char, double>);
			IF_FRAGMENT_MEM2FILE(std::pair<char, float>);
			IF_FRAGMENT_MEM2FILE(std::pair<char, std::string>);

			IF_FRAGMENT_MEM2FILE(std::pair<long long, int>);
			IF_FRAGMENT_MEM2FILE(std::pair<long long, bool>);
			IF_FRAGMENT_MEM2FILE(std::pair<long long, char>);
			IF_FRAGMENT_MEM2FILE(std::pair<long long, long long>);
			IF_FRAGMENT_MEM2FILE(std::pair<long long, double>);
			IF_FRAGMENT_MEM2FILE(std::pair<long long, float>);
			IF_FRAGMENT_MEM2FILE(std::pair<long long, std::string>);

			IF_FRAGMENT_MEM2FILE(std::pair<double, int>);
			IF_FRAGMENT_MEM2FILE(std::pair<double, bool>);
			IF_FRAGMENT_MEM2FILE(std::pair<double, char>);
			IF_FRAGMENT_MEM2FILE(std::pair<double, long long>);
			IF_FRAGMENT_MEM2FILE(std::pair<double, double>);
			IF_FRAGMENT_MEM2FILE(std::pair<double, float>);
			IF_FRAGMENT_MEM2FILE(std::pair<double, std::string>);

			IF_FRAGMENT_MEM2FILE(std::pair<float, int>);
			IF_FRAGMENT_MEM2FILE(std::pair<float, bool>);
			IF_FRAGMENT_MEM2FILE(std::pair<float, char>);
			IF_FRAGMENT_MEM2FILE(std::pair<float, long long>);
			IF_FRAGMENT_MEM2FILE(std::pair<float, double>);
			IF_FRAGMENT_MEM2FILE(std::pair<float, float>);
			IF_FRAGMENT_MEM2FILE(std::pair<float, std::string>);

			IF_FRAGMENT_MEM2FILE(std::pair<std::string, int>);
			IF_FRAGMENT_MEM2FILE(std::pair<std::string, bool>);
			IF_FRAGMENT_MEM2FILE(std::pair<std::string, char>);
			IF_FRAGMENT_MEM2FILE(std::pair<std::string, long long>);
			IF_FRAGMENT_MEM2FILE(std::pair<std::string, double>);
			IF_FRAGMENT_MEM2FILE(std::pair<std::string, float>);
			IF_FRAGMENT_MEM2FILE(std::pair<std::string, std::string>);

		}
		root->InsertEndChild(obj);
	}

	// This group of functions can load object from memory;
	template <>
	void memory2file<int>(const int& object, const std::string& type, XMLElement* root, XMLDocument& doc);

	template <>
	void memory2file<double>(const double& object, const std::string& type, XMLElement* root, XMLDocument& doc);

	template <>
	void memory2file<float>(const float& object, const std::string& type, XMLElement* root, XMLDocument& doc);

	template <>
	void memory2file<long long>(const long long& object, const std::string& type, XMLElement* root, XMLDocument& doc);

	template <>
	void memory2file<char>(const char& object, const std::string& type, XMLElement* root, XMLDocument& doc);

	template <>
	void memory2file<bool>(const bool& object, const std::string& type, XMLElement* root, XMLDocument& doc);

	// The template function doesn't allow me to use defalut parameter, so I use overload;
	void file2memory(int& object, XMLElement* root, const std::string& type = "");

	void file2memory(float& object, XMLElement* root, const std::string& type = "");

	void file2memory(double& object, XMLElement* root, const std::string& type = "");

	void file2memory(long long& object, XMLElement* root, const std::string& type = "");

	void file2memory(bool& object, XMLElement* root, const std::string& type = "");

	void file2memory(char& object, XMLElement* root, const std::string& type = "");

	void file2memory(std::string& object, XMLElement* root, const std::string& type = "");

	template <typename T1, typename T2>
	void file2memory(std::pair<T1, T2>& object, XMLElement* root, const std::string& type = "")
	{
		XMLElement* p;
		if (type == "") {
			p = root;
		}
		else {
			p = root->FirstChildElement(type.c_str());
		}
		file2memory(object.first, p, "first");
		file2memory(object.second, p, "second");
	}

	template <typename T>
	void file2memory(std::vector<T>& object, XMLElement* root, const std::string& type = "")
	{
		XMLElement* p;
		if (type == "") {
			p = root;
		}
		else {
			p = root->FirstChildElement(type.c_str());
		}
		object.clear();
		int i = 0;
		for (XMLElement* current = p->FirstChildElement("element"); current; current = current->NextSiblingElement(), i++) {
			object.push_back(T());
			file2memory(object[i], current);
		}
	}
	// Using codes upside will return compile error confronted with the bool vector!
	// According to some reference, the bool vector is implemented and capsulated in a bitwise way,
	// so it cannot work properly. Then, I use this specific function to get avoid that.
	void file2memory(std::vector<bool>& object, XMLElement* root, const std::string& type = "");

	template <typename T>
	void file2memory(std::list<T>& object, XMLElement* root, const std::string& type = "")
	{
		XMLElement* p;
		if (type == "") {
			p = root;
		}
		else {
			p = root->FirstChildElement(type.c_str());
		}
		object.clear();
		int i = 0;
		for (XMLElement* current = p->FirstChildElement("element"); current; current = current->NextSiblingElement(), i++) {
			T tmp;
			file2memory(tmp, current);
			object.push_back(tmp);
		}
	}

	template <typename T>
	void file2memory(std::set<T>& object, XMLElement* root, const std::string& type = "")
	{
		XMLElement* p;
		if (type == "") {
			p = root;
		}
		else {
			p = root->FirstChildElement(type.c_str());
		}
		object.clear();
		int i = 0;
		for (XMLElement* current = p->FirstChildElement("element"); current; current = current->NextSiblingElement(), i++) {
			T tmp;
			file2memory(tmp, current);
			object.insert(tmp);
		}
	}

	template <typename T1, typename T2>
	void file2memory(std::map<T1, T2>& object, XMLElement* root, const std::string& type = "")
	{
		XMLElement* p;
		if (type == "") {
			p = root;
		}
		else {
			p = root->FirstChildElement(type.c_str());
		}
		object.clear();
		int i = 0;
		for (XMLElement* current = p->FirstChildElement(); current; current = current->NextSiblingElement()->NextSiblingElement(), i++) {
			T1 key; T2 value;
			file2memory(key, current);
			file2memory(value, current->NextSiblingElement());
			object[key] = value;
		}
	}

	template <typename T>
	void file2memory(T& object, XMLElement* root, const std::string& type = "")
	{
		XMLElement* obj = root->FirstChildElement(type.c_str())->FirstChildElement("member");
		void (T:: * funcp)(void*);
		// The macro functions are ugly, but useful!
		for (int i = 0; i < object.types.size(), obj; i++, obj = obj->NextSiblingElement()) {
			funcp = object.writeFunc[i];

			IF_FRAGMENT_FILE2MEM(int);
			IF_FRAGMENT_FILE2MEM(bool);
			IF_FRAGMENT_FILE2MEM(char);
			IF_FRAGMENT_FILE2MEM(long long);
			IF_FRAGMENT_FILE2MEM(double);
			IF_FRAGMENT_FILE2MEM(float);
			IF_FRAGMENT_FILE2MEM(std::string);

			IF_FRAGMENT_FILE2MEM(std::vector<int>);
			IF_FRAGMENT_FILE2MEM(std::vector<bool>);
			IF_FRAGMENT_FILE2MEM(std::vector<char>);
			IF_FRAGMENT_FILE2MEM(std::vector<long long>);
			IF_FRAGMENT_FILE2MEM(std::vector<double>);
			IF_FRAGMENT_FILE2MEM(std::vector<float>);
			IF_FRAGMENT_FILE2MEM(std::vector<std::string>);

			IF_FRAGMENT_FILE2MEM(std::set<int>);
			IF_FRAGMENT_FILE2MEM(std::set<bool>);
			IF_FRAGMENT_FILE2MEM(std::set<char>);
			IF_FRAGMENT_FILE2MEM(std::set<long long>);
			IF_FRAGMENT_FILE2MEM(std::set<double>);
			IF_FRAGMENT_FILE2MEM(std::set<float>);
			IF_FRAGMENT_FILE2MEM(std::set<std::string>);

			IF_FRAGMENT_FILE2MEM(std::list<int>);
			IF_FRAGMENT_FILE2MEM(std::list<bool>);
			IF_FRAGMENT_FILE2MEM(std::list<char>);
			IF_FRAGMENT_FILE2MEM(std::list<long long>);
			IF_FRAGMENT_FILE2MEM(std::list<double>);
			IF_FRAGMENT_FILE2MEM(std::list<float>);
			IF_FRAGMENT_FILE2MEM(std::list<std::string>);

			IF_FRAGMENT_FILE2MEM(std::map<int, int>);
			IF_FRAGMENT_FILE2MEM(std::map<int, bool>);
			IF_FRAGMENT_FILE2MEM(std::map<int, char>);
			IF_FRAGMENT_FILE2MEM(std::map<int, long long>);
			IF_FRAGMENT_FILE2MEM(std::map<int, double>);
			IF_FRAGMENT_FILE2MEM(std::map<int, float>);
			IF_FRAGMENT_FILE2MEM(std::map<int, std::string>);

			IF_FRAGMENT_FILE2MEM(std::map<bool, int>);
			IF_FRAGMENT_FILE2MEM(std::map<bool, bool>);
			IF_FRAGMENT_FILE2MEM(std::map<bool, char>);
			IF_FRAGMENT_FILE2MEM(std::map<bool, long long>);
			IF_FRAGMENT_FILE2MEM(std::map<bool, double>);
			IF_FRAGMENT_FILE2MEM(std::map<bool, float>);
			IF_FRAGMENT_FILE2MEM(std::map<bool, std::string>);

			IF_FRAGMENT_FILE2MEM(std::map<char, int>);
			IF_FRAGMENT_FILE2MEM(std::map<char, bool>);
			IF_FRAGMENT_FILE2MEM(std::map<char, char>);
			IF_FRAGMENT_FILE2MEM(std::map<char, long long>);
			IF_FRAGMENT_FILE2MEM(std::map<char, double>);
			IF_FRAGMENT_FILE2MEM(std::map<char, float>);
			IF_FRAGMENT_FILE2MEM(std::map<char, std::string>);

			IF_FRAGMENT_FILE2MEM(std::map<long long, int>);
			IF_FRAGMENT_FILE2MEM(std::map<long long, bool>);
			IF_FRAGMENT_FILE2MEM(std::map<long long, char>);
			IF_FRAGMENT_FILE2MEM(std::map<long long, long long>);
			IF_FRAGMENT_FILE2MEM(std::map<long long, double>);
			IF_FRAGMENT_FILE2MEM(std::map<long long, float>);
			IF_FRAGMENT_FILE2MEM(std::map<long long, std::string>);

			IF_FRAGMENT_FILE2MEM(std::map<double, int>);
			IF_FRAGMENT_FILE2MEM(std::map<double, bool>);
			IF_FRAGMENT_FILE2MEM(std::map<double, char>);
			IF_FRAGMENT_FILE2MEM(std::map<double, long long>);
			IF_FRAGMENT_FILE2MEM(std::map<double, double>);
			IF_FRAGMENT_FILE2MEM(std::map<double, float>);
			IF_FRAGMENT_FILE2MEM(std::map<double, std::string>);

			IF_FRAGMENT_FILE2MEM(std::map<float, int>);
			IF_FRAGMENT_FILE2MEM(std::map<float, bool>);
			IF_FRAGMENT_FILE2MEM(std::map<float, char>);
			IF_FRAGMENT_FILE2MEM(std::map<float, long long>);
			IF_FRAGMENT_FILE2MEM(std::map<float, double>);
			IF_FRAGMENT_FILE2MEM(std::map<float, float>);
			IF_FRAGMENT_FILE2MEM(std::map<float, std::string>);

			IF_FRAGMENT_FILE2MEM(std::map<std::string, int>);
			IF_FRAGMENT_FILE2MEM(std::map<std::string, bool>);
			IF_FRAGMENT_FILE2MEM(std::map<std::string, char>);
			IF_FRAGMENT_FILE2MEM(std::map<std::string, long long>);
			IF_FRAGMENT_FILE2MEM(std::map<std::string, double>);
			IF_FRAGMENT_FILE2MEM(std::map<std::string, float>);
			IF_FRAGMENT_FILE2MEM(std::map<std::string, std::string>);

			IF_FRAGMENT_FILE2MEM(std::pair<int, int>);
			IF_FRAGMENT_FILE2MEM(std::pair<int, bool>);
			IF_FRAGMENT_FILE2MEM(std::pair<int, char>);
			IF_FRAGMENT_FILE2MEM(std::pair<int, long long>);
			IF_FRAGMENT_FILE2MEM(std::pair<int, double>);
			IF_FRAGMENT_FILE2MEM(std::pair<int, float>);
			IF_FRAGMENT_FILE2MEM(std::pair<int, std::string>);

			IF_FRAGMENT_FILE2MEM(std::pair<bool, int>);
			IF_FRAGMENT_FILE2MEM(std::pair<bool, bool>);
			IF_FRAGMENT_FILE2MEM(std::pair<bool, char>);
			IF_FRAGMENT_FILE2MEM(std::pair<bool, long long>);
			IF_FRAGMENT_FILE2MEM(std::pair<bool, double>);
			IF_FRAGMENT_FILE2MEM(std::pair<bool, float>);
			IF_FRAGMENT_FILE2MEM(std::pair<bool, std::string>);

			IF_FRAGMENT_FILE2MEM(std::pair<char, int>);
			IF_FRAGMENT_FILE2MEM(std::pair<char, bool>);
			IF_FRAGMENT_FILE2MEM(std::pair<char, char>);
			IF_FRAGMENT_FILE2MEM(std::pair<char, long long>);
			IF_FRAGMENT_FILE2MEM(std::pair<char, double>);
			IF_FRAGMENT_FILE2MEM(std::pair<char, float>);
			IF_FRAGMENT_FILE2MEM(std::pair<char, std::string>);

			IF_FRAGMENT_FILE2MEM(std::pair<long long, int>);
			IF_FRAGMENT_FILE2MEM(std::pair<long long, bool>);
			IF_FRAGMENT_FILE2MEM(std::pair<long long, char>);
			IF_FRAGMENT_FILE2MEM(std::pair<long long, long long>);
			IF_FRAGMENT_FILE2MEM(std::pair<long long, double>);
			IF_FRAGMENT_FILE2MEM(std::pair<long long, float>);
			IF_FRAGMENT_FILE2MEM(std::pair<long long, std::string>);

			IF_FRAGMENT_FILE2MEM(std::pair<double, int>);
			IF_FRAGMENT_FILE2MEM(std::pair<double, bool>);
			IF_FRAGMENT_FILE2MEM(std::pair<double, char>);
			IF_FRAGMENT_FILE2MEM(std::pair<double, long long>);
			IF_FRAGMENT_FILE2MEM(std::pair<double, double>);
			IF_FRAGMENT_FILE2MEM(std::pair<double, float>);
			IF_FRAGMENT_FILE2MEM(std::pair<double, std::string>);

			IF_FRAGMENT_FILE2MEM(std::pair<float, int>);
			IF_FRAGMENT_FILE2MEM(std::pair<float, bool>);
			IF_FRAGMENT_FILE2MEM(std::pair<float, char>);
			IF_FRAGMENT_FILE2MEM(std::pair<float, long long>);
			IF_FRAGMENT_FILE2MEM(std::pair<float, double>);
			IF_FRAGMENT_FILE2MEM(std::pair<float, float>);
			IF_FRAGMENT_FILE2MEM(std::pair<float, std::string>);

			IF_FRAGMENT_FILE2MEM(std::pair<std::string, int>);
			IF_FRAGMENT_FILE2MEM(std::pair<std::string, bool>);
			IF_FRAGMENT_FILE2MEM(std::pair<std::string, char>);
			IF_FRAGMENT_FILE2MEM(std::pair<std::string, long long>);
			IF_FRAGMENT_FILE2MEM(std::pair<std::string, double>);
			IF_FRAGMENT_FILE2MEM(std::pair<std::string, float>);
			IF_FRAGMENT_FILE2MEM(std::pair<std::string, std::string>);
		}
	}

	template <typename T>
	bool serialize_xml(const T& object, const std::string& type, const std::string& path)
	{
		XMLDocument doc;
		XMLElement* root = doc.NewElement("serialization");
		memory2file(object, type, root, doc);
		doc.InsertEndChild(root);
		return doc.SaveFile(path.c_str());
	}

	template <typename T>
	bool deserialize_xml(T& object, const std::string& type, const std::string& path)
	{
		XMLDocument doc;
		XMLError e = doc.LoadFile(path.c_str());
		if (e != XML_SUCCESS) {
			std::cout << "Fail to open! Please check the .xml file!" << std::endl;
			return false;
		}
		XMLElement* root = doc.FirstChildElement("serialization");
		if (root == nullptr) {
			std::cout << "Invalid serialization document! Please check the .xml file!" << std::endl;
			return false;
		}
		else {
			file2memory(object, root, type);
		}
	}



}


