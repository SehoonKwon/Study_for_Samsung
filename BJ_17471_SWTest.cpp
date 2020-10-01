//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//#define endl "\n"
//
//int N;
//int vil[11]; //���� ��� ��
//int Array[11][11]; //������ �̾��� ����
//int MIN = 987654321;
//int visit[11]; // 1�� 1������, 0�� 2������
//int V[11]; //����Ŭ Ȯ�ο� visit
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
//		Array[i][i] = 1; // �ڱ� �ڽŰ� �̾��� ����
//	}
//}
//
//void connect1(int idx)
//{
//	if (V[idx] == 1) return; //�̹� 1�������� ���Ե��ִ� idx�� return
//	V[idx] = true;
//	cnt1++; // 1�������� �ϳ��� ���� �һ�� ������
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (Array[idx][i] == 1 && visit[i] == 1) //i��° ������ �̾����ְ� visit[i]==1 -> 1�������̶� �����Ǿ��ִ� ����
//		{
//			connect1(i); // V�� ǥ��
//		}
//	}
//}
//
//void connect2(int idx)
//{
//	if (V[idx] == 2) return; //�̹� 2�������� ���Ե��ִ� idx�� return
//	V[idx] = 2;
//	cnt2++; // 2�������� �ϳ��� ���� �һ�� ������
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (Array[idx][i] == 1 && visit[i] == 0) //i��° ������ �̾����ְ� visit[i]==0 -> 2�������̶� �����Ǿ��ִ� ����
//		{
//			connect2(i); // V�� ǥ��
//		}
//	}
//}
//
//int isCycle()
//{
//	memset(V, 0, sizeof(V)); //memcpy visit�ϸ� �̹� 1���� visit[1]==1 ���¶� ������. ó������ �ϳ��� ������ �����ؾ� ��� Ž��
//	cnt1 = 0, cnt2 = 0;
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (visit[i] == 1)
//		{
//			connect1(i);
//			break; //�ٷ� �극��ũ ����� ����Ŭ 1���� ����
//		}
//	}
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (visit[i] == 0)
//		{
//			connect2(i);
//			break; //�ٷ� �극��ũ ����� ����Ŭ 1���� ����
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