//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//
////구슬 1개만 하는거면 쉽게 짜겠는데 2개를 동시에 움직이면서 모두 들어가는 경우 예외처리 하는 부분이 난이도 엄~~~~청 높임. 
//
//int N, M;
//int rx, ry, bx, by;
//char Array[11][11];
//int visit[11][11][11][11];
//int dx[] = { 0,0,-1,1 };
//int dy[] = { -1,1,0,0 };
//
//struct point
//{
//	int x;
//	int y;
//	int bx;
//	int by;
//	int step;
//};
//
//queue<point> q;
//
//int BFS()
//{
//	visit[ry][rx][by][bx] = true;
//	q.push({ rx,ry,bx,by,0 });
//
//
//	while (!q.empty())
//	{
//		int X = q.front().x;
//		int Y = q.front().y;
//		int BX = q.front().bx;
//		int BY = q.front().by;
//		int step = q.front().step;
//		int Bstep = step;
//		q.pop();
//
//		if (step >= 10)
//		{
//			while (!q.empty()) q.pop();
//			return -1;
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = X + dx[i];
//			int ny = Y + dy[i];
//			int nbx = BX + dx[i];
//			int nby = BY + dy[i];
//
//			int goal = 0;
//			int goal_b = 0;
//			//빨간 공 이동
//			while (Array[ny][nx] != '#' && (nx > -1 && nx<M && ny > -1 && ny < N))
//			{
//				if (Array[ny][nx] == 'O')
//				{
//					goal = 1;
//					break;
//				}
//
//				nx += dx[i];
//				ny += dy[i];
//			}
//
//			//파란 공 이동
//			while (Array[nby][nbx] != '#' && (nbx >-1 && nbx < M && nby > -1 && nby <N))
//			{
//				if (Array[nby][nbx] == 'O')
//				{
//					goal_b = 1;
//					break;
//				}
//
//				nbx += dx[i];
//				nby += dy[i];
//			}
//
//			nx -= dx[i];
//			ny -= dy[i];
//			nbx -= dx[i];
//			nby -= dy[i];
//
//			if (goal_b == 1 && goal != 1) continue;
//
//			if (goal == 1)
//			{
//				if (goal_b == 1)
//					continue;
//
//				else
//				{
//					while (!q.empty()) q.pop();
//					return step+1;
//				}
//			}
//
//			//경우 1 - 윗방향 + 일직선 상에 있는경우
//			if (i == 0 && (nx == nbx && ny == nby))
//			{
//				if (Y < BY) nby++; //빨간 공이 파란 공 위의 경우
//				if (Y > BY) ny++; // 빨간 공이 파란 공 아래인 경우
//			}
//
//			//경우 2 - 아랫방향 + 일직선 상
//			if (i == 1 && (nx == nbx && ny == nby))
//			{
//				if (Y < BY) ny--;
//				if (Y > BY) nby--;
//			}
//
//			//경우 3 - 왼쪽 방향 + 일직선
//			if (i == 2 && (nx == nbx && ny == nby))
//			{
//				if (X < BX) nbx++;
//				if (X > BX) nx++;
//			}
//
//			//경우 4 - 오른쪽 방향 + 일직선
//			if (i == 3 && (nx == nbx && ny == nby))
//			{
//				if (X < BX) nx--;
//				if (X > BX) nbx--;
//			}
//
//			//			if ((nx == X && ny == Y) || (nbx==BX && nby==BY)) continue;
//			if (visit[ny][nx][nby][nbx] == 0)
//			{
//				visit[ny][nx][nby][nbx] = true;
//				q.push({ nx,ny,nbx,nby,step + 1 });
//			}
//		}
//	}
//
//	return -1;
//}
//
//int main()
//{
//	memset(visit, 0, sizeof(visit));
//
//	cin >> N >> M;
//
//	for(int i=0; i<N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			cin >> Array[i][j];
//			if (Array[i][j] == 'R')
//			{
//				rx = j;
//				ry = i;
//			}
//
//			if (Array[i][j] == 'B')
//			{
//				bx = j;
//				by = i;
//			}
//		}
//
//	int ans = BFS();
//
//	cout << ans;
//
//	return 0;
//}