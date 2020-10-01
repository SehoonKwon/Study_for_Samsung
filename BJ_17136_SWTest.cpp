//#include <iostream>
//#include <vector>
//using namespace std;
//
////최신 색종이 붙이기. 코드가 더 간결해져서 업뎃, 전에는 230줄이 넘어갔음(switch활용 + 쓸데없는 flag 안쓰기)
//
//int Array[11][11];
//int visit[11][11];
//int MIN = 987654321;
//
//struct point
//{
//	int x;
//	int y;
//};
//
//vector<point> v;
//
//void input()
//{
//	for (int i = 0; i<10; i++)
//		for (int j = 0; j < 10; j++)
//		{
//			cin >> Array[i][j];
//			if (Array[i][j] == 1)
//				v.push_back({ j, i });
//		}
//}
//
//int check(int x, int y)
//{
//	for (int k = 1; k < 6; k++)
//	{
//		for (int i = y; i < y + k; i++)
//		{
//			if (i < 0 || i >= 10) return k - 1; //k번째 사이즈는 안된다 => 그 전까진 가능하다는 소리
//			for (int j = x; j < x + k; j++)
//			{
//				if (j < 0 || j >= 10) return k - 1;
//				if (Array[i][j] == 0 || visit[i][j] == 1) return k - 1;
//			}
//		}
//	}
//
//	return 5;
//}
//
//void Vcheck(int x, int y, int c, int tf)
//{
//	for (int i = y; i < y + c; i++)
//		for (int j = x; j < x + c; j++)
//			visit[i][j] = tf;
//}
//
//void DFS(int idx, int cnt1, int cnt2, int cnt3, int cnt4, int cnt5, int Tcnt)
//{
//	if (Tcnt > v.size()) return;
//	if (cnt1 > 5 || cnt2 > 5 || cnt3 > 5 || cnt4 > 5 || cnt5 > 5) return;
//
//	if (Tcnt == v.size())
//	{
//		int sum = cnt1 + cnt2 + cnt3 + cnt4 + cnt5;
//		if (sum < MIN) MIN = sum;
//		return;
//	}
//
//	int X = v[idx].x, Y = v[idx].y;
//
//	if (visit[Y][X] == true) DFS(idx + 1, cnt1, cnt2, cnt3, cnt4, cnt5, Tcnt);
//
//	int sz = check(X, Y);
//
//	//switch에서 break 안하면 밑에 케이스로 이동하는 것을 이용
//	switch (sz)
//	{
//	case 5:
//		Vcheck(X, Y, 5, 1);
//		DFS(idx + 1, cnt1, cnt2, cnt3, cnt4, cnt5 + 1, Tcnt + 25);
//		Vcheck(X, Y, 5, 0);
//	case 4:
//		Vcheck(X, Y, 4, 1);
//		DFS(idx + 1, cnt1, cnt2, cnt3, cnt4 + 1, cnt5, Tcnt + 16);
//		Vcheck(X, Y, 4, 0);
//	case 3:
//		Vcheck(X, Y, 3, 1);
//		DFS(idx + 1, cnt1, cnt2, cnt3 + 1, cnt4, cnt5, Tcnt + 9);
//		Vcheck(X, Y, 3, 0);
//	case 2:
//		Vcheck(X, Y, 2, 1);
//		DFS(idx + 1, cnt1, cnt2 + 1, cnt3, cnt4, cnt5, Tcnt + 4);
//		Vcheck(X, Y, 2, 0);
//	case 1:
//		Vcheck(X, Y, 1, 1);
//		DFS(idx + 1, cnt1 + 1, cnt2, cnt3, cnt4, cnt5, Tcnt + 1);
//		Vcheck(X, Y, 1, 0);
//		break;
//	default:
//		break;
//	}
//}
//
//void solve()
//{
//	DFS(0, 0, 0, 0, 0, 0, 0);
//
//	if (MIN == 987654321) MIN = -1;
//	cout << MIN << endl;
//}
//
//int main()
//{
//	input();
//	solve();
//	return 0;
//}