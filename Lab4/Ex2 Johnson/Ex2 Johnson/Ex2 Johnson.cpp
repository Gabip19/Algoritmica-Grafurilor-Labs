#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> int_pair;


struct arc
{
	int surs;
	int dest;
	int pond;
};


class Graf
{

public:

	int V, E;
	vector<arc> arce;
	vector<int_pair>* adj;
	char* input;
	char* output;

	Graf(char* input, char* output);
	~Graf();
	void citeste_graf();
	//vector<int> bellman_ford(int s);

	void jhonson_alg();
};


Graf::Graf(char* input, char* output)
{
	this->input = input;
	this->output = output;
	this->V = 0;
	this->E = 0;
	this->adj = nullptr;
}


Graf::~Graf()
{
	delete[] this->adj;
}


void Graf::citeste_graf()
{
	arc arc_nou;
	int V, E;

	ifstream fin(input);
	fin >> V >> E;
	
	this->V = V;
	this->E = E;

	adj = new vector<int_pair>[V + 1];

	for (int i = 0; i < E; i++)
	{
		fin >> arc_nou.surs;
		fin >> arc_nou.dest;
		fin >> arc_nou.pond;
		//cout << arc_nou.surs << " " << arc_nou.dest << " " << arc_nou.pond << endl;
		arce.push_back(arc_nou);
		adj[arc_nou.surs].push_back(make_pair(arc_nou.dest, arc_nou.pond));
	}

	fin.close();
}


vector<int> bellman_ford(int V, vector<arc> arce, int s)
{
	vector<int> dist(V + 1, INT_MAX);
	dist[s] = 0;

	for (int i = 1; i < V; i++)
	{
		for (auto& arc_ : arce)
		{
			int u = arc_.surs;
			int v = arc_.dest;
			int w = arc_.pond;
			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	for (auto& arc_ : arce)
	{
		int u = arc_.surs;
		int v = arc_.dest;
		int w = arc_.pond;
		if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
		{
			return {};
		}
	}

	/*for (int i = 0; i < V; i++)
		cout << i << " -> " << dist[i] << " " << endl;*/
	return dist;
}


vector<int> dijkstra(int V, vector<int_pair>* adj, int s)
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

		//list<int_pair>::iterator it;
		for (auto& pereche : adj[u])
		{
			int v = pereche.first;
			int w = pereche.second;

			//cout << PQ.size() << " ";

			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parinte[v] = u;
				PQ.push(make_pair(dist[v], v));
			}
		}
	}

	return dist;
}


void Graf::jhonson_alg()
{
	// Adaugam noul nod si muchiile sale
	vector<arc> arce_nou = this->arce;

	for (int i = 0; i < V; i++)
	{
		arc arc_nou;
		arc_nou.surs = V;
		arc_nou.dest = i;
		arc_nou.pond = 0;
		arce_nou.push_back(arc_nou);
	}

	// BELLMAN_FORD pe noul graf pt determinare ponderi noi
	vector<int> pond_noi = bellman_ford(V + 1, arce_nou, V);

	ofstream fout(output);

	// Daca avem circuite de pondere negativa
	if (pond_noi.size() == 0)
	{
		fout << -1;
		fout.close();
		return;
	}

	// Calcul ponderi noi
	for (int i = 0; i < V; i++)
	{
		for (auto& pereche : adj[i])
		{
			pereche.second = pereche.second + pond_noi[i] - pond_noi[pereche.first];
			fout << i << " " << pereche.first << " " << pereche.second << "\n";
		}
	}

	// Dijkstra pentru fiecare nod
	for (int i = 0; i < this->V; i++)
	{
		vector<int> dist = dijkstra(V, adj, i);
		for (int j = 0; j < this->V; j++)
		{
			if (dist[j] != INT_MAX)
			{
				dist[j] = dist[j] - pond_noi[i] + pond_noi[j];
				fout << dist[j] << " ";
			}
			else
				fout << "INF ";
		}
		fout << "\n";
	}
}


int main(int argc, char* argv[])
{
	Graf g(argv[1], argv[2]);
	g.citeste_graf();
	g.jhonson_alg();
	//vector<arc> asd = g.arce;
	//vector<int> a = bellman_ford(g.V, asd, 0);
	return 0;
}