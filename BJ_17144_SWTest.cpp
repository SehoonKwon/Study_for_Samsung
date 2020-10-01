//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//#define endl "\n"
//
//int R, C, T;
//int Array[51][51];
//int temp[51][51];
//int dx[] = { 0,0,-1,1 };
//int dy[] = { 1,-1,0,0 };
//
//struct point
//{
//	int x;
//	int y;
//};
//
//vector<point> cleaner;
//
//void spread()
//{
//	memcpy(temp, Array, sizeof(Array));
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			if (Array[i][j] != 0)
//			{
//				int d = Array[i][j] / 5;
//
//				for (int k = 0; k < 4; k++)
//				{
//					int nx = j + dx[k];
//					int ny = i + dy[k];
//
//					if (nx > -1 && nx < C && ny > -1 && ny < R)
//					{
//						if (Array[ny][nx] == -1) continue;
//						else
//						{
//							temp[ny][nx] += d;
//							temp[i][j] -= d;
//						}
//					}
//				}
//			}
//		}
//	}
//
//	memcpy(Array, temp, sizeof(temp));
//}
//
//void clean()
//{
//	int x = cleaner[0].x;
//	int y = cleaner[0].y;
//
//	//�������� �ؾ� ���κ� ó������
//	for (int i = y-1; i > 0; i--)
//		Array[i][x] = Array[i-1][x];
//
//	//�ٲ� ����û���� �� �ٽ� -1�� ���� 
//	Array[y][x] = -1;
//
//	for (int i = 0; i < C; i++)
//		Array[0][i] = Array[0][i + 1];
//
//	for (int i = 0; i < y; i++)
//		Array[i][C - 1] = Array[i + 1][C - 1];
//
//	for (int i = C - 1; i > x; i--) // i > x1 �ϸ� ����û���� ��ǥ�� -1�� ������Ƿ� �� ĭ �� �ձ��� 
//	{
//		Array[y][i] = Array[y][i - 1];
//		if (Array[y][i] == -1) Array[y][i] = 0;
//	}
//}
//
////�Ʒ���
//void clean2()
//{
//	int x = cleaner[1].x;
//	int y = cleaner[1].y;
//
//	//�������� �ؾ� ���κ� ó������
//	for (int i = y; i < R; i++)
//		Array[i][x] = Array[i + 1][x];
//
//	//�ٲ� ����û���� �� �ٽ� -1�� ���� 
//	Array[y][x] = -1;
//
//	for (int i = 0; i < C; i++)
//		Array[R-1][i] = Array[R-1][i + 1];
//
//	for (int i = R-1; i > y; i--)
//		Array[i][C - 1] = Array[i - 1][C - 1];
//
//	for (int i = C - 1; i > x; i--) // i > x1 �ϸ� ����û���� ��ǥ�� -1�� ������Ƿ� �� ĭ �� �ձ��� 
//	{
//		Array[y][i] = Array[y][i - 1];
//		if (Array[y][i] == -1) Array[y][i] = 0;
//	}
//}
//
//int main()
//{
//	cin >> R >> C >> T;
//
//	for (int i = 0; i < R; i++)
//		for (int j = 0; j < C; j++)
//		{
//			cin >> Array[i][j];
//			if (Array[i][j] == -1) cleaner.push_back({ j, i }); //����û���� ��ġ ����
//		}
//
//	for (int i = 0; i < T; i++)
//	{
//		spread();
//		clean();
//		clean2();
//	}
//
//	int ans = 0;
//	for(int i=0; i<R; i++)
//		for (int j = 0; j < C; j++)
//			if (Array[i][j] != -1) ans += Array[i][j];
//
//	cout << ans;
//
//	return 0;
//}