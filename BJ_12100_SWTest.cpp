//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define endl "\n"
//
//int N;
//int MAX = 0;
//int Array[21][21];
//
//void input()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> Array[i][j];
//}
//
//void move(int dir)
//{
//	//»óÇÏÁÂ¿ì
//	if (dir == 0)
//	{
//		for (int i = 0; i < N; i++)
//			for (int j = 0; j < N; j++)
//			{
//				if (Array[i][j] == 0)
//				{
//					for (int k = i; k < N; k++)
//					{
//						if (Array[k][j] != 0) Array[i][j] = Array[k][j];
//						break;
//					}
//				}
//			}
//	}
//
//	if (dir == 1)
//	{
//		for (int i = N -1; i > -1; i--)
//			for (int j = N -1; j > -1; j--)
//			{
//				if (Array[i][j] == 0)
//				{
//					for (int k = i; k > -1; k--)
//					{
//						if (Array[k][j] != 0) Array[i][j] = Array[k][j];
//						break;
//					}
//				}
//			}
//	}
//
//	if (dir == 2)
//	{
//		for (int i = 0; i < N; i++)
//			for (int j = 0; j < N; j++)
//			{
//				if (Array[i][j] == 0)
//				{
//					for (int k = j; k < N; k++)
//					{
//						if (Array[k][j] != 0) Array[i][j] = Array[k][j];
//						break;
//					}
//				}
//			}
//	}
//
//	if (dir == 3)
//	{
//		for (int i = 0; i < N; i++)
//			for (int j = N -1; j > -1; j--)
//			{
//				if (Array[i][j] == 0)
//				{
//					for (int k = j; k > -1; k--)
//					{
//						if (Array[k][j] != 0) Array[i][j] = Array[k][j];
//						break;
//					}
//				}
//			}
//	}
//}
//
//void DFS(int dir, int cnt)
//{
//	if (cnt == 5)
//	{
//		for (int i = 0; i < N; i++)
//			for (int j = 0; j < N; j++)
//				if (Array[i][j] != 0) MAX = max(MAX, Array[i][j]);
//
//		return;
//	}
//
//	move(dir);
//}
//
//void solve()
//{
//	DFS(0, 0);
//
//	cout << MAX << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	return 0;
//}