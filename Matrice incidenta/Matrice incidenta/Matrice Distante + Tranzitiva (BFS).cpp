//#include <iostream>
//#include <fstream>
//#include <queue>
//
//using namespace std;
//
//ifstream fin("graf.txt");
//
//int mat[50][50], n, mat_dist[50][50];
//
//
//void citest_mat()
//{
//	int x, y;
//	fin >> n;
//	while (fin >> x >> y)
//	{
//		mat[x][y] = 1;
//		mat[y][x] = 1;
//	}
//}
//
//
//void afiseaza_mat(int a[][50])
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			cout << a[i][j] << " ";
//		cout << "\n";
//	}
//}
//
//
//struct Nod
//{
//	int numar;
//	int distanta;
//	bool vizitat;
//} nod_list[50];
//
//
//void BFS(Nod& s)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		nod_list[i].numar = i;
//		nod_list[i].distanta = -1;
//		nod_list[i].vizitat = false;
//	}
//
//	s.distanta = 0;
//	s.vizitat = true;
//	queue<Nod> Q;
//	Q.push(s);
//
//	while (!Q.empty())
//	{
//		Nod& v = Q.front();
//		
//		for (int i = 1; i <= n; i++)
//			if (mat[i][v.numar] == 1)
//			{
//				Nod& u = nod_list[i];
//				if (u.vizitat == false)
//				{
//					u.vizitat = true;
//					u.distanta = v.distanta + 1;
//					Q.push(u);
//				}
//			}
//
//		Q.pop();
//	}
//}
//
//
//void constr_mat()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		BFS(nod_list[i]);
//		for (int j = 1; j <= n; j++)
//			mat_dist[i][j] = nod_list[j].distanta;
//	}
//}
//
//
//// ROY FLOYD
////void construct_mat()
////{
////	for (int k = 1; k <= n; k++)
////		for (int i = 1; i <= n; i++)
////			for (int j = 1; j <= n; j++)
////				mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
////}
//
//
//int main()
//{
//	citest_mat();
//	constr_mat();
//	afiseaza_mat(mat_dist);
//	return 0;
//}