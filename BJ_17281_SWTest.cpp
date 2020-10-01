//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N;
//int Array[51][9];
//int visit[9];
//int ans;
//
//
//vector<int> t;
//
//void input()
//{
//	cin >> N;
//	for (int i = 1; i < N + 1; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			cin >> Array[i][j];
//		}
//	}
//}
//
//int Game()
//{
//	int turn_idx = 0, out_cnt = 0, score = 0; //turn_idx는 0번째가 아니라 순서가 들어있는 t의 인덱스용
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		int ru1 = 0, ru2 = 0, ru3 = 0;
//
//		while (1)
//		{
//			int res = Array[i][t[turn_idx]];
//			turn_idx++;
//			if (turn_idx == 9) turn_idx = 0;
//
//			switch (res)
//			{
//			case 0:
//				out_cnt++;
//				break;
//
//			case 1:
//				if (ru3 == 1)
//				{
//					score++;
//					ru3 = 0;
//				}
//
//				if (ru2 == 1)
//				{
//					ru3 = 1;
//					ru2 = 0;
//				}
//
//				if (ru1 == 1)
//					ru2 = 1;
//				else
//					ru1 = 1;
//
//				break;
//
//			case 2:
//				if (ru3 == 1)
//				{
//					score++;
//					ru3 = 0;
//				}
//
//				if (ru2 == 1)
//				{
//					score++;
//					ru2 = 0;
//
//				}
//				if (ru1 == 1)
//				{
//					ru3 = 1;
//					ru1 = 0;
//					ru2 = 1;
//				}
//				else if (ru1 == 0)
//					ru2 = 1;
//
//				break;
//
//			case 3:
//				if (ru3 == 1)
//				{
//					score++;
//					ru3 = 0;
//				}
//
//				if (ru2 == 1)
//				{
//					score++;
//					ru2 = 0;
//				}
//				if (ru1 == 1)
//				{
//					score++;
//					ru1 = 0;
//					ru3 = 1;
//				}
//				else if (ru1 == 0)
//					ru3 = 1;
//
//				break;
//
//			case 4:
//				score += (ru1 + ru2 + ru3 + 1);
//				ru1 = 0, ru2 = 0, ru3 = 0;
//				break;
//
//			default:
//				break;
//			}
//
//			if (out_cnt == 3)
//			{
//				out_cnt = 0;
//				break;
//			}
//		}
//	}
//
//	return score;
//}
//
//void DFS(int cnt)
//{
//	if (cnt == 8)
//	{
//		//차례 정해져있으니 게임 돌리기
//		t.insert(t.begin() + 3, 0);
//		int res = Game();
//		t.erase(t.begin() + 3);
//
//		//최댓값
//		if (ans < res) ans = res;
//		return;
//	}
//
//	for (int i = 1; i < 9; i++)
//	{
//		if (visit[i] == true) continue;
//
//		visit[i] = true;
//		t.push_back(i);
//		DFS(cnt + 1);
//		t.pop_back();
//		visit[i] = false;
//	}
//}
//
//void solve()
//{
//	//순서 정하기 -> 게임 돌리기 -> 최댓값 찾기
//	DFS(0);
//	
//	cout << ans << "\n";
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	input();
//	solve();
//	return 0;
//}