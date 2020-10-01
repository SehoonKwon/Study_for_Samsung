//#include <iostream>
//#include <deque>
//using namespace std;
//
////20.06.02 1½Ã°£ 52ºÐ clear
//
//int N, M, T;
//int x[51], d[51], k[51];
//deque<int> D[51], temp[51];
//
//void input()
//{
//	cin >> N >> M >> T;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			int X;
//			cin >> X;
//			D[i].push_back(X);
//		}
//	}
//
//	for (int i = 0; i < T; i++)
//		cin >> x[i] >> d[i] >> k[i];
//}
//
//void Rotate(int idx, int dir, int num)
//{
//	if (dir == 0)
//	{
//		for (int i = 0; i < num; i++)
//		{
//			int temp = D[idx].back();
//			D[idx].pop_back();
//			D[idx].push_front(temp);
//		}
//	}
//	else
//	{
//		for (int i = 0; i < num; i++)
//		{
//			int temp = D[idx].front();
//			D[idx].pop_front();
//			D[idx].push_back(temp);
//		}
//	}
//}
//
//int calcul()
//{
//	int sum = 0;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			sum += D[i][j];
//
//	return sum;
//}
//
//void PRT()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//			cout << D[i][j] << " ";
//		cout << "\n";
//	}
//}
//
//int check()
//{
//	for (int i = 0; i < N; i++)
//		temp[i] = D[i];
//
//	int flag = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			int up = i + 1, down = i - 1, left = j - 1, right = j + 1;
//			if (left == -1) left = M - 1;
//			if (right == M) right = 0;
//
//			if (D[i][j] != 0 && up < N && D[i][j] == D[up][j])
//			{
//				flag = 1;
//				temp[i][j] = 0;
//				temp[up][j] = 0;
//			}
//
//			if (D[i][j] != 0 && down > 0 && D[i][j] == D[down][j])
//			{
//				flag = 1;
//				temp[i][j] = 0;
//				temp[down][j] = 0;
//			}
//
//			if (D[i][j] != 0 && D[i][j] == D[i][left])
//			{
//				flag = 1;
//				temp[i][j] = 0;
//				temp[i][left] = 0;
//			}
//
//			if (D[i][j] != 0 && D[i][j] == D[i][right])
//			{
//				flag = 1;
//				temp[i][j] = 0;
//				temp[i][right] = 0;
//			}
//		}
//	}
//
//	if (flag)
//	{
//		for (int i = 0; i < N; i++)
//			D[i] = temp[i];
//
//		return 0;
//	}
//
//	return 1;
//}
//
//void adjust()
//{
//	int sum = 0, cnt = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (D[i][j] != 0)
//			{
//				sum += D[i][j];
//				cnt++;
//			}
//		}
//	}
//
//	double avg = (double)sum / cnt;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (D[i][j] != 0)
//			{
//				if (D[i][j] > avg) D[i][j]--;
//				else if (D[i][j] < avg) D[i][j]++;
//			}
//		}
//	}
//
//}
//
//void solve()
//{
//	for (int i = 0; i < T; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if ((j + 1) % x[i] == 0) Rotate(j, d[i], k[i]);
//		}
//
//		int c = check();
//		if (c)
//			adjust();
//	}
//
//	int res = calcul();
//	cout << res;
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