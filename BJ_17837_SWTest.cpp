//#include <iostream>
//#include <stack>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
////20.06.05 1시간 52분
//
//int N, K;
//int Array[14][14]; //13으로하면 idx가 12인 곳 까지 생기지만 nx,ny로 인해 넘어갈 가능성
//int dx[] = { 0, 1, -1, 0, 0 };
//int dy[] = { 0, 0, 0, -1, 1 };
//int dir_table[] = { 0, 2, 1, 4, 3 };
//int end_flag;
//
//struct point
//{
//	int x;
//	int y;
//	int dir;
//};
//
//vector<point> v;
//vector<int> map[13][13]; //idx만 저장
//
//void input()
//{
//	memset(Array, -1, sizeof(Array)); //범위 넘어가는거 체크 안하고 그냥 -1로 이용하기 위해
//
//	cin >> N >> K;
//	for (int i = 1; i < N + 1; i++)
//		for (int j = 1; j < N + 1; j++)
//			cin >> Array[i][j];
//
//	for (int i = 0; i < K; i++)
//	{
//		int x, y, dir;
//		cin >> y >> x >> dir;
//		v.push_back({ x, y, dir });
//		map[y][x].push_back(i);
//	}
//}
//
//void White(int X, int Y, int nx, int ny, int idx)
//{
//	queue<int> q;
//	if (map[Y][X].size() > 0)
//		for (int i = 0; i < map[Y][X].size(); i++)
//		{
//			if (map[Y][X][i] == idx)
//			{
//				for (int j = i; j < map[Y][X].size(); j++)
//				{
//					q.push(map[Y][X][j]);
//					map[Y][X].erase(map[Y][X].begin() + j);
//					j--;
//				}
//			}
//		}
//	while (!q.empty())
//	{
//		map[ny][nx].push_back(q.front());
//		q.pop();
//	}
//}
//
//void Red(int X, int Y, int nx, int ny, int idx)
//{
//	stack<int> stk;
//	if (map[Y][X].size() > 0)
//		for (int i = 0; i < map[Y][X].size(); i++)
//		{
//			if (map[Y][X][i] == idx)
//			{
//				for (int j = i; j < map[Y][X].size(); j++)
//				{
//					stk.push(map[Y][X][j]);
//					map[Y][X].erase(map[Y][X].begin() + j);
//					j--;
//				}
//			}
//		}
//	while (!stk.empty())
//	{
//		map[ny][nx].push_back(stk.top());
//		stk.pop();
//	}
//}
//
//void Hmove(int vidx)
//{
//	int X = v[vidx].x;
//	int Y = v[vidx].y;
//	int dir = v[vidx].dir;
//	int nx = X + dx[dir];
//	int ny = Y + dy[dir];
//
//	if (Array[ny][nx] == 0)
//		White(X, Y, nx, ny, vidx);
//	else if (Array[ny][nx] == 1)
//		Red(X, Y, nx, ny, vidx);
//	else
//	{
//		dir = dir_table[dir];
//		nx = X + dx[dir];
//		ny = Y + dy[dir];
//		v[vidx].dir = dir;
//
//		if (Array[ny][nx] == 0)
//			White(X, Y, nx, ny, vidx);
//		else if (Array[ny][nx] == 1)
//			Red(X, Y, nx, ny, vidx);
//	}
//}
//
//void setting()
//{
//	for (int i = 1; i < N + 1; i++)
//	{
//		for (int j = 1; j < N + 1; j++)
//		{
//			if (map[i][j].size() > 0)
//			{
//				if (map[i][j].size() >= 4)
//				{
//					end_flag = 1;
//					return;
//				}
//				for (int k = 0; k < map[i][j].size(); k++)
//				{
//					v[map[i][j][k]].x = j;
//					v[map[i][j][k]].y = i;
//				}
//			}
//		}
//	}
//}
//
//void solve()
//{
//	int T = 0;
//	while (1)
//	{
//		T++;
//		if (T > 1000)
//		{
//			T = -1;
//			break;
//		}
//
//		for (int i = 0; i < v.size(); i++)
//		{
//			Hmove(i);
//			setting();
//		}
//
//		if (end_flag) break;
//	}
//
//	cout << T;
//}
//
//int main()
//{
//	input();
//	solve();
//	return 0;
//}