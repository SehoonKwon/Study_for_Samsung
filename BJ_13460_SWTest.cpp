//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//
////���� 1���� �ϴ°Ÿ� ���� ¥�ڴµ� 2���� ���ÿ� �����̸鼭 ��� ���� ��� ����ó�� �ϴ� �κ��� ���̵� ��~~~~û ����. 
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
//			//���� �� �̵�
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
//			//�Ķ� �� �̵�
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
//			//��� 1 - ������ + ������ �� �ִ°��
//			if (i == 0 && (nx == nbx && ny == nby))
//			{
//				if (Y < BY) nby++; //���� ���� �Ķ� �� ���� ���
//				if (Y > BY) ny++; // ���� ���� �Ķ� �� �Ʒ��� ���
//			}
//
//			//��� 2 - �Ʒ����� + ������ ��
//			if (i == 1 && (nx == nbx && ny == nby))
//			{
//				if (Y < BY) ny--;
//				if (Y > BY) nby--;
//			}
//
//			//��� 3 - ���� ���� + ������
//			if (i == 2 && (nx == nbx && ny == nby))
//			{
//				if (X < BX) nbx++;
//				if (X > BX) nx++;
//			}
//
//			//��� 4 - ������ ���� + ������
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