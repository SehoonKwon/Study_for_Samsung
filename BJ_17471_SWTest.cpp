//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//#define endl "\n"
//
//int N;
//int vil[11]; //마을 사람 수
//int Array[11][11]; //마을이 이어진 정보
//int MIN = 987654321;
//int visit[11]; // 1은 1번구역, 0은 2번구역
//int V[11]; //사이클 확인용 visit
//int cnt1, cnt2;
//
//void input()
//{
//	cin >> N;
//	for (int i = 1; i < N + 1; i++)
//		cin >> vil[i];
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		int cnt;
//		cin >> cnt;
//
//		for (int j = 0; j < cnt; j++)
//		{
//			int a;
//			cin >> a;
//
//			Array[i][a] = 1;
//			Array[a][i] = 1;
//		}
//
//		Array[i][i] = 1; // 자기 자신과 이어져 있음
//	}
//}
//
//void connect1(int idx)
//{
//	if (V[idx] == 1) return; //이미 1번마을에 포함되있는 idx면 return
//	V[idx] = true;
//	cnt1++; // 1번구역이 하나도 없는 불상사 방지용
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (Array[idx][i] == 1 && visit[i] == 1) //i번째 마을과 이어져있고 visit[i]==1 -> 1번마을이라 지정되어있는 경우면
//		{
//			connect1(i); // V에 표시
//		}
//	}
//}
//
//void connect2(int idx)
//{
//	if (V[idx] == 2) return; //이미 2번마을에 포함되있는 idx면 return
//	V[idx] = 2;
//	cnt2++; // 2번구역이 하나도 없는 불상사 방지용
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (Array[idx][i] == 1 && visit[i] == 0) //i번째 마을과 이어져있고 visit[i]==0 -> 2번마을이라 지정되어있는 경우면
//		{
//			connect2(i); // V에 표시
//		}
//	}
//}
//
//int isCycle()
//{
//	memset(V, 0, sizeof(V)); //memcpy visit하면 이미 1번이 visit[1]==1 상태라 논리오류. 처음부터 하나씩 만들어간다 생각해야 모든 탐색
//	cnt1 = 0, cnt2 = 0;
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (visit[i] == 1)
//		{
//			connect1(i);
//			break; //바로 브레이크 해줘야 사이클 1개만 생김
//		}
//	}
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (visit[i] == 0)
//		{
//			connect2(i);
//			break; //바로 브레이크 해줘야 사이클 1개만 생김
//		}
//	}
//
//	if (cnt1 == 0 || cnt2 == 0) return false;
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (V[i] == 0) return false;
//	}
//
//	return true;
//}
//
//void DFS(int idx)
//{
//	int p = isCycle();
//	if (p == 1)
//	{
//		int sum1 = 0, sum2 = 0;
//		for (int i = 1; i < N + 1; i++)
//		{
//			if (visit[i] == 1) sum1 += vil[i];
//			else if (visit[i] == 0) sum2 += vil[i];
//		}
//
//		MIN = min(MIN, abs(sum1 - sum2));
//	}
//
//	for (int i = idx; i < N + 1; i++)
//	{
//		if (visit[i] == true) continue;
//
//		visit[i] = true;
//		DFS(i);
//		visit[i] = false;
//	}
//}
//
//void solve()
//{
//	DFS(1);
//
//	if (MIN != 987654321) cout << MIN << endl;
//	else cout << "-1" << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	input();
//
//	solve();
//
//	return 0;
//}