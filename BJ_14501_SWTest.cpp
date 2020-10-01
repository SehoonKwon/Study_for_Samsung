//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//#define endl "\n"
//
//// ���� ��Ʈ��ŷ �������� 40�� ��
//
//int N;
//int visit[16];
//int MAX = 0;
//
//struct point
//{
//	int T;
//	int P;
//};
//
//vector<point> v;
//
//void input()
//{
//	cin >> N;
//
//	v.push_back({ 0, 0 }); //�ε��� ���߱�� ����
//	for (int i = 0; i < N; i++)
//	{
//		int t, p;
//		cin >> t >> p;
//		v.push_back({ t, p });
//	}
//}
//
//int calcul()
//{
//	int sum = 0;
//	for (int i = 1; i < N + 1; i++)
//	{
//		if (visit[i] == 1)
//		{
//			sum += v[i].P;
//		}
//	}
//
//	return sum;
//}
//
//void DFS(int idx)
//{
//	if (idx > N)
//	{
//		int ans = calcul();
//
//		MAX = max(ans, MAX);
//		return;
//	}
//
//	visit[idx] = true;
//	int k = v[idx].T;
//	if (idx + k <= N + 1) DFS(idx + k);
//
//	//���� ���ϴ� ��� �׳� �ε��� �ϳ� ���� �ؼ� �ѱ��. �̷��� �ؾ� ������ �� üũ ���ϰ� �ѱ� �� ����
//	visit[idx] = false;
//	DFS(idx + 1);
//
//}
//
//void solve()
//{
//	DFS(1);
//
//	cout << MAX << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	input();
//
//	solve();
//
//	return 0;
//}