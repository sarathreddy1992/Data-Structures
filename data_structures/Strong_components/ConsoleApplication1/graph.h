//source geekforgeeks



#pragma once

#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<unordered_map>
#include<iterator>
#include"dependency.h"


using namespace std;
class Graph
{
public:
	using name = unordered_map<string, int>;
	using name2 = unordered_map<string, vector<string>>;
	using vect = vector<string>;
	name map;
	vect list1;
	vect dependencylist;
	int V;    
	list<int> *adj;    
	void fillOrder(int v, bool visited[], stack<int> &Stack);
	void DFSUtil(int v, bool visited[], name map);
    name2 values;
	Graph (int V);   
	void addEdge(int v, int w);   
	void DisplayDfs(int v, bool visited[], name map);
	void setmap(name2 obj);
	void vectorlist();
	void graph_();
	void DFS(name map);
	void topologicalSort(name map);
	void printSCCs(name map);
	Graph getTranspose();
};


