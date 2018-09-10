#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include<iostream>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<string>

using namespace std;

class Dependency
{
public:
	vector<string> files;
	vector<string> packages;
	unordered_map<string, vector<string>> values;
	unordered_map<string, vector<string>> map();
	void setfileset(vector<string> file1);
	std::vector<string> fileRead(string file);
	void disp();
	void dependency(string PackageName, vector<string> list);
	vector<string> finddependecy();
	string getpackagename(string filename);
	void displaydependency();
	void replacestring(string old, string rep, string &file_contents);

};



#endif