//#include <iostream>
//#include <fstream>
//
//using namespace std;
//ifstream fin("floyd.txt");
//
//int mat[100][100], n;
//
//void citire_mat()
//{
//	fin >> n;
//	
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			if (i == j)
//			{
//				mat[i][j] = 0;
//			}
//			else
//			{
//				mat[i][j] = INT_MAX;
//			}
//	
//	int x, y, w;
//	while (fin >> x >> y >> w)
//	{
//		mat[x][y] = w;
//	}
//}
//
//void floyd_warshall()
//{
//	for (int k = 1; k <= n; k++)
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//			{
//				if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX)
//				{
//					if (mat[i][j] > mat[i][k] + mat[k][j])
//						mat[i][j] = mat[i][k] + mat[k][j];
//				}
//			}
//}
//
//void afis_mat()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			cout << mat[i][j] << " ";
//		cout << "\n";
//	}
//}
//
//int main()
//{
//	citire_mat();
//	floyd_warshall();
//	afis_mat();
//	return 0;
//}