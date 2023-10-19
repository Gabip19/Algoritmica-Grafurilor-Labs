#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

using namespace std;


vector<vector<int>> adj;
map<pair<int, int>, int> adj_map;


void print_ciclu_eulerian(vector<vector<int>>& adj, char* output)
{
	stack<int> circuit_curent;
	vector<int> circuit;
	
	int vf_curent = 0;
	circuit_curent.push(vf_curent);

	while (!circuit_curent.empty())
	{
		if (adj[vf_curent].size())
		{
			int vf_urmator = adj[vf_curent].back();
			adj[vf_curent].pop_back();
			
			if (adj_map[{vf_curent, vf_urmator}])
			{
				circuit_curent.push(vf_curent);
				adj_map[{vf_curent, vf_urmator}] = 0;
				vf_curent = vf_urmator;
			}
			else if (adj_map[{vf_urmator, vf_curent}])
			{
				circuit_curent.push(vf_curent);
				adj_map[{vf_urmator, vf_curent}] = 0;
				vf_curent = vf_urmator;
			}
		}
		else
		{
			circuit.push_back(vf_curent);

			vf_curent = circuit_curent.top();
			circuit_curent.pop();
		}
	}

	ofstream fout(output);
	for (int i = circuit.size() - 1; i >= 1; --i)
	{
		fout << circuit[i] << " ";
	}
	fout.close();
}


int main(int argc, char* argv[])
{
	int V, E;
	
	ifstream fin(argv[1]);
	fin >> V >> E;

	adj.resize(V);

	for (int i = 0; i < E; i++)
	{
		int x, y;
		fin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		
		adj_map[{x, y}] = 1;
	}
	fin.close();

	print_ciclu_eulerian(adj, argv[2]);

	return 0;
}