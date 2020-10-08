#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

//20.10.08

int N, M;
int Array[11][11];
int land[11][11];
int visit[11][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int parent[7];

struct point
{
	int s;
	int e;
	int dist;
};

vector<point> v;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Array[i][j];
}

void DFS(int x, int y, int c)
{
	visit[y][x] = c;
	land[y][x] = c;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx > -1 && nx < M && ny > -1 && ny < N)
			if (visit[ny][nx] == false && Array[ny][nx] == 1)
				DFS(nx, ny, c);
	}
}

void find_land()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (land[i][j] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int x = j;
					int y = i;
					while (1)
					{
						x += dx[k];
						y += dy[k];
						
						if (x < 0 || x >= M || y < 0 || y >= N) break;
						if (land[y][x] > 0)
						{
							if (land[y][x] == land[i][j]) break;
							else if (land[y][x] != land[i][j])
							{
								int d = abs(y - i) + abs(x - j) - 1; // -1 ÇØÁÖ¾î¾ß ºó Ä­ °¹¼ö¸¸Å­¸¸ Ä«¿îÆ®
								v.push_back({ land[i][j], land[y][x], d });
								break;
							}
						}
					}
				}
			}
		}
	}
}

int myFind(int x)
{
	if (x == parent[x]) return x;
	else return parent[x] = myFind(parent[x]);
}

bool cmp(const point& u, const point& v)
{
	if (u.dist < v.dist) return true;
	else return false;
}

void solve()
{
	//¼¶ ¹øÈ£ ÁöÁ¤
	int lcnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == false && Array[i][j] == 1)
			{
				DFS(j, i, lcnt);
				lcnt++;
			}
		}
	} 

	lcnt--; //¼¶ °¹¼ö

	//°¢°¢ÀÇ ¼¶¿¡¼­ ´Ù¸¥ ¼¶ Ã£°í Á¤º¸ º¤ÅÍ¿¡ ÀúÀå
	find_land();

	//MST±¸Çö
	for (int i = 1; i < 7; i++)
		parent[i] = i;

	sort(v.begin(), v.end(), cmp);
	int dari_cnt = 0;
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int s = v[i].s;
		int e = v[i].e;
		int dist = v[i].dist;
		if (dist < 2) continue;

		int S = myFind(s);
		int E = myFind(e);
		if (S == E) continue;

		parent[E] = S;
		dari_cnt++;
		sum += v[i].dist;
	}

	if (dari_cnt == lcnt - 1) cout << sum;
	else cout << -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}