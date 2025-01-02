#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class TableEntry{
public:
	string key;
	string value;

	TableEntry(string key, string value){
		this->key = key;
		this->value = value;
	}

	TableEntry(string key){
		this->key = key;
	}

	TableEntry(){
		this->key = "";
	}
};

#endif