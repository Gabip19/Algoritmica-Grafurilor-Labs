//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//ifstream fin("graf.txt");
//
//int mat[50][50], n, m;
//
//
//void citest_mat()
//{
//	int x, y;
//	fin >> n;
//	m = 0;
//	while (fin >> x >> y)
//	{
//		m++;
//		mat[x][m] = 1;
//		mat[y][m] = 1;
//	}
//}
//
//
//void afiseaza_mat()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			cout << mat[i][j] << " ";
//		cout << "\n";
//	}
//}
//
//
//int main()
//{
//	citest_mat();
//	afiseaza_mat();
//	return 0;
//}