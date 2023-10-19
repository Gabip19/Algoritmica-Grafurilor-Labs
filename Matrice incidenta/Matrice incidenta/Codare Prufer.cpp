//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//
//vector<int> codare_prufer(const vector<int>& parinte, vector<int>& grade, int radacina)
//{
//	priority_queue< int, vector<int>, greater<int> > Q;
//	vector<int> cod;
//
//	for (int i = 0; i < parinte.size(); i++)
//	{
//		if (grade[i] == 1 && i != radacina)
//			Q.push(i);
//	}
//
//	while (grade[radacina] != 0)
//	{
//		int x = Q.top();
//		Q.pop();
//		cod.push_back(parinte[x]);
//		grade[parinte[x]]--;
//
//		if (grade[parinte[x]] == 1 && parinte[x] != radacina)
//			Q.push(parinte[x]);
//	}
//
//	return cod;
//
//	/*int ptr = -1;
//	int i = 0;
//	while (ptr == -1)
//	{
//		if (grade[i] == 1 && i != radacina)
//			ptr = i;
//		++i;
//	}
//
//	int leaf = ptr;
//	for (int i = 0; i < parinte.size() - 2; i++)
//	{
//		int pp = parinte[leaf];
//		cod.push_back(pp);
//		grade[pp]--;
//
//		if (grade[pp] == 1 && pp < ptr && pp != radacina)
//			leaf = pp;
//		else
//		{
//			ptr++;
//			while (grade[ptr] != 1)
//			{
//				ptr++;
//				if (ptr == radacina)
//					ptr++;
//			}
//			leaf = ptr;
//		}
//	}
//	cod.push_back(radacina);
//
//	return cod;*/
//}
//
//
//int main(int argc, char* argv[])
//{
//	int n, r = 0;
//
//	ifstream fin(argv[1]);
//	ofstream fout(argv[2]);
//
//	fin >> n;
//
//	vector<int> parinte(n);
//	vector<int> grade(n, 0);
//
//	for (int i = 0; i < n; i++)
//	{
//		int nod;
//		fin >> nod;
//		if (nod != -1)
//		{
//			parinte[i] = nod;
//			grade[nod]++;
//			grade[i]++;
//		}
//		else
//			r = i;
//	}
//
//	const vector<int> cod_prufer = codare_prufer(parinte, grade, r);
//
//	fout << cod_prufer.size() << "\n";
//	for (int i = 0; i < cod_prufer.size(); ++i)
//		fout << cod_prufer[i] << " ";
//
//	fin.close();
//	fout.close();
//	return 0;
//}