#include <iostream>
#include "XMLSerialization.h"
#include "BinarySerialization.h"

using namespace std;

int main(void) {

	cout << "Please type in the test number from 0-25;" << endl;


	int test;
	cin >> test;
	switch (test) {
	case 0: {
		cout << "Test int using XML Serialization:" << endl;
		int a = 2022, b;
		XMLSerialization::serialize_xml(a, "int", "int.xml");
		XMLSerialization::deserialize_xml(b, "int", "int.xml");
		cout << b;
		break;
	}
	case 1: {
		cout << "Test long long using XML Serialization:" << endl;
		long long a = 3190100466l, b;
		XMLSerialization::serialize_xml(a, "longlong", "longlong.xml");
		XMLSerialization::deserialize_xml(b, "longlong", "longlong.xml");
		cout << b;
		break;
	}
	case 2: {
		cout << "Test bool using XML Serialization:" << endl;
		bool a = true, b;
		XMLSerialization::serialize_xml(a, "bool", "bool.xml");
		XMLSerialization::deserialize_xml(b, "bool", "bool.xml");
		cout << b;
		break;
	}
	case 3: {
		cout << "Test float using XML Serialization:" << endl;
		float a = 6.1, b;
		XMLSerialization::serialize_xml(a, "float", "float.xml");
		XMLSerialization::deserialize_xml(b, "float", "float.xml");
		cout << b;
		break;
	}
	case 4: {
		cout << "Test double using XML Serialization:" << endl;
		double a = 6.1, b;
		XMLSerialization::serialize_xml(a, "double", "double.xml");
		XMLSerialization::deserialize_xml(b, "double", "double.xml");
		cout << b;
		break;
	}
	case 5: {
		cout << "Test char using XML Serialization:" << endl;
		char a = 'a', b;
		XMLSerialization::serialize_xml(a, "char", "char.xml");
		XMLSerialization::deserialize_xml(b, "char", "char.xml");
		cout << b;
		break;
	}
	case 6: {
		cout << "Test string using XML Serialization:" << endl;
		string a = "It works well.", b;
		XMLSerialization::serialize_xml(a, "string", "string.xml");
		XMLSerialization::deserialize_xml(b, "string", "string.xml");
		cout << b;
		break;
	}
	case 7: {
		cout << "Test set using XML Serialization:" << endl;
		set<string> a = { "It","works","well" }, b;
		XMLSerialization::serialize_xml(a, "set", "set.xml");
		XMLSerialization::deserialize_xml(b, "set", "set.xml");
		for (auto x : b) {
			cout << x << endl;
		}
		break;
	}
	case 8: {
		cout << "Test vector using XML Serialization:" << endl;
		vector<bool> a = { 0,1,0,0,1 }, b;
		XMLSerialization::serialize_xml(a, "vector", "vector.xml");
		XMLSerialization::deserialize_xml(b, "vector", "vector.xml");
		for (auto x : b) {
			cout << x << endl;
		}
		break;
	}
	case 9: {
		cout << "Test list using XML Serialization:" << endl;
		list<int> a = { 1,2,3,4,5,6,7,8,9 }, b;
		XMLSerialization::serialize_xml(a, "list", "list.xml");
		XMLSerialization::deserialize_xml(b, "list", "list.xml");
		for (auto x : b) {
			cout << x << endl;
		}
		break;
	}
	case 10: {
		cout << "Test pair using XML Serialization:" << endl;
		pair<char, vector<int>> a = { 'a',{1,3,5,7,9} }, b;
		XMLSerialization::serialize_xml(a, "pair", "pair.xml");
		XMLSerialization::deserialize_xml(b, "pair", "pair.xml");
		cout << b.first << ":";
		for (auto x : b.second) {
			cout << x << " ";
		}
		break;
	}
	case 11: {
		cout << "Test map using XML Serialization:" << endl;
		map<list<bool>, string> a = { { {0,0,1}, "ans=1" },{{0,1,0},"ans=2"} }, b;
		XMLSerialization::serialize_xml(a, "map", "map.xml");
		XMLSerialization::deserialize_xml(b, "map", "map.xml");
		for (auto x : b) {
			cout << "The key is: ";
			for (auto y : x.first) {
				cout << y << " ";
			}
			cout << "\nThe value is: " << x.second << endl;
		}
		break;
	}
	case 12: {
		cout << "Test user defined type using XML Serialization:" << endl;
		UserDefinedType a, b;
		a.idx = 5;
		a.name = "ook";
		a.data = { 2.3, 4.3, 5.4 };
		a.mymap = { {"1", 1.32}, {"2", 2.43} };
		XMLSerialization::serialize_xml(a, "UserDefinedType", "UserDefinedType.xml");
		XMLSerialization::deserialize_xml(b, "UserDefinedType", "UserDefinedType.xml");
		cout << "idx is " << b.idx << endl;
		cout << "name is " << b.name << endl;
		cout << "data are ";
		for (auto x : b.data) {
			cout << x << " ";
		}
		cout << "\nmymap are ";
		for (auto x : b.mymap) {
			cout << x.first << ":" << x.second << " ";
		}
		break;
	}
	case 13: {
		cout << "Test int using Binary Serialization:" << endl;
		int a = 2022, b;
		BinarySerialization::serialize(a, "int.data");
		BinarySerialization::deserialize(b, "int.data");
		cout << b;
		break;
	}
	case 14: {
		cout << "Test long long using Binary Serialization:" << endl;
		long long a = 3190100466l, b;
		BinarySerialization::serialize(a, "longlong.data");
		BinarySerialization::deserialize(b, "longlong.data");
		cout << b;
		break;
	}
	case 15: {
		cout << "Test bool using Binary Serialization:" << endl;
		bool a = true, b;
		BinarySerialization::serialize(a, "bool.data");
		BinarySerialization::deserialize(b, "bool.data");
		cout << b;
		break;
	}
	case 16: {
		cout << "Test float using Binary Serialization:" << endl;
		float a = 6.1, b;
		BinarySerialization::serialize(a, "float.data");
		BinarySerialization::deserialize(b, "float.data");
		cout << b;
		break;
	}
	case 17: {
		cout << "Test double using Binary Serialization:" << endl;
		double a = 6.1, b;
		BinarySerialization::serialize(a, "double.data");
		BinarySerialization::deserialize(b, "double.data");
		cout << b;
		break;
	}
	case 18: {
		cout << "Test char using Binary Serialization:" << endl;
		char a = 'a', b;
		BinarySerialization::serialize(a, "char.data");
		BinarySerialization::deserialize(b, "char.data");
		cout << b;
		break;
	}
	case 19: {
		cout << "Test string using Binary Serialization:" << endl;
		string a = "It works well.", b;
		BinarySerialization::serialize(a, "string.data");
		BinarySerialization::deserialize(b, "string.data");
		cout << b;
		break;
	}
	case 20: {
		cout << "Test set using Binary Serialization:" << endl;
		set<string> a = { "It","works","well" }, b;
		BinarySerialization::serialize(a, "set.data");
		BinarySerialization::deserialize(b, "set.data");
		for (auto x : b) {
			cout << x << endl;
		}
		break;
	}
	case 21: {
		cout << "Test vector using Binary Serialization:" << endl;
		vector<bool> a = { 0,1,0,0,1 }, b;
		BinarySerialization::serialize(a, "vector.data");
		BinarySerialization::deserialize(b, "vector.data");
		for (auto x : b) {
			cout << x << endl;
		}
		break;
	}
	case 22: {
		cout << "Test list using Binary Serialization:" << endl;
		list<int> a = { 1,2,3,4,5,6,7,8,9 }, b;
		BinarySerialization::serialize(a, "list.data");
		BinarySerialization::deserialize(b, "list.data");
		for (auto x : b) {
			cout << x << endl;
		}
		break;
	}
	case 23: {
		cout << "Test pair using Binary Serialization:" << endl;
		pair<char, vector<int>> a = { 'a',{1,3,5,7,9} }, b;
		BinarySerialization::serialize(a, "pair.data");
		BinarySerialization::deserialize(b, "pair.data");
		cout << b.first << ":";
		for (auto x : b.second) {
			cout << x << " ";
		}
		break;
	}
	case 24: {
		cout << "Test map using Binary Serialization:" << endl;
		map<list<bool>, string> a = { { {0,0,1}, "ans=1" },{{0,1,0},"ans=2"} }, b;
		BinarySerialization::serialize(a, "map.data");
		BinarySerialization::deserialize(b, "map.data");
		for (auto x : b) {
			cout << "The key is: ";
			for (auto y : x.first) {
				cout << y << " ";
			}
			cout << "\nThe value is: " << x.second << endl;
		}
		break;
	}
	case 25: {
		cout << "Test user defined type using Binary Serialization:" << endl;
		UserDefinedType a, b;
		a.idx = 5;
		a.name = "ook";
		a.data = { 2.3, 4.3, 5.4 };
		a.mymap = { {"1", 1.32}, {"2", 2.43} };
		BinarySerialization::serialize(a, "UserDefinedType.data");
		BinarySerialization::deserialize(b, "UserDefinedType.data");
		cout << "idx is " << b.idx << endl;
		cout << "name is " << b.name << endl;
		cout << "data are ";
		for (auto x : b.data) {
			cout << x << " ";
		}
		cout << "\nmymap are ";
		for (auto x : b.mymap) {
			cout << x.first << ":" << x.second << " ";
		}
		break;
	}
	}
	return 0;
}