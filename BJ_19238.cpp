#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, G;
int Array[21][21];
int visit[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int tx, ty;

struct point
{
	int Sx;
	int Sy;
	int Dx;
	int Dy;
	int idx;
	int state;
};

struct point2
{
	int x;
	int y;
	int step;
	int idx;
};

vector<point> guest;
vector<point2> hoobo;

void input()
{
	cin >> N >> M >> G;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			cin >> Array[i][j];

	cin >> ty >> tx;
	for (int i = 0; i < M; i++)
	{
		int Sx, Sy, Dx, Dy;
		cin >> Sy >> Sx >> Dy >> Dx;
		Array[Sy][Sx] = 2;
		guest.push_back({ Sx,Sy,Dx,Dy, i, 0 });
	}
}

bool cmp(point2& u, point2& v)
{
	if (u.step < v.step) return true;
	else if (u.step == v.step)
	{
		if (u.y < v.y) return true;
		else if (u.y == v.y)
		{
			if (u.x < v.x) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

void BFS_H(int x, int y)
{
	memset(visit, 0, sizeof(visit));
	queue<point2> q;
	q.push({ x, y, 0 });
	visit[y][x] = true;

	while (!q.empty())
	{
		int X = q.front().x;
		int Y = q.front().y;
		int step = q.front().step;
		q.pop();

		if (hoobo.size() > 0 && step > hoobo[0].step) return;
		if (Array[Y][X] == 2)
		{
			for (int i = 0; i < guest.size(); i++)
			{
				if (guest[i].state == 0 && X == guest[i].Sx && Y == guest[i].Sy)
				{
					hoobo.push_back({ X, Y, step, guest[i].idx });
					break;
				}
			}
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx > 0 && nx <= N && ny > 0 && ny <= N)
			{
				if (visit[ny][nx] == false && Array[ny][nx] != 1)
				{
					visit[ny][nx] = true;
					q.push({ nx, ny, step + 1 });
				}
			}
		}
	}
}

int BFS(int Dx, int Dy)
{
	memset(visit, 0, sizeof(visit));
	queue<point2> q;
	q.push({ tx, ty, 0 });
	visit[ty][tx] = true;

	while (!q.empty())
	{
		int X = q.front().x;
		int Y = q.front().y;
		int step = q.front().step;
		q.pop();

		if (G - step < 0) continue; // <= 로하면 목적지에 내리는 동시에 가스가 0이 된 경우에 실패로 간주해 

		if (X == Dx && Y == Dy)
			return step;

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx > 0 && nx <= N && ny > 0 && ny <= N)
			{
				if (visit[ny][nx] == false && Array[ny][nx] != 1)
				{
					visit[ny][nx] = true;
					q.push({ nx, ny, step + 1 });
				}
			}
		}
	}

	return -1;
}

void solve()
{
	int num = guest.size();

	while (1)
	{
		if (num == 0) break;
		
		BFS_H(tx, ty);
		if (hoobo.size() == 0)
		{
			G = -1;
			break;
		}
		
		sort(hoobo.begin(), hoobo.end(), cmp);
		int dist = BFS(hoobo[0].x, hoobo[0].y);
		if (dist == -1)
		{
			G = -1;
			break;
		}
		else G -= dist;

		if (G <= 0)
		{
			G = -1;
			break;
		}
		tx = hoobo[0].x;
		ty = hoobo[0].y;
		int idx = hoobo[0].idx;
		dist = BFS(guest[idx].Dx, guest[idx].Dy);
		if (dist == -1)
		{
			G = -1;
			break;
		}
		else G -= dist;
		G += (dist * 2);
		num--;
		guest[idx].state = 1;
		Array[guest[idx].Sy][guest[idx].Sx] = 0;
		tx = guest[idx].Dx;
		ty = guest[idx].Dy;
		hoobo.clear();
	}

	cout << G;
}

int main()
{
	input();
	solve();
	return 0;
}
