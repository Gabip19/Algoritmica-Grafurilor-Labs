#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define MAX_INT 2147483647

using namespace std;


bool BFS(vector<int>* rGraf, int s, int d, vector<int>& parinte)
{
	int V = rGraf->size();
	vector<bool> gasit(V, false);

	queue<int> Q;
	Q.push(s);
	gasit[s] = true;
	parinte[s] = -1;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		for (int v = 0; v < V; ++v)
		{
			if (!gasit[v] && rGraf[u][v] > 0)
			{
				parinte[v] = u;
				if (v == d)
				{
					return true;
				}
				Q.push(v);
				gasit[v] = true;
			}
		}
	}

	return false;
}


int FluxMaxKarp(vector<int>* rGraf, int V, int E, int s, int t)
{
	int flux_max = 0;

	vector<int> parinte(V);
	while (BFS(rGraf, s, t, parinte))
	{
		int flux_cale = MAX_INT;
		for (int v = t; v != s; v = parinte[v])
		{
			int u = parinte[v];
			if (rGraf[u][v] < flux_cale)
				flux_cale = rGraf[u][v];
		}

		for (int v = t; v != s; v = parinte[v])
		{
			int u = parinte[v];
			rGraf[u][v] -= flux_cale;
			rGraf[v][u] += flux_cale;
		}

		flux_max += flux_cale;
	}

	return flux_max;
}


int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	
	int V, E;
	fin >> V >> E;

	vector<int>* rGraf = new vector<int>[V];

	for (int i = 0; i < V; i++)
	{
		rGraf[i] = vector<int>(V, 0);
	}

	for (int i = 0; i < E; ++i)
	{
		int u, v, c;
		fin >> u >> v >> c;
		rGraf[u][v] = c;
	}
	
	fin.close();
	
	/*
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout << Graf[i][j] << " ";
		}
		cout << endl;
	}
	cout << "//////////////\n";
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout << rGraf[i][j] << " ";
		}
		cout << endl;
	}
	*/


	int flux_max = FluxMaxKarp(rGraf, V, E, 0, V - 1);
	
	ofstream fout(argv[2]);
	fout << flux_max;
	fout.close();

	delete[] rGraf;

	return 0;
}