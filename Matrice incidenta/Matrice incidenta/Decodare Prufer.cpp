//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <deque>
//#include <set>
//
//using namespace std;
//
//const vector<int> decodare_prufer(deque<int>& K, int n)
//{
//	// n = nr elemente in K
//	vector<int> parinte(n + 1, -1);
//	vector<int> aparitii(n + 1, 0);
//	set<int> minime;
//
//	for (int el : K)
//	{
//		aparitii[el]++;
//	}
//
//	for (int i = 0; i <= n; i++)
//	{
//		if (aparitii[i] == 0)
//			minime.insert(i);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		int x = K.front();
//		K.pop_front();
//		aparitii[x]--;
//
//		int y = *minime.begin();
//		minime.erase(minime.begin());
//
//		parinte[y] = x;
//
//		K.push_back(y);
//		aparitii[y]++;
//
//		if (aparitii[x] == 0)
//			minime.insert(x);
//	}
//
//	return parinte;
//
//	/*
//	* vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
//	int n = code.size() + 2;
//	vector<int> degree(n, 1);
//	for (int i : code)
//		degree[i]++;
//
//	int ptr = 0;
//	while (degree[ptr] != 1)
//		ptr++;
//	int leaf = ptr;
//
//	vector<pair<int, int>> edges;
//	for (int v : code) {
//		edges.emplace_back(leaf, v);
//		if (--degree[v] == 1 && v < ptr) {
//			leaf = v;
//		} else {
//			ptr++;
//			while (degree[ptr] != 1)
//				ptr++;
//			leaf = ptr;
//		}
//	}
//	edges.emplace_back(leaf, n-1);
//	return edges;
//	}
//	*/
//}
//
//vector<int> pruefer_decode(const vector<int>& code)
//{
//	int n = code.size() + 1;
//	vector<int> degree(n, 1);
//
//	for (int i : code)
//		degree[i]++;
//
//	int ptr = 0;
//	while (degree[ptr] != 1)
//		ptr++;
//	int leaf = ptr;
//
//	vector<int> parent(n, -1);
//
//	for (int v : code)
//	{
//		parent[leaf] = v;
//		if (--degree[v] == 1 && v < ptr)
//		{
//			leaf = v;
//		}
//		else
//		{
//			ptr++;
//			while (degree[ptr] != 1)
//				ptr++;
//			leaf = ptr;
//		}
//	}
//	return parent;
//}
//
//int main(int argc, char* argv[])
//{
//	int n, x;
//	deque<int> K;
//	vector<int> M;
//
//	ifstream fin(argv[1]);
//	fin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		fin >> x;
//		K.push_back(x);
//		M.push_back(x);
//	}
//
//	const vector<int> p_graf = decodare_prufer(K, n);
//
//	ofstream fout(argv[2]);
//	//for (int i = 0; i < p_graf.size(); i++)
//	//	fout << p_graf[i] << " ";
//
//	vector<int> a = pruefer_decode(M);
//
//	fout << a.size() << "\n";
//	for (int i = 0; i <= n; i++)
//		fout << a[i] << " ";
//
//	fin.close();
//	fout.close();
//	return 0;
//}