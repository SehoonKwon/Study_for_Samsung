#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl "\n"

//21.10.23 1시간 14분

int N, M;
int Array[51][51], idx_Array[51][51], temp[2500];
int d[101], s[101];
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, -1, 1, 0, 0 };
int lcnt = 1, dcnt = 1, rcnt = 2, ucnt = 2;
int dir_cnt[5];
int vsize, ans;

struct point
{
	int x;
	int y;
	int val;
};
vector<point> v(2500);

void input()
{
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			cin >> Array[i][j];

	for (int i = 1; i < M + 1; i++)
		cin >> d[i] >> s[i];
}


void makeNum()
{
	int X = (N + 1) / 2, Y = (N + 1) / 2, dir = 3;
	int num = 1;

	while (1)
	{
		X += dx[dir];
		Y += dy[dir];
		dir_cnt[dir]++;

		if (X == 0) break;

		if (dir == 1)
		{
			if (dir_cnt[dir] == ucnt)
			{
				dir_cnt[dir] = 0;
				dir = 3;
				ucnt += 2;
			}
		}
		else if (dir == 2)
		{
			if (dir_cnt[dir] == dcnt)
			{
				dir_cnt[dir] = 0;
				dir = 4;
				dcnt += 2;
			}
		}

		else if (dir == 3)
		{
			if (dir_cnt[dir] == lcnt)
			{
				dir_cnt[dir] = 0;
				dir = 2;
				lcnt += 2;
			}
		}

		else if (dir == 4)
		{
			if (dir_cnt[dir] == rcnt)
			{
				dir_cnt[dir] = 0;
				dir = 1;
				rcnt += 2;
			}
		}

		v[num] = { X, Y, Array[Y][X] };
		idx_Array[Y][X] = num;
		num++;
	}
	vsize = num;
}

void pull()
{
	for (int i = 1; i < vsize; i++)
	{
		if(v[i].val == 0)
		{
			for (int k = i + 1; k < vsize; k++)
			{
				if (v[k].val > 0)
				{
					v[i].val = v[k].val;
					Array[v[i].y][v[i].x] = v[i].val;
					v[k].val = 0;
					Array[v[k].y][v[k].x] = v[k].val;
					break;
				}
			}
		}
	}
}

int explosion()
{
	int flag = 0;
	for (int i = 1; i < vsize; i++)
	{
		vector<int> ev;
		ev.push_back(i);

		for (int k = i + 1; k < vsize; k++)
		{
			if (v[k].val > 0 && v[k].val == v[i].val) ev.push_back(k);
			else break;
		}
		
		if (ev.size() >= 4)
		{
			ans += (v[ev[0]].val * (int)ev.size());
			for (int k = 0; k < ev.size(); k++)
			{
				int num = ev[k];
				v[num].val = 0;
				Array[v[num].y][v[num].x] = v[num].val;
			}
			flag = 1;
		}
	}

	return flag;
}

void makeGroup()
{
	//그룹만들기
	memset(temp, 0, sizeof(temp));
	int num = 1;
	for (int i = 1; i < vsize; i++)
	{
		vector<int> gv;
		if (v[i].val == 0) break;
		gv.push_back(v[i].val);

		for (int k = i + 1; k < vsize; k++)
		{
			if (v[k].val > 0 && v[k].val == v[i].val) gv.push_back(v[k].val);
			else break;
		}

		temp[num] = gv.size();
		num++;
		if (num > vsize) break;
		temp[num] = gv[0];
		num++;
		if (num > vsize) break;

		i += gv.size() - 1;
	}

	//새 맵 짜기
	memset(Array, 0, sizeof(Array));
	for (int i = 1; i < vsize; i++)
	{
		v[i].val = temp[i];
		Array[v[i].y][v[i].x] = v[i].val;
	}
}

void solve()
{
	//칸 만들기
	makeNum();
	
	int X = (N + 1) / 2, Y = (N + 1) / 2;
	for (int k = 1; k < M + 1; k++)
	{
		//블리자드 마법
		int bd = d[k], bs = s[k];

		for (int r = 1; r <= bs; r++)
		{
			int nx = X + dx[bd] * r;
			int ny = Y + dy[bd] * r;

			if (nx < 1 || nx > N || ny < 1 || ny > N) break;
			int num = idx_Array[ny][nx];
			Array[ny][nx] = 0;
			v[num].val = 0;
		}

		//당겨오기
		pull();

		//연쇄폭발 & 당기기
		while (1)
		{
			int e = explosion();
			if (e == 0) break;
			else pull();
		}

		//그룹 만들기 & 판 새로짜기
		makeGroup();
	}

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
