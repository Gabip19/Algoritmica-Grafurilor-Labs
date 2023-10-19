#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <cmath>

using namespace std;
ifstream fin("input.txt");

typedef pair<float, int> int_pair;

class Graf
{
private:

	int V, E;
	list<int_pair>* adj;

public:

	Graf(int V, int E);
	~Graf();
	void citeste_graf();
	void dijkstra(int s, int d);
};

Graf::Graf(int V, int E)
{
	this->V = V;
	this->E = E;
	adj = new list<int_pair>[V + 1];
}

Graf::~Graf()
{
	delete[] this->adj;
}

struct oras
{
	int x;
	int y;
};

void Graf::citeste_graf()
{
	vector<oras> orase;

	oras a;
	a.x = 0;
	a.y = 0;
	orase.push_back(a);
	for (int i = 1; i <= V; i++)
	{
		fin >> a.x >> a.y;
		orase.push_back(a);
	}

	int u, v;
	float w;
	for (int i = 1; i <= E; i++)
	{
		fin >> u >> v;
		w = (float)sqrt(((orase[v].x - orase[u].x) * (orase[v].x - orase[u].x)) + ((orase[v].y - orase[u].y) * (orase[v].y - orase[u].y)));
		adj[u].push_back(make_pair(v, w));
	}
}

void Graf::dijkstra(int s, int d)
{
	vector<int> dist(V + 1, INT_MAX);
	vector<int> parinte(V + 1, -1);

	dist[s] = 0;

	priority_queue<int_pair, vector<int_pair>, greater<int_pair>> PQ;
	PQ.push(make_pair(0, s));

	while (!PQ.empty())
	{
		int u = PQ.top().second;
		PQ.pop();

		list<int_pair>::iterator it;
		for (it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = it->first;
			int w = it->second;

			//cout << PQ.size() << " ";

			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parinte[v] = u;
				PQ.push(make_pair(dist[v], v));
			}
		}
	}

	for (int i = 1; i <= V; i++)
		cout << i << " -> " << dist[i] << " " << endl;

	cout << d << " ";
	int i = d;
	while (parinte[i] != -1)
	{
		cout << parinte[i] << " ";
		i = parinte[i];
	}
}

int main()
{
	int V, E, s, f;
	fin >> V >> E;
	cout << "Sura: "; cin >> s;
	cout << "Destinatie: "; cin >> f;
	Graf g(V, E);
	g.citeste_graf();
	g.dijkstra(s, f);
	return 0;
}