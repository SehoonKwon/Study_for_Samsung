#include <iostream>
#include <deque>
using namespace std;

//21.14.14

int N, K;
int Array[210];
int chk;

struct point
{
	int r; //로봇유무
	int val; //내구도
};

void input()
{
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
		cin >> Array[i]; //임시저장
}

void solve()
{
	deque<point> dq(2 * N);
	for (int i = 0; i < 2 * N; i++)
		dq[i].val = Array[i];

	int cnt = 0;
	while (1)
	{
		cnt++;

		//1
		point temp = dq.back();
		dq.pop_back();
		dq.push_front(temp);
		dq[N - 1].r = 0;

		//2
		for (int i = N - 1; i > 0; i--)
		{
			if (dq[i].r == 1) continue;
			else
			{
				if (dq[i].val > 0 && dq[i - 1].r == 1)
				{
					dq[i].val--;
					if (dq[i].val == 0) chk++;
					dq[i].r = 1;
					dq[i - 1].r = 0;
				}

				dq[N - 1].r = 0;
			}
		}

		//3
		if (dq[0].r == 0 && dq[0].val > 0)
		{
			dq[0].r = 1;
			dq[0].val--;
			if (dq[0].val == 0) chk++;
		}

		//4
		if (chk >= K) break;
	}

	cout << cnt;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
