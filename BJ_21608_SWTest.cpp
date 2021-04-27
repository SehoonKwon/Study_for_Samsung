#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//21.04.27 시험 본 다다음날

int N;
int Array[21][21];
int want[401][4];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<int> q;

struct point
{
	int x;
	int y;
	int ecnt;
	int wcnt;
};
vector<point> v;

void input()
{
	cin >> N;
	for (int i = 1; i <= N * N; i++)
	{
		int x;
		cin >> x;
		q.push(x);
		for (int j = 0; j < 4; j++)
			cin >> want[x][j];
	}
}

void check(int x, int y, int num)
{
	int ecnt = 0, wcnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && nx <= N && ny > 0 && ny <= N)
		{
			if (Array[ny][nx] == 0) ecnt++;
			else
			{
				for (int j = 0; j < 4; j++)
					if (Array[ny][nx] == want[num][j])
						wcnt++;
			}
		}
	}

	v.push_back({ x, y, ecnt, wcnt });
}

bool cmp(const point& u, const point& v)
{
	if (u.wcnt > v.wcnt) return true;
	else if (u.wcnt == v.wcnt)
	{
		if (u.ecnt > v.ecnt) return true;
		else if (u.ecnt == v.ecnt)
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
	else return false;
}

int sum(int x, int y)
{
	int cnt = 0, num = Array[y][x];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && nx <= N && ny > 0 && ny <= N)
		{
			for (int j = 0; j < 4; j++)
				if (Array[ny][nx] == want[num][j]) cnt++;
		}
	}

	if (cnt == 1) return 1;
	else if (cnt == 2) return 10;
	else if (cnt == 3) return 100;
	else if (cnt == 4) return 1000;
	else return 0;
}

void solve()
{
	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		//빈 칸 갯수 체크
		v.clear();
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if(Array[i][j] == 0) check(j, i, num);

		sort(v.begin(), v.end(), cmp);

		Array[v[0].y][v[0].x] = num;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ans += sum(j, i);

	cout << ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
