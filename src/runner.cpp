//============================================================================
// Name        : JsonFileParser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "json/json.h"

using namespace std;
Json::Value jsonFileParser(string fileName);


int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	string fileName("E://Program Files (x86)//workspace//JsonFileParser//src//config.json");
	Json::Value root = jsonFileParser(fileName);
	if(root==NULL){
		cout<<"The json file cannot be parsed."<<endl;
	}else{
		cout<<root["PDBFileDatabaseLocation"].asString()<<endl;
	}

	return 0;
}

Json::Value jsonFileParser(string fileName) {
	Json::Reader reader;
	Json::Value root;

	//read from file
	ifstream is;
	is.open(fileName.c_str(), ios::binary);

	if (reader.parse(is, root)) {
		return root;
	}else{
		return NULL;
	}
}
