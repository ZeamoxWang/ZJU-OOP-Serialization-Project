#pragma once
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <map>

//using namespace std;

#define INITIALIZE(className)										\
		public:														\
			std::vector<void(className::*)(void*) const> getFunc;	\
			std::vector<void(className::*)(void*)> writeFunc;		\
			std::vector<std::string> types;							\


#define INITIALIZE_MEM(name, rank, ...)											\
		public:																	\
			__VA_ARGS__ name;													\
			void get##rank(void* obj) const {*(__VA_ARGS__*)obj = this->name;};	\
			void write##rank(void* obj) {this->name = *(__VA_ARGS__*)obj;};		\

#define REGISTER_MEM(className, rank, ...)										\
		{getFunc.push_back(&className::get##rank);								\
		writeFunc.push_back(&className::write##rank);							\
		types.push_back(#__VA_ARGS__);}											\

// For any user defined type, you should use macro functions to declare
// and register them in ctor!
struct UserDefinedType {
	// First, you should call INITIALIZE with the class name;
	INITIALIZE(UserDefinedType);
	// Second, you should call INITIALIZE_MEM to declare the members;
	INITIALIZE_MEM(idx, 0, int);
	INITIALIZE_MEM(name, 1, std::string);
	INITIALIZE_MEM(data, 2, std::vector<double>);
	INITIALIZE_MEM(mymap, 3, std::map<std::string, float>);
public:
	UserDefinedType() {
		// Third, you should call REGISTER_MEM to register members in ctor;
		REGISTER_MEM(UserDefinedType, 0, int);
		REGISTER_MEM(UserDefinedType, 1, std::string);
		REGISTER_MEM(UserDefinedType, 2, std::vector<double>);
		REGISTER_MEM(UserDefinedType, 3, std::map<std::string, float>);
	};
};
