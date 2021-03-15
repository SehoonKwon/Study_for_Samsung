#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//21.03.15 첫 도전 1시간 35분

#define endl "\n"

int N;
int Array[10][10];
int score;

void input()
{
	cin >> N;
}

void Bpush(int x, int y, int t)
{
	int bidx = -1;
	if (t == 1)
	{
		for (bidx = x; bidx < 10; bidx++)
		{
			if (Array[y][bidx] == 1)
			{
				bidx--;
				break;
			}
		}
		if (bidx >= 10) bidx = 9;
		Array[y][bidx] = 1;
	}
	else if (t == 2)
	{
		for (bidx = x + 1; bidx < 10; bidx++)
		{
			if (Array[y][bidx] == 1)
			{
				bidx--;
				break;
			}
		}
		if (bidx >= 10) bidx = 9;
		Array[y][bidx] = 1;
		Array[y][bidx - 1] = 1;
	}
	else if (t == 3)
	{
		for (bidx = x; bidx < 10; bidx++)
		{
			if (Array[y][bidx] == 1 || Array[y + 1][bidx] == 1)
			{
				bidx--;
				break;
			}
		}
		if (bidx >= 10) bidx = 9;
		Array[y][bidx] = 1;
		Array[y + 1][bidx] = 1;
	}
}

vector<int> checkB()
{
	vector<int> tv;
	for (int x = 9; x > 5; x--)
	{
		if (Array[0][x] == 1 && Array[1][x] == 1 && Array[2][x] == 1 && Array[3][x] == 1)
		{
			tv.push_back(x);
			Array[0][x] = Array[1][x] = Array[2][x] = Array[3][x] = 0;
		}
	}

	return tv;
}

void Bpush2(vector<int> DelB)
{
	for (int x = DelB[0]; x > 3; x--)
		for (int i = 0; i < 4; i++)
			Array[i][x] = Array[i][x - DelB.size()];
}

void check2B()
{
	int cnt = 0;
	for (int i = 4; i < 6; i++)
	{
		if (Array[0][i] == 1 || Array[1][i] == 1 || Array[2][i] == 1 || Array[3][i] == 1)
			cnt++;
	}

	for (int i = 0; i < 4; i++)
		for (int j = 9; j > 5; j--)
			Array[i][j] = Array[i][j - cnt];

	for (int i = 0; i < 4; i++)
	{
		Array[i][4] = 0;
		Array[i][5] = 0;
	}
}

void Gpush(int x, int y, int t)
{
	int gidx = -1;
	if (t == 1)
	{
		for (gidx = y; gidx < 10; gidx++)
		{
			if (Array[gidx][x] == 1)
			{
				gidx--;
				break;
			}
		}
		if (gidx >= 10) gidx = 9;
		Array[gidx][x] = 1;
	}
	else if (t == 2)
	{
		for (gidx = y; gidx < 10; gidx++)
		{
			if (Array[gidx][x] == 1 || Array[gidx][x + 1] == 1)
			{
				gidx--;
				break;
			}
		}
		if (gidx >= 10) gidx = 9;
		Array[gidx][x] = 1;
		Array[gidx][x + 1] = 1;
	}
	else if (t == 3)
	{
		for (gidx = y + 1; gidx < 10; gidx++)
		{
			if (Array[gidx][x] == 1)
			{
				gidx--;
				break;
			}
		}
		if (gidx >= 10) gidx = 9;
		Array[gidx][x] = 1;
		Array[gidx - 1][x] = 1;
	}
}

vector<int> checkG()
{
	vector<int> tv;
	for (int y = 9; y > 5; y--)
	{
		if (Array[y][0] == 1 && Array[y][1] == 1 && Array[y][2] == 1 && Array[y][3] == 1)
		{
			tv.push_back(y);
			Array[y][0] = Array[y][1] = Array[y][2] = Array[y][3] = 0;
		}
	}

	return tv;
}

void Gpush2(vector<int> DelG)
{
	for (int y = DelG[0]; y > 3; y--)
		for (int i = 0; i < 4; i++)
			Array[y][i] = Array[y - DelG.size()][i];
}

void check2G()
{
	int cnt = 0;
	for (int i = 4; i < 6; i++)
	{
		if (Array[i][0] == 1 || Array[i][1] == 1 || Array[i][2] == 1 || Array[i][3] == 1)
			cnt++;
	}

	for (int i = 9; i > 5; i--)
		for (int j = 0; j < 4; j++)
			Array[i][j] = Array[i - cnt][j];

	for (int i = 0; i < 4; i++)
	{
		Array[4][i] = 0;
		Array[5][i] = 0;
	}
}

void solve()
{
	int t, x, y;
	while (N--)
	{

		cin >> t >> y >> x; // 문제에서는 x가 행, y가 열
		Bpush(x, y, t);
		vector<int> DelB = checkB();
		if (DelB.size() > 0)
		{
			score += DelB.size();
			Bpush2(DelB);
		}
		check2B();

		Gpush(x, y, t);
		vector<int> DelG = checkG();
		if (DelG.size() > 0)
		{
			score += DelG.size();
			Gpush2(DelG);
		}
		check2G();
	}

	cout << score << endl;
	int block_cnt = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (Array[i][j] == 1) block_cnt++;

	cout << block_cnt;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
