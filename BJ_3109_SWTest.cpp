//#include <iostream>
//#include <queue>
//using namespace std;
//
//int N, K, L;
//int Array[101][101];
//int visit[101][101];
//char curve[10001];
//int dir_table[5][2] = { { 0, 0 },{ 3, 4 },{ 4, 3 },{ 2, 1 },{ 1, 2 } };
//
//struct point
//{
//	int x;
//	int y;
//};
//
//queue<point> tail;
//
//void input()
//{
//	cin >> N;
//	cin >> K;
//
//	for (int i = 0; i < K; i++)
//	{
//		int X, Y;
//		cin >> Y >> X;
//		Array[Y][X] = 1;
//	}
//
//	cin >> L;
//	for (int i = 0; i < L; i++)
//	{
//		int X;
//		char D;
//		cin >> X >> D;
//		curve[X] = D;
//	}
//}
//
//int change_dir(int cur, char X)
//{
//	int A;
//	if (X == 'L') A = 0;
//	else A = 1;
//
//	return dir_table[cur][A];
//}
//
//
//void solve()
//{
//	int dir = 4; //1 2 3 4 = ªÛ«œ¡¬øÏ
//	int hx = 1, hy = 1;
//	tail.push({ hx, hy });
//	visit[hy][hx] = 1; //πÏ¿« ∏ˆ
//
//	int t = 0, flag = 0;
//	while (1)
//	{
//		//πÏ ¿Ãµø -> Ω√∞£√  ∫∏∞Ì πÊ«‚¿¸»Ø
//		switch (dir)
//		{
//		case 1:
//			hy--;
//			if (visit[hy][hx] == true || hy < 1)
//			{
//				flag = 1;
//				break;
//			}
//
//			visit[hy][hx] = true;
//			tail.push({ hx, hy });
//			if (Array[hy][hx] == 0)
//			{
//				visit[tail.front().y][tail.front().x] = false;
//				tail.pop();
//			}
//			else Array[hy][hx] = 0;
//			break;
//
//		case 2:
//			hy++;
//			if (visit[hy][hx] == true || hy > N)
//			{
//				flag = 1;
//				break;
//			}
//
//			visit[hy][hx] = true;
//			tail.push({ hx, hy });
//			if (Array[hy][hx] == 0)
//			{
//				visit[tail.front().y][tail.front().x] = false;
//				tail.pop();
//			}
//			else Array[hy][hx] = 0;
//			break;
//
//		case 3:
//			hx--;
//			if (visit[hy][hx] == true || hx < 1)
//			{
//				flag = 1;
//				break;
//			}
//
//			visit[hy][hx] = true;
//			tail.push({ hx, hy });
//			if (Array[hy][hx] == 0)
//			{
//				visit[tail.front().y][tail.front().x] = false;
//				tail.pop();
//			}
//			else Array[hy][hx] = 0;
//			break;
//
//		case 4:
//			hx++;
//			if (visit[hy][hx] == true || hx > N)
//			{
//				flag = 1;
//				break;
//			}
//
//			visit[hy][hx] = true;
//			tail.push({ hx, hy });
//			if (Array[hy][hx] == 0)
//			{
//				visit[tail.front().y][tail.front().x] = false;
//				tail.pop();
//			}
//			else Array[hy][hx] = 0;
//			break;
//		default:
//			break;
//		}
//
//		t++;
//		if (flag) break;
//
//		if (curve[t] != 0)
//			dir = change_dir(dir, curve[t]);
//	}
//
//	cout << t << "\n";
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	input();
//	solve();
//	return 0;
//}