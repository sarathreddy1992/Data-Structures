#pragma once
#include<iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void fillOrder(int v, bool visited[], stack<int> &Stack);
	void DFSUtil(int v, bool visited[]);

	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void topologicalSort();
	void printSCCs();
	Graph getTranspose();
};