#include "XMLSerialization.h"


namespace XMLSerialization {

	template <>
	void memory2file<int>(const int& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		obj->SetAttribute("val", object);
		root->InsertEndChild(obj);
	}

	template <>
	void memory2file<double>(const double& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		obj->SetAttribute("val", object);
		root->InsertEndChild(obj);
	}

	template <>
	void memory2file<float>(const float& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		obj->SetAttribute("val", object);
		root->InsertEndChild(obj);
	}

	template <>
	void memory2file<long long>(const long long& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		obj->SetAttribute("val", object);
		root->InsertEndChild(obj);
	}

	template <>
	void memory2file<char>(const char& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		obj->SetAttribute("val", object);
		root->InsertEndChild(obj);
	}

	template <>
	void memory2file<bool>(const bool& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		obj->SetAttribute("val", object);
		root->InsertEndChild(obj);
	}

	void memory2file(const std::string& object, const std::string& type, XMLElement* root, XMLDocument& doc)
	{
		XMLElement* obj = doc.NewElement(type.c_str());
		obj->SetAttribute("val", object.c_str());
		root->InsertEndChild(obj);
	}

	void file2memory(std::string& object, XMLElement* root, const std::string& type)
	{
		if (type == "") {
			object = root->Attribute("val");
		}
		else {
			XMLElement* p = root->FirstChildElement(type.c_str());
			if (p != nullptr) {
				object = p->Attribute("val");
			}
			else {
				std::cout << "Deserialization failure!" << std::endl;
			}
		}
	}

	void file2memory(int& object, XMLElement* root, const std::string& type)
	{
		if (type == "") {
			object = atoi(root->Attribute("val"));
		}
		else {
			XMLElement* p = root->FirstChildElement(type.c_str());
			if (p != nullptr) {
				object = atoi(p->Attribute("val"));
			}
			else {
				std::cout << "Deserialization failure!" << std::endl;
			}
		}
	}

	void file2memory(float& object, XMLElement* root, const std::string& type)
	{
		if (type == "") {
			object = atof(root->Attribute("val"));
		}
		else {
			XMLElement* p = root->FirstChildElement(type.c_str());
			if (p != nullptr) {
				object = atof(p->Attribute("val"));
			}
			else {
				std::cout << "Deserialization failure!" << std::endl;
			}
		}
	}

	void file2memory(double& object, XMLElement* root, const std::string& type)
	{
		if (type == "") {
			object = atof(root->Attribute("val"));
		}
		else {
			XMLElement* p = root->FirstChildElement(type.c_str());
			if (p != nullptr) {
				object = atof(p->Attribute("val"));
			}
			else {
				std::cout << "Deserialization failure!" << std::endl;
			}
		}
	}

	void file2memory(long long& object, XMLElement* root, const std::string& type)
	{
		if (type == "") {
			object = atoll(root->Attribute("val"));
		}
		else {
			XMLElement* p = root->FirstChildElement(type.c_str());
			if (p != nullptr) {
				object = atoll(p->Attribute("val"));
			}
			else {
				std::cout << "Deserialization failure!" << std::endl;
			}
		}
	}

	void file2memory(bool& object, XMLElement* root, const std::string& type)
	{
		std::string tmp;
		if (type == "") {
			tmp = root->Attribute("val");
		}
		else {
			XMLElement* p = root->FirstChildElement(type.c_str());
			if (p != nullptr) {
				tmp = p->Attribute("val");
			}
			else {
				std::cout << "Deserialization failure!" << std::endl;
				return;
			}
		}
		if (strcmp(tmp.c_str(), "true") == 0) {
			object = true;
		}
		else if (strcmp(tmp.c_str(), "false") == 0) {
			object = false;
		}
	}

	void file2memory(char& object, XMLElement* root, const std::string& type)
	{
		if (type == "") {
			object = (char)atoi(root->Attribute("val"));
		}
		else {
			XMLElement* p = root->FirstChildElement(type.c_str());
			if (p != nullptr) {
				object = (char)atoi(p->Attribute("val"));
			}
			else {
				std::cout << "Deserialization failure!" << std::endl;
			}
		}
	}

	void file2memory(std::vector<bool>& object, XMLElement* root, const std::string& type)
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
			if (strcmp(current->Attribute("val"), "true") == 0) {
				object.push_back(true);
			}
			else {
				object.push_back(false);
			}
		}
	}



}


