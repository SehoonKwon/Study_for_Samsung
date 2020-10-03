#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//20.10.03 1시간 21분

int N, M, k;
int sk_dir[401][5][5]; //번호, 현재dir, 우선dir
int dx[] = { 0, 0, 0, -1, 1 }; //상하좌우
int dy[] = { 0, -1,1, 0, 0 };
int kArray[21][21]; //흔적타이머 배열
int sArray[21][21]; //상어흔적 저장배열
int sk_cnt;
vector<int> Array[21][21];

struct SHK
{
	int x;
	int y;
	int dir;
	int dead;
};

vector<SHK> sk(401);

void input()
{
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int x;
			cin >> x;
			if (x > 0)
			{
				Array[i][j].push_back(x);
				sk[x].x = j;
				sk[x].y = i;
			}
		}
	}

	for (int i = 1; i < M + 1; i++)
	{
		int dir;
		cin >> dir;
		sk[i].dir = dir;
	}

	for (int i = 1; i < M + 1; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 1; k < 5; k++)
			{
				cin >> sk_dir[i][j][k];
			}
		}
	}
}

void kcut()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (kArray[i][j] > 0)
			{
				kArray[i][j]--;
				if (kArray[i][j] == 0)
					sArray[i][j] = 0;
			}
}

void move_sk()
{
	for (int i = 1; i < M + 1; i++)
	{
		if (sk[i].dead == 1) continue;
		int flag = 0;
		int x = sk[i].x;
		int y = sk[i].y;
		int cdir = sk[i].dir;
		for (int j = 1; j < 5; j++)
		{
			int ndir = sk_dir[i][cdir][j];
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];

			if (nx > -1 && nx < N && ny > -1 && ny < N)
			{
				//흔적이 없는 곳
				if (kArray[ny][nx] == 0)
				{
					sk[i].x = nx;
					sk[i].y = ny;
					sk[i].dir = ndir;
					Array[ny][nx].push_back(i);
					flag = 1;
					break;
				}
			}

			if (flag)
				break;
		}

		//흔적이 없는 곳 못 찾았으면
		if (!flag)
		{
			for (int j = 1; j < 5; j++)
			{
				int ndir = sk_dir[i][cdir][j];
				int nx = x + dx[ndir];
				int ny = y + dy[ndir];

				if (nx > -1 && nx < N && ny > -1 && ny < N)
				{
					//자기 흔적이 있는 곳
					if (sArray[ny][nx] == i)
					{
						sk[i].x = nx;
						sk[i].y = ny;
						sk[i].dir = ndir;
						Array[ny][nx].push_back(i);
						flag = 1;
						break;
					}
				}

				if (flag)
					break;
			}
		}
	}
}

void chk()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Array[i][j].size() > 1)
			{
				sort(Array[i][j].begin(), Array[i][j].end());
				for (int k = 1; k < Array[i][j].size(); k++)
					sk[Array[i][j][k]].dead = 1;
			}
		}
	}
}

void skroot()
{
	for (int i = 1; i < M + 1; i++)
	{
		if(sk[i].dead == 0)
		{
			int x = sk[i].x;
			int y = sk[i].y;
			kArray[y][x] = k;
			sArray[y][x] = i;
		}
	}
}

void solve()
{
	k++;
	//처음 상어들 흔적 남기기
	for (int i = 1; i < M + 1; i++)
	{
		int x = sk[i].x;
		int y = sk[i].y;
		kArray[y][x] = k;
		sArray[y][x] = i;
	}

	for (int i = 1; i < 1001; i++)
	{
		//흔적 -1
		kcut();

		//상어 움직이기
		move_sk();

		//모든 칸 점검
		chk();
		
		//종료 조건
		int cnt = 0;
		for (int j = 1; j < M + 1; j++)
		{
			if (sk[j].dead == 0)
			{
				cnt++;
				if (cnt >= 2) break;
			}
		}
		if (cnt == 1)
		{
			cout << i;
			return;
		}

		//흔적 남기기
		skroot();

		//상어배열 초기화
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				Array[j][k].clear();
	}

	cout << -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}