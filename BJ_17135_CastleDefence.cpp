//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//#define endl "\n"
//
//int N, M, D;
//int Array[17][17];
//int Array2[17][17];
//int Bvisit[17][17];
//int visit[17];
//int MAX = 0;
//int dx[] = { -1, 0, 1 }; //가장 왼쪽부터 없애므로 왼쪽, 가운데, 오른쪽 순서로 찾는순간 멈추게 하기
//int dy[] = { 0, -1, 0 };
//
//struct point
//{
//	int x;
//	int y;
//	int live;
//};
//
//struct point2
//{
//	int x;
//	int y;
//	int step;
//};
//
//vector<point> v, v2;
//
//void input()
//{
//	cin >> N >> M >> D;
//	for(int i = 0; i < N; i++)
//	{
//		for(int j = 0; j < M; j++)
//		{
//			cin >> Array[i][j];
//			if (Array[i][j] == 1) v.push_back({ j, i, 1 }); //병사일 경우 벡터에 저장
//		}
//	}
//
//	v2 = v;
//	memcpy(Array2, Array, sizeof(Array));
//}
//
//void move_map()
//{
//	// 맵을 0으로 초기화 한 다음 병사들 위치 한 칸씩 내리기
//	memset(Array, 0, sizeof(Array));
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i].live == 0)
//		{
//			v.erase(v.begin() + i);
//			continue;
//		}
//
//		else
//		{
//			v[i].y++;
//			if (v[i].y == N) v.erase(v.begin() + i); // 성에 닿으면 병사 삭제
//			else Array[v[i].y][v[i].x] = 1;
//		}
//	}
//}
//
//int check_map()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (Array[i][j] == 1) return 0;
//		}
//	}
//
//	return 1;
//}
//
//int shoot(int x, int y)
//{
//	Bvisit[y][x] = true;
//	queue<point2> q;
//	q.push({ x, y, 0 });
//
//	while (!q.empty())
//	{
//		int X = q.front().x;
//		int Y = q.front().y;
//		int step = q.front().step;
//		q.pop();
//
//		if (step == D)
//			continue;
//
//		for (int i = 0; i < 3; i++)
//		{
//			int nx = X + dx[i];
//			int ny = Y + dy[i];
//
//			if (nx > -1 && nx < M && ny > -1 && ny < N)
//			{
//				if (Array[ny][nx] == 0 && Bvisit[ny][nx] == false)
//				{
//					Bvisit[ny][nx] = true;
//					q.push({ nx, ny, step + 1 });
//				}
//				
//				else if (Array[ny][nx] == 1)
//				{
//					for (int i = 0; i < v.size(); i++)
//					{
//						if (v[i].x == nx && v[i].y == ny)
//						{
//							v[i].live = 0;
//							break;
//						}
//					}
//					return 1;
//				}
//			}
//		}
//	}
//
//	return 0;
//}
//
//int kill(int IDX[])
//{
//	int cnt = 0;
//
//	for (int i = 0; i < 3; i++)
//	{
//		memset(Bvisit, 0, sizeof(Bvisit));
//		shoot(IDX[i], N);
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i].live == 0)
//		{
//			v.erase(v.begin() + i);
//			cnt++;
//			i--;
//		}
//	}
//
//	return cnt;
//}
//
//int start()
//{
//	// 선택된 병사조합 맵에 생성
//	int idx[3];
//	int idx_cnt = 0;
//
//	for (int i = 0; i < M; i++)
//	{
//		if (visit[i] == true)
//		{
//			idx[idx_cnt] = i;
//			idx_cnt++;
//			Array[N][i] = 2;
//			if (idx_cnt == 3) break;
//		}
//	}
//
//	int cnt = 0;
//
//	while (1)
//	{
//		cnt += kill(idx);
//		move_map();
//		int ch = check_map();
//		if (ch == 1)
//			break;
//	}
//
//	return cnt;
//}
//
//void DFS(int idx, int cnt)
//{
//	if (cnt == 3)
//	{
//		v = v2;
//		memcpy(Array, Array2, sizeof(Array2));
//		int kill_cnt = start();
//		MAX = max(MAX, kill_cnt);
////		cout << MAX << endl;
//		return;
//	}
//
//	for (int i = idx; i < M; i++)
//	{
//		if (visit[i] == true) continue;
//
//		visit[i] = true;
//		DFS(i + 1, cnt + 1);
//		visit[i] = false;
//	}
//}
//
//void solve()
//{
//	int cnt = 0;
//	
//	for (int i = 0; i < M - 2; i++)
//	{
//		DFS(i, 0); 
//	}
//
//	cout << MAX << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	input();
//
//	solve();
//
//	return 0;
//}