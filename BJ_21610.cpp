#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl "\n"

int N, M;
int Array[51][51], visit[51][51];
int d[101], s[101];
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

struct cloud
{
	int x;
	int y;
};
vector<cloud> cv(4);

void input()
{
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			cin >> Array[i][j];

	for (int i = 1; i < M + 1; i++)
		cin >> d[i] >> s[i];
}


void solve()
{
	cv[0] = { 1, N };
	cv[1] = { 2, N };
	cv[2] = { 1, N - 1 };
	cv[3] = { 2, N - 1 };

	for (int i = 1; i < M + 1; i++)
	{
		//구름 이동
		int cd = d[i], cs = s[i];
		for (int k = 0; k < cv.size(); k++)
		{
			cv[k].x += (cs * dx[cd]);
			cv[k].y += (cs * dy[cd]);

			if (cv[k].x % N == 0) cv[k].x = N;
			else
			{
				int r = cv[k].x % N;
				if (r < 0) cv[k].x = N + r;
				else cv[k].x = r;
			}

			if (cv[k].y % N == 0) cv[k].y = N;
			else
			{
				int r = cv[k].y % N;
				if (r < 0) cv[k].y = N + r;
				else cv[k].y = r;
			}
		}

		//비 내리기
		for (auto it : cv)
			Array[it.y][it.x]++;

		//물 복사
		for (int k = 0; k < cv.size(); k++)
		{
			for (int r = 2; r < 9; r += 2)
			{
				int nx = cv[k].x + dx[r];
				int ny = cv[k].y + dy[r];

				if (nx > 0 && nx < N + 1 && ny > 0 && ny < N + 1)
					if (Array[ny][nx] > 0)
						Array[cv[k].y][cv[k].x]++;
			}
		}

		//구름 제거 및 제거된 칸 표시
		memset(visit, 0, sizeof(visit));
		for (auto it : cv)
			visit[it.y][it.x] = true;

		cv.clear();

		//구름 생성
		for (int k = 1; k < N + 1; k++)
		{
			for (int r = 1; r < N + 1; r++)
				if (visit[k][r] == false && Array[k][r] >= 2)
				{
					Array[k][r] -= 2;
					cv.push_back({ r, k });
				}
		}
	}

	int sum = 0;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			sum += Array[i][j];

	cout << sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
