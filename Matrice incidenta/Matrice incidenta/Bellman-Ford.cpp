//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//ifstream fin("bellman_ford.txt");
//
//
//struct arc
//{
//	int surs;
//	int dest;
//	int pond;
//};
//
//class Graf
//{
//private:
//
//	int V, E;
//	arc* arce;
//
//public:
//
//	Graf(int V, int E);
//	~Graf();
//	void citeste_graf();
//	void bellman_ford(int s);
//};
//
//Graf::Graf(int V, int E)
//{
//	this->V = V;
//	this->E = E;
//	this->arce = new arc[E];
//}
//
//Graf::~Graf()
//{
//	delete[] this->arce;
//}
//
//void Graf::citeste_graf()
//{
//	for (int i = 0; i < E; i++)
//	{
//		fin >> arce[i].surs;
//		fin >> arce[i].dest;
//		fin >> arce[i].pond;
//	}
//}
//
//void Graf::bellman_ford(int s)
//{
//	//int* dist = new int[V+1];
//	//int* parinte = new int[V+1];
//	
//	//for (int i = 1; i <= V; i++)
//	//{
//	//	dist[i] = INT_MAX;
//	//	parinte[i] = -1;
//	//}
//
//	vector<int> dist(V + 1, INT_MAX);
//	vector<int> parinte(V + 1, -1);
//	
//	dist[s] = 0;
//
//	for (int i = 1; i < V; i++)
//	{
//		for (int j = 0; j < E; j++)
//		{
//			int u = arce[j].surs;
//			int v = arce[j].dest;
//			int w = arce[j].pond;
//			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
//			{
//				dist[v] = dist[u] + w;
//				parinte[v] = u;
//			}
//		}
//	}
//
//	for (int i = 0; i < E; i++)
//	{
//		int u = arce[i].surs;
//		int v = arce[i].dest;
//		int w = arce[i].pond;
//		if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
//		{
//			cout << "Graful contine circuite de pondere negativa.\n";
//			return;
//		}
//	}
//
//	for (int i = 1; i <= V; i++)
//		cout << i << " -> " << dist[i] << " " << parinte[i] << endl;
//
//	//delete[] dist;
//	//delete[] parinte;
//}
//
//
//int main()
//{
//	int V, E;
//	fin >> V >> E;
//	Graf g(V, E);
//	g.citeste_graf();
//	g.bellman_ford(1);
//	return 0;
//}