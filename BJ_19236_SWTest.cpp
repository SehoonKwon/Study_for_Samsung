#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

//�ٲٷ��� ������ 0�϶� ������ ������ ������µ� �̸� ��ã�Ƽ� ���ѽð����� ��Ǯ����

int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }; // dummy, ��, �»�, ��, ����, ��, ����, ��, ���
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int MAX;

struct FISH
{
	int x;
	int y;
	int num;
	int dir;
};

int Array[4][4];
vector<FISH> v(17);

void input()
{
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int num, dir;
			cin >> num >> dir;
			v[num] = { j, i, num, dir };
			Array[i][j] = num;
		}
	}
}

void Hunt(FISH sk, int Arr[][4], vector<FISH> f)
{
	//����� �̵�
	for (int i = 1; i < 17; i++)
	{
		if (f[i].dir == -1)
			continue;

		int dir = f[i].dir;

		for (int j = 0; j < 8; j++)
		{
			if (dir == 9) dir = 1;
			int nx = f[i].x + dx[dir];
			int ny = f[i].y + dy[dir];

			if (nx > -1 && nx < 4 && ny > -1 && ny < 4)
			{
				if (nx == sk.x && ny == sk.y) dir++;
				else
				{
					int target = Arr[ny][nx];
					f[i].dir = dir;

					if (target == 0)
					{
						Arr[ny][nx] = i;
						Arr[f[i].y][f[i].x] = 0;

						f[i].x = nx;
						f[i].y = ny;
					}
					else
					{
						FISH temp = f[target];
						f[target].x = f[i].x;
						f[target].y = f[i].y;
						Arr[f[target].y][f[target].x] = target;

						f[i].x = temp.x;
						f[i].y = temp.y;
						Arr[f[i].y][f[i].x] = i;
					}
					break;
				}
			}
			else
				dir++;
		}
	}

	int sdir = sk.dir;
	for (int i = 1; ; i++)
	{
		int nx = sk.x + dx[sdir] * i;
		int ny = sk.y + dy[sdir] * i;

		if (nx > -1 && nx < 4 && ny > -1 && ny < 4)
		{
			if (Arr[ny][nx] == 0) continue;
			vector<FISH> tf = f;
			int tArr[4][4];
			for (int j = 0; j < 4; j++)
				memcpy(tArr[j], Arr[j], sizeof(Arr[j]));

			int target = tArr[ny][nx];
			FISH tsk = { tf[target].x, tf[target].y, sk.num + tf[target].num, tf[target].dir };
			tf[target].dir = -1;
			tArr[ny][nx] = 0;

			Hunt(tsk, tArr, tf);
		}
		else
		{
			if (MAX < sk.num) MAX = sk.num;
			return;
		}
	}
}

void solve()
{
	//��� ��ġ 0, 0 ����� �԰� ���� -> ����� �̵�
	//-> ����̵� (��Ʈ��ŷ �� ���� �� �迭���� �� �纻�� �Ķ���ͷ� �Ѱܼ� ó���ϱ�) -> �̵����� �� �ִ� ����
	int target = Array[0][0];
	FISH shark = { v[target].x, v[target].y, v[target].num, v[target].dir };
	v[target].dir = -1;
	Array[0][0] = 0;

	Hunt(shark, Array, v);
	cout << MAX;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}