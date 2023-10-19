#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int V, E;
vector<vector<int>> capacitate;
vector<int> inaltime, exces, curent;
deque<int> vf_cu_exces;


void inaltare(int u)
{
	int d = INT_MAX;
	for (int i = 0; i < V; i++)
	{
		if (capacitate[u][i] > 0)
			d = min(inaltime[i], d);
	}
	if (d < INT_MAX)
	{
		inaltime[u] = d + 1;
	}
}


void pompeaza(int u, int v)
{
	int d = min(capacitate[u][v], exces[u]);
	capacitate[u][v] -= d;
	capacitate[v][u] += d;
	exces[u] -= d;
	exces[v] += d;

	if (d && exces[v] == d)
		vf_cu_exces.push_back(v);
}


void descarca(int u)
{
	while (exces[u] > 0)
	{
		int v = curent[u];
		if (v >= V)
		{
			inaltare(u);
			curent[u] = 0;
		}
		else if (capacitate[u][v] > 0 && inaltime[u] > inaltime[v])
			pompeaza(u, v);
		else
			curent[u]++;
	}
}


void init_preflux(int s)
{
	inaltime.assign(V, 0);
	exces.assign(V, 0);
	curent.assign(V, 0);

	inaltime[s] = V;
	exces[s] = INT_MAX;

	for (int i = 0; i < V; ++i)
	{
		if (capacitate[s][i] > 0)
			pompeaza(s, i);
	}
}


int PompareTopologica(int s, int t)
{
	init_preflux(s);

	while (!vf_cu_exces.empty())
	{
		int u = vf_cu_exces.front();
		vf_cu_exces.pop_front();
		if (u != s && u != t)
			descarca(u);
	}

	return exces[t];
}

// 23 -9
int main(int argc, char* argv[])
{
	//ifstream fin("test.txt");
	ifstream fin(argv[1]);

	fin >> V >> E;
	capacitate.assign(V, vector<int>(V, 0));

	for (int i = 0; i < E; ++i)
	{
		int u, v, c;
		fin >> u >> v >> c;
		capacitate[u][v] = c;
	}
	fin.close();
	
	int flux_max = PompareTopologica(0, V - 1);

	ofstream fout(argv[2]);
	//cout << flux_max;
	fout << flux_max;
	fout.close();

	return 0;
}