//#include <iostream>
//using namespace std;
//
//#define endl "\n"
//
////N �ִ밪�� 100���̹Ƿ� N^2���δ� ���� �������
////�־��� ��� : �Ѱ���, �ΰ������� 1�� ���� �����Ҷ� �� �����帶�� �ο��� �ִ�� �������� �ʿ��� �������� (1 + 99��) * N�� => 100��^2
////long int = int !! long long int�� �ؾ���, long long int => int * 4��,  90���
//
//int N, B, C;
//int Array[1000001];
//long long int ans = 0;
//
//void input()
//{
//	cin >> N;
//	for (int i = 1; i < N + 1; i++)
//		cin >> Array[i];
//
//	cin >> B >> C;
//}
//
////�ΰ��� �� ���ϱ�
//int calcul(int x)
//{
//	int res = Array[x] / C;
//
//	if ((res * C) == Array[x]) return res;
//	else return res + 1;
//}
//
//void solve()
//{
//	//�� �����帶�� �ѽ��谨���� 1�� �ʼ���ġ.
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		int cnt = 0;
//		
//		//�ѽ��谨���� ��ġ
//		Array[i] -= B;
//		ans++;
//
//		//�ѽ��谨�������ε� ����ϸ� ���� ������
//		if (Array[i] <= 0)
//			continue;
//
//		//���� �ο���ŭ �ΰ��� ��� ä���
//		cnt = calcul(i);
//
//		ans += cnt;
//	}
//
//	cout << ans << endl;
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