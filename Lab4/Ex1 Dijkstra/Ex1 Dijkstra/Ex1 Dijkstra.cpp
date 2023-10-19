#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> int_pair;


class Graf
{
private:

	int V, E, s;
	list<int_pair>* adj;
	char* input;
	char* output;

public:

	Graf(char* input, char* output);
	~Graf();
	void citeste_graf();
	void dijkstra();
};


Graf::Graf(char* input, char* output)
{
	this->input = input;
	this->output = output;
	this->V = 0;
	this->E = 0;
	this->s = 0;
	this->adj = nullptr;
}


Graf::~Graf()
{
	delete[] this->adj;
}


void Graf::citeste_graf()
{
	int u, v, w;
	int V, E, s;

	ifstream fin(input);

	fin >> V >> E >> s;

	this->V = V;
	this->E = E;
	this->s = s;

	adj = new list<int_pair>[V + 1];

	for (int i = 1; i <= E; i++)
	{
		fin >> u >> v >> w;
		//cout << u << " " << v << " " << w << "\n";
		adj[u].push_back(make_pair(v, w));
	}

	fin.close();
}


void Graf::dijkstra()
{
	// indexare de la 0 la varfuri

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

			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parinte[v] = u;
				PQ.push(make_pair(dist[v], v));
			}
		}
	}

	ofstream fout(output);
	for (int i = 0; i < V; i++)
	{
		if (dist[i] == INT_MAX)
			fout << "INF ";
		else
			fout << dist[i] << " ";
	}
	fout.close();
}


int main(int argc, char* argv[])
{
	Graf g(argv[1], argv[2]);
	g.citeste_graf();
	g.dijkstra();

	return 0;
}