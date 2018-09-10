
#include <sstream>
#include"FileSystem.h"
#include"Hash.h"
#include"MyKey.h"
#include<iterator>
#include<cstdlib>
#include "queue.h"
#include "trie.h"
using namespace std;

std::vector<string> fileRead(string file);
vector<string>RemovePunc(string f);
std::string str1;


void split(const std::string &str, std::string sep, std::vector<std::string> &read)
{
	char* cstr = const_cast<char*>(str.c_str());
	char* current;
	std::vector<std::string>arr;
	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());


	}
	
}

inline vector<string> edit(string main1)
{
	string temp;
	vector<string> onewordaway;
	for (int i = 0; i < main1.length(); i++) {
		temp = main1.substr(0, i) + main1.substr(i + 1);
		onewordaway.push_back(temp);
	}
	for (int i = 0; i < main1.length() ; i++)
	{
		temp = main1.substr(0, i) + main1[(i + 1) % main1.length()] + main1[i] + main1.substr((i + 2) % main1.length());
		onewordaway.push_back(temp);
	}
	int j = 0;
	while (j < main1.length()) {
		for (int i = 0; i < 26; i++) {
			string originalString = main1; 
			char c = i + 65;
			stringstream streamConvertor;
			streamConvertor << c;
			string word;
			streamConvertor >> word;
			string bv = originalString.replace(j, 1, word);
		    onewordaway.push_back(bv);
		}
		j++;
	}
	return onewordaway;
}

using namespace std;



int main()
{
	vector<string> p;

	FileSystem::Directory::setCurrentDirectory(".\\inputfiles\\");

	Trie* trie = new Trie();

	std::cout << "************************FIRST REQUIRMENT************************" << std::endl;
	std::cout << "========================================================================"<<std::endl;

	std::ifstream dictionary("dictionary.txt");  


	if (dictionary)
	{
		std::cout << "Words are being inserted into the trie data structure" << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
	else
	{
		std::cout << "could not read the file" << std::endl;
	}
	std::string input;
	while (std::getline(dictionary, input))
	{
		trie->addWord(input);
	}
	dictionary.close();


	std::cout << "Reading the TobeSpellChecked file for errors:"<<std::endl;
	std::cout << "================================================================"<<std::endl;
	

std::vector<std::string> qfile;
	std::ifstream filecheck("TobeSpellChecked.txt");
	std::vector<std::string> Read;
	if (filecheck)
	{
		std::cout << "able to read file"<<std::endl;
	}
	else
	{
		std::cout << "cannot read file"<<std::endl;
	}
	//filecheck.close();
	
	while (std::getline(filecheck, str1))
	{
		qfile.push_back(str1);
	}
	
	for (int i = 0;i<str1.size(); i++)
	{
		if (ispunct(str1[i]))
		{
			str1.erase(i--, 1);
		}
	}


	string stng;
	istringstream stringStream(str1);
	while (std::getline(stringStream, stng, ' ')) {
		std::transform(stng.begin(), stng.end(), stng.begin(), tolower);
		int count = 0;
		vector<string> suggestions;

		if (trie->searchWord(stng)) {
			//	output<<s<<" Correct word "<<endl;
			std::cout << stng << "  found in Dictionary" << endl;
		}
		else
		{
			Queue edit_list;
			vector<string> outcomes;
			edit_list.Enqueue(stng);
			int breakout = 0;
			while (count < 10 && breakout < 10)
			{
				string word = edit_list.Dequeue();
				auto suggestions = edit(word);
				for (int i = 0; i < suggestions.size(); i++) {
					if (trie->searchWord(suggestions[i]))
					{
						outcomes.push_back(suggestions[i]);
						count++;
					}
					else
						edit_list.Enqueue(suggestions[i]);
				}
				breakout++;
			}
			if (count == 0) {
				std::cout << "No suggestions" << endl;
			}
			else
			{
				std::cout << "Did you mean" << endl;
				vector<string>::iterator itr;
				for (itr = outcomes.begin(); itr != outcomes.end(); itr++)
					std::cout << *itr << endl;
			}
		}
	}

	std::cout << "---------------SECOND REQUIRMENT--------------------------" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	std::ifstream dictionary1("dictionary.txt");  //Addding dictionary file


	if (dictionary1)
	{
		std::cout << "Words are being inserted into the trie data structure" << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
	else
	{
		std::cout << "could not read the file" << std::endl;
	}
	std::string input2;
	while (std::getline(dictionary1, input2))
	{
		trie->addWord(input2);
	}
	dictionary1.close();
	std::cout << "Enter a prefix and we will tell you what words are possible. .\n";
	std::string prefix;
	std::getline(std::cin, prefix);

	std::string nex_word = trie->retrieve(prefix);

	std::cout << "Next Word: ";
	std::cout << "\n" << " " << prefix + nex_word << std::endl;


	cout << "\n************REQUIREMENT 3***********\n";
	std::cout << "=============================================================\n";

	std::cout << "text files in .\\ inputfiles";
	std::vector<std::string> temp;
	p = FileSystem::Directory::getFiles(".", "*.txt");
	std::string direc = FileSystem::Directory::getCurrentDirectory();
	//FileSystem::Directory::setCurrentDirectory(".\\inputFiles");
	for (size_t i = 0; i < temp.size(); ++i)
	{
		std::cout << "\n    " << FileSystem::Path::getFullFileSpec(temp[i]).c_str();
	}	
	
	HashMap<string, std::vector<string>, hash_generator> hmap1;
	vector<string> o;
	
	for (auto a = 0; a < p.size(); a++) {
		o = RemovePunc(p[a]);

		for (auto b = 0; b != o.size(); b++) {
			vector<string> eachFile;
	
			if (hmap1.get(o[b], eachFile)) {
				if (eachFile.size() > 0 && std::find(eachFile.begin(), eachFile.end(), p[a]) == eachFile.end()) {
					eachFile.push_back(p[a]);
					hmap1.put(o[b], eachFile);
				}
			}
			else {
				eachFile.push_back(p[a]);
				hmap1.put(o[b], eachFile);
			}
		}
	}
	vector<string> value1;
	cout << "\n Demo: \nSearching for the word collection in the files.\n";
	cout << hmap1.get("the", value1);
	for (auto str : value1)
		cout << "      -  " << str << endl;
	cout << "\n";
	value1.clear();
	char input1_ = 'y';
	string word_;
	while (input1_ == 'y') {
		cout << "enter the word to be searched: ";
		cin >> word_;
		cout << hmap1.get(word_, value1);
		for (auto str : value1)
			cout << "      -  " << str << endl;
		cout << "\n\n";
		value1.clear();
		cout << "Do you want to continue (y/n)? \n";
		cin >> input1_;
	}
 std::cin.get();
	return 0;
}
vector<string>RemovePunc(string f) {
	vector<string>	read_Files;// = fileRead(f);
	read_Files.clear();
	read_Files = fileRead(f);
	for (auto i = 0; i < read_Files.size(); i++) {
		read_Files[i].erase(std::remove_if(read_Files[i].begin(), read_Files[i].end(), ispunct), read_Files[i].end());
	}

	//for (auto i = 0; i < read_Files.size(); i++) {// display contents of each file
	//	 cout << read_Files[i];
	//}
	return read_Files;
}
std::vector<string> fileRead(string file)
{
	string c = "";
	std::vector< string> readFile;
	readFile.clear();
	ifstream infile;
	infile.open(file);
	if (!infile)
	{
		cout << "There was a problem opening file " << file << " for reading." << endl;
	}
	//	cout << "Opened " << file << " for reading." << endl;
	while (infile >> c)//.get(c))
	{
		//	cout << c;
		int i = 0;
		while (c[i] != '\0') {
			if (int(c[i]) < 0 || int(c[i]) > 254) {
				c[i] = ' ';
			}
			i++;
		}
		readFile.push_back(c);
	}
	infile.clear();
	infile.close();
	//cout << "File read successfully. " << endl;
	return readFile;
}