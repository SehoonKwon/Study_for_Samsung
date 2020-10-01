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
//	//역순으로 해야 경계부분 처리가능
//	for (int i = y-1; i > 0; i--)
//		Array[i][x] = Array[i-1][x];
//
//	//바뀐 공기청정기 값 다시 -1로 조정 
//	Array[y][x] = -1;
//
//	for (int i = 0; i < C; i++)
//		Array[0][i] = Array[0][i + 1];
//
//	for (int i = 0; i < y; i++)
//		Array[i][C - 1] = Array[i + 1][C - 1];
//
//	for (int i = C - 1; i > x; i--) // i > x1 하면 공기청정기 좌표인 -1이 당겨지므로 한 칸 더 앞까지 
//	{
//		Array[y][i] = Array[y][i - 1];
//		if (Array[y][i] == -1) Array[y][i] = 0;
//	}
//}
//
////아래쪽
//void clean2()
//{
//	int x = cleaner[1].x;
//	int y = cleaner[1].y;
//
//	//역순으로 해야 경계부분 처리가능
//	for (int i = y; i < R; i++)
//		Array[i][x] = Array[i + 1][x];
//
//	//바뀐 공기청정기 값 다시 -1로 조정 
//	Array[y][x] = -1;
//
//	for (int i = 0; i < C; i++)
//		Array[R-1][i] = Array[R-1][i + 1];
//
//	for (int i = R-1; i > y; i--)
//		Array[i][C - 1] = Array[i - 1][C - 1];
//
//	for (int i = C - 1; i > x; i--) // i > x1 하면 공기청정기 좌표인 -1이 당겨지므로 한 칸 더 앞까지 
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
//			if (Array[i][j] == -1) cleaner.push_back({ j, i }); //공기청정기 위치 저장
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