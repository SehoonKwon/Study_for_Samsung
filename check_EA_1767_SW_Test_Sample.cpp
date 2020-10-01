//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int T, N;
//int Array[13][13] = { 0, };
//int Array2[13][13] = { 0, };
//int Direct[4];
//int dir[4];
//
//void check(int y, int x);
//int connect(int y, int x, int dir);
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> Array[i][j];
//
//	memcpy(Array2, Array, sizeof(Array));
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//		{
//			if (Array[i][j] == 1) check(i, j);
//		}
//
//	//for (int i = 0; i < N; i++)
//	//{
//	//	cout << "\n";
//	//	for (int j = 0; j < N; j++)
//	//		cout << Array2[i][j] << " ";
//	//}
//
//	int cnt = 0;
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			if (Array2[i][j] == 2) cnt++;
//
//	cout << cnt;
//
//	return 0;
//}
//
//int connect(int y, int x, int dir)
//{
//	if (dir == -1)
//	{
//		for (int i = 0; i < N; i++)
//			for (int j = 0; j < x; j++)
//			{
//				if (Array[i][j] == 1)
//					check(i, j);
//			}
//
//		//교차되는 선이 있는지 일단 검사해보고 있으면 종료, 없으면 진행. 미리 해봐야 나중에 긋다 만나도 여태 그은 라인 안지워도 됌
//		for (int i = 0; i < x; i++)
//			if (Array2[y][i] != 0) return 0;
//
//		for (int i = 0; i < x; i++)
//			Array2[y][i] = 2;
//	}
//
//	if (dir == 1)
//	{
//		//교차되는 선이 있는지 일단 검사해보고 있으면 종료, 없으면 진행. 미리 해봐야 나중에 긋다 만나도 여태 그은 라인 안지워도 됌
//		for (int i = x + 1; i < N; i++)
//			if (Array2[y][i] != 0) return 0;
//
//		for (int i = x + 1; i < N; i++)
//			Array2[y][i] = 2;
//	}
//
//	if (dir == 2)
//	{
//		//교차되는 선이 있는지 일단 검사해보고 있으면 종료, 없으면 진행. 미리 해봐야 나중에 긋다 만나도 여태 그은 라인 안지워도 됌
//		for (int i = 0; i < y; i++)
//			if (Array2[i][x] != 0) return 0;
//
//		for (int i = 0; i < y; i++)
//			Array2[i][x] = 2;
//	}
//
//	if (dir == -2)
//	{
//		//교차되는 선이 있는지 일단 검사해보고 있으면 종료, 없으면 진행. 미리 해봐야 나중에 긋다 만나도 여태 그은 라인 안지워도 됌
//		for (int i = y + 1; i < N; i++)
//			if (Array2[i][x] != 0) return 0;
//
//		for (int i = y + 1; i < N; i++)
//			Array2[i][x] = 2;
//	}
//
//	//성공하면 1 반환
//	return 1;
//}
//
//void check(int y, int x)
//{
//	if (y == 0 || y == N - 1 || x == 0 || x == N - 1) return;
//
//	int dxl, dxr, dyu, dyd;
//	dxl = x;
//	dxr = N - 1 - x;
//	dyu = y;
//	dyd = N - 1 - y;
//
//	//가장 최솟값의 길 찾기
//	Direct[0] = dxl;
//	Direct[1] = dxr;
//	Direct[2] = dyu;
//	Direct[3] = dyd;
//
//	sort(Direct, Direct + 4);
//
//	for (int i = 0; i < 4; i++)
//	{
//		if (Direct[i] == dxl) dir[i] = -1;
//		else if (Direct[i] == dxr) dir[i] = 1;
//		else if (Direct[i] == dyu) dir[i] = 2;
//		else if (Direct[i] == dyd) dir[i] = -2;
//	}
//
//	int flag = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		flag = connect(y, x, dir[i]);
//		if (flag == 1) return;
//	}
//
////	if (flag == 0) cout << "fail" << "\n";
//
//}