//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <list>
//#include <queue>
//
//using namespace std;
//ifstream fin("dijkstra.txt");
//
//typedef pair<int, int> int_pair;
//
//class Graf
//{
//private:
//
//	int V, E;
//	list<int_pair>* adj;
//
//public:
//
//	Graf(int V, int E);
//	~Graf();
//	void citeste_graf();
//	void dijkstra(int s);
//};
//
//Graf::Graf(int V, int E)
//{
//	this->V = V;
//	this->E = E;
//	adj = new list<int_pair>[V+1];
//}
//
//Graf::~Graf()
//{
//	delete[] this->adj;
//}
//
//void Graf::citeste_graf()
//{
//	int u, v, w;
//	for (int i = 1; i <= E; i++)
//	{
//		fin >> u >> v >> w;
//		adj[u].push_back(make_pair(v, w));
//	}
//}
//
//void Graf::dijkstra(int s)
//{
//	// indexare de la 0 la varfuri
//
//	vector<int> dist(V + 1, INT_MAX);
//	vector<int> parinte(V + 1, -1);
//	
//	dist[s] = 0;
//
//	priority_queue<int_pair, vector<int_pair>, greater<int_pair>> PQ;
//	PQ.push(make_pair(0, s));
//
//	while (!PQ.empty())
//	{
//		int u = PQ.top().second;
//		PQ.pop();
//
//		list<int_pair>::iterator it;
//		for (it = adj[u].begin(); it != adj[u].end(); it++)
//		{
//			int v = it->first;
//			int w = it->second;
//
//			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
//			{
//				dist[v] = dist[u] + w;
//				parinte[v] = u;
//				PQ.push(make_pair(dist[v], v));
//			}
//		}
//	}
//
//	for (int i = 0; i < V; i++)
//		cout << i << " -> " << dist[i] << " " << endl;// << parinte[i] << endl;
//}
//
//int main()
//{
//	int V, E, s;
//	fin >> V >> E >> s;
//	Graf g(V, E);
//	g.citeste_graf();
//	g.dijkstra(s);
//	return 0;
//}