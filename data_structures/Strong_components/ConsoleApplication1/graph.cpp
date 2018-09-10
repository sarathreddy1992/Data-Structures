#include"graph.h"

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DisplayDfs(int v, bool visited[], name map)
{
	visited[v] = true;
	{
		for (auto i = map.begin(); i != map.end(); i++)
		{
			if (i->second == v)
			{
				std::cout << i->first << " ";
			}
		}
		
	}
}

void Graph::setmap(name2 obj)
{
	values = obj;
	vectorlist();

}

void Graph::DFSUtil(int v, bool visited[], name map)
{

	visited[v] = true;
	std::cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited,map);
}

void Graph::vectorlist()
{
	name2::const_iterator it;
	for (it = values.begin(); it!= values.end(); it++)
	{
		list1.push_back(it->first);
	}
}

void Graph::graph_()
{
	for (int i = 0; i < list1.size(); i++)
	{
		map[list1[i]] = i;
	}

	int a = list1.size();

	Graph g(a);

	for (size_t j = 0; j < list1.size(); j++)
	{
		string s = list1[j];
		int i=84;
		name::const_iterator it;
		it = map.find(s);
		
		if (it == map.end())
		{
			std::cout << "not found \n";
		}
		else
		{
			i = it->second;

		}
		name2::const_iterator it2;
		it2 = values.find(list1[j]);
		if (it2 == values.end())
		{
			std::cout << "not found\n";
		}

		else
		{
			dependencylist = it2->second;
		}

		int i2=84;
		for (size_t k = 0; k < dependencylist.size(); k++)
		{
			name::const_iterator it3;
			it3 = map.find(dependencylist[k]);
			if (it3 == map.end())
			{
				std::cout << "not found \n";
			}
			else
			{
				i2 = it3->second;
				g.addEdge(i, i2);
				

			}

		}
		}
	

	

	cout << endl << "The vetices in the graph are:" << endl;
	cout << endl << "===========================================================" << endl;
	g.DFS(map);
	cout << endl << "following is the depth for search traversal" << endl;
	cout << "============================================================" << endl;
	g.printSCCs(map);
	cout << endl << "following are the strongly connected components in the graph" << endl;
	cout << endl << "=======================================================================" << endl;
	g.topologicalSort(map);
	cout << endl << "following is the topological sort in the graph" << endl;
	cout << "=====================================================================" << endl;

}


void Graph::DFS(name map)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			DFSUtil(i, visited,map);
}

// The function to do Topological Sort.
void Graph::topologicalSort(name map)
{
	vector<int> in_degree(V, 0);

	for (int u = 0; u<V; u++)
	{
		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
			in_degree[*itr]++;
	}

	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

		int cnt = 0;
		vector <int> top_order;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)

	if (--in_degree[*itr] == 0)
		q.push(*itr);

		cnt++;
	}

	// Check if there was a cycle
	if (cnt != V)
	{
		cout << "There exists a cycle in the graph\n";
		return;
	}

	// Print topological order
	for (int i = 0; i<top_order.size(); i++)
		cout << top_order[i] << " ";
	cout<<endl;
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
	
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	Stack.push(v);
}

// The main function that finds and prints all strongly connected 
// components
void Graph::printSCCs(name map)
{
	stack<int> Stack;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);


	Graph gr = getTranspose();

		for (int i = 0; i < V; i++)
		visited[i] = false;

	while (Stack.empty() == false)
	{
	int v = Stack.top();
		Stack.pop();

			if (visited[v] == false)
		{
			gr.DFSUtil(v, visited,map);
			cout << endl;
		}
	}
	


}



#ifdef Graph
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal\n";
	g.DFS();

	cout << "Following is a Topological Sort of\n";
	g.topologicalSort();

	cout << "Following are strongly connected components in "
		"given graph \n";
	g.printSCCs();
	return 0;
}
#endif