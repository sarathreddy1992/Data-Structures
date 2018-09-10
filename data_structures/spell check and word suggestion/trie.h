
#pragma once

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Node {
public:
	Node() { mContent = ' '; mMarker = false; }
	Node(char input)
	{
		mContent = input;
	}
	~Node() {}
	char content() { return mContent; }
	void setContent(char c) { mContent = c; }
	bool wordMarker() { return mMarker; }
	void setWordMarker() { mMarker = true; }
	Node* findChild(char c);
	void appendChild(Node* child) { mChildren.push_back(child); }
	vector<Node*> children() { return mChildren; }
	string retrieve(string input, int charLocation);
	
private:
	char mContent;
	bool mMarker;
	vector<Node*> mChildren;
};

class Trie {
	int totalNodes = 0;
public:
	Trie();
	~Trie();
	void addWord(string s);
	bool searchWord(string s);
	string retrieve(string word);
	bool autoComplete(string s, vector<string>&res);
	void parseTree(Node *current, char*s, vector<string>&res, bool &loop) 
	{
		char k[100] = { 0 };
		char a[2] = { 0 };
		if (loop)
		{
			if (current != NULL)
			{
				if (current->wordMarker() == true) {
					res.push_back(s);
					if (res.size() > 15)
						loop = false;
				}
				vector<Node *> child = current->children();
				for (int i = 0; i < child.size() && loop; i++) {
					strcpy(k, s);
					a[0] = child[i]->content();
					a[1] = '\0';
					strcat(k, a);
					if (loop)
						parseTree(child[i], k, res, loop);
				}

			}
		}
	}
private:
	Node* root;
};

Node* Node::findChild(char c)
{
	for (int i = 0; i < mChildren.size(); i++)
	{
		Node* tmp = mChildren.at(i);
		if (tmp->content() == c)
		{
			return tmp;
		}
	}

	return NULL;
}

Trie::Trie()
{
	root = new Node();
}

Trie::~Trie()
{
	// Free memory
}


bool Trie::searchWord(string s)
{
	Node* current = root;

	while (current != NULL)
	{
		for (int i = 0; i < s.length(); i++)
		{
			Node* tmp = current->findChild(s[i]);
			if (tmp == NULL)
				return false;
			current = tmp;
		}

		if (current->wordMarker())
			return true;
		else
			return false;
	}

	return false;
}


void Trie::addWord(string s)
{
	Node* current = root;

	if (s.length() == 0)
	{
		current->setWordMarker(); // an empty word
		return;
	}

	for (int i = 0; i < s.length(); i++)
	{
		Node* child = current->findChild(s[i]);
		if (child != NULL)
		{
			current = child;
		}
		else
		{
			Node* tmp = new Node();
			tmp->setContent(s[i]);
			current->appendChild(tmp);
			current = tmp;
		}
		if (i == s.length() - 1)
			current->setWordMarker();
	}
}
bool Trie::autoComplete(std::string s, std::vector<string> &res)
{
	Node *current = root;

	for (int i = 0; i < s.length(); i++)
	{
		Node* tmp = current->findChild(s[i]);
		if (tmp == NULL)
			return false;
		current = tmp;
	}

	char c[100];
	strcpy(c, s.c_str());
	bool loop = true;
	parseTree(current, c, res, loop);
	return true;

}



string Node::retrieve(string input, int charLocation)   
{
	string output = "";// input;
	if (charLocation <= input.length() - 1)
	{
		//Get to correct branch
		vector<Node*>::iterator child;
		for (child = mChildren.begin(); child != mChildren.end(); child++)
		{
			if ((*child)->content() == input[charLocation])
				break;
		}
		if (child == mChildren.end())
			return "";
		else
		{
			return (*child)->retrieve(input, charLocation + 1);
		}
	}
	//else if (mContent == '\0')
	//{
	//	return input + "\n";
	//}
	else
	{
		//All the subsequent strings will be recommendations
		if (mChildren.size() > 0) {
			for (vector<Node*>::iterator child = mChildren.begin(); child != mChildren.end(); child++)
			{
				string temp = ""; temp += (*child)->content();
				temp += (*child)->retrieve(input + ((*child)->content()), charLocation + 1);
				output = temp;
				break;
			}
		}
		return output;
	}
}


string Trie::retrieve(string word)
{
	string wordToAdd = word;
	transform(wordToAdd.begin(), wordToAdd.end(), wordToAdd.begin(), ::tolower);
	return root->retrieve(wordToAdd, 0);
}


