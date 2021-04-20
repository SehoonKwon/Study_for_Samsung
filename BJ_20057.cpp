#include <iostream>
using namespace std;

//21.04.20 지문 이해 못하고 배열 , 잘몰쓴거 못찾아서 한참 헤맴. 2시간 8분

#define endl "\n"

int N;
int Array[510][510];
int dx[4][10] = { { -2, -1, -1, 0, 0, 0, 0, 1, 1, -1 }, {0, -1, 1, -1, 1, -2, 2, -1, 1, 0},
				{2, 1, 1, 0, 0, 0, 0, -1, -1, 1}, { 0, -1, 1, -1, 1, -2, 2, -1, 1, 0} };
int dy[4][10] = { { 0, -1, 1, -1, 1, -2, 2, -1, 1, 0 }, { 2, 1, 1, 0, 0, 0, 0, -1, -1, 1 },
				 {0,-1, 1, -1, 1, -2, 2, -1, 1, 0}, {-2, -1, -1, 0, 0, 0, 0, 1, 1, -1} };
double pct[9] = { 0.05, 0.1, 0.1, 0.07, 0.07, 0.02, 0.02, 0.01, 0.01 };
int total;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Array[i][j];
}

void tornado(int x, int y, int dir)
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int addmorae;
		if (i == 9) addmorae = Array[y][x] - sum;
		else
		{
			addmorae = (int)(Array[y][x] * pct[i]);
			sum += addmorae;
		}
		int nx = x + dx[dir][i];
		int ny = y + dy[dir][i];

		if (nx > -1 && nx < N && ny > -1 && ny < N)
			Array[ny][nx] += addmorae;
		else
			total += addmorae;
	}

	Array[y][x] = 0;
}

void solve()
{
	//토네이도 초기상태
	int x = N / 2, y = N / 2, dir = 0, lcnt = 0, dcnt = 0, rcnt = 0, ucnt = 0;
	int nlcnt = 1, ndcnt = 1, nrcnt = 2, nucnt = 2;

	int cnt = 0;
	while (1)
	{
		cnt++;
		if (cnt == N * N) break;
		if (dir == 0)
		{
			x--;
			lcnt++;
			tornado(x, y, dir);
			if (lcnt == nlcnt)
			{
				dir = 1;
				nlcnt += 2;
				lcnt = 0;
			}
		}
		else if (dir == 1)
		{
			y++;
			dcnt++;
			tornado(x, y, dir);
			if (dcnt == ndcnt)
			{
				dir = 2;
				ndcnt += 2;
				dcnt = 0;
			}
		}
		else if (dir == 2)
		{
			x++;
			rcnt++;
			tornado(x, y, dir);
			if (rcnt == nrcnt)
			{
				dir = 3;
				nrcnt += 2;
				rcnt = 0;
			}
		}
		else if (dir == 3)
		{
			y--;
			ucnt++;
			tornado(x, y, dir);
			if (ucnt == nucnt)
			{
				dir = 0;
				nucnt += 2;
				ucnt = 0;
			}
		}
	}

	cout << total;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
