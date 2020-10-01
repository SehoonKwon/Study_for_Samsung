//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//#define endl "\n"
//
//// size�� ����� 1�̻��̶�� ���ִ°� ������ 3�� �Ѵ°�쵵 �ִµ� ? -> rotate�� �ƿ� �Լ�ȭ�� �ؾߵɵ� => ����
//
//int N, M, K;
//int Array[51][51], Array2[51][51],Array3[51][51];
//int visit[7];
//int MIN = 9999;
//
//struct point
//{
//	int x, y;
//	int size;
//};
//
//vector<point> v, v2;
//
//void input()
//{
//	cin >> N >> M >> K;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			cin >> Array[i][j];
//
//	for (int i = 0; i < K; i++)
//	{
//		int x, y, s;
//		cin >> y >> x >> s;
//		v.push_back({ x - 1, y - 1, s }); //����� 0, 0���� �����ϹǷ� ��ǥ -1��
//	}
//
//	memcpy(Array2, Array, sizeof(Array));
//	memcpy(Array3, Array, sizeof(Array)); //���� �迭 ����
//}
//
//int row_MIN()
//{
//	int m = 9999;
//	for (int i = 0; i < N; i++)
//	{
//		int sum = 0;
//		for (int j = 0; j < M; j++)
//			sum += Array[i][j];
//
//		m = min(sum, m);
//	}
//
//	return m;
//}
//
//
//void Rotate(int x, int y, int s)
//{
//	if (x - s < 0 || x + s > M || y - s < 0 || y - s > N) return;
//
//	for (int c = 1; c <= s; c++)
//	{
//		//��
//		for (int i = x - c + 1; i <= x + c; i++)
//			Array[y - c][i] = Array2[y - c][i - 1];
//
//		//������
//		for (int i = y - c + 1; i <= y + c; i++)
//			Array[i][x + c] = Array2[i - 1][x + c];
//
//		//�Ʒ�
//		for (int i = x + c - 1; i >= x - c; i--)
//			Array[y + c][i] = Array2[y + c][i + 1];
//
//		//����
//		for (int i = y + c - 1; i >= y - c; i--)
//			Array[i][x - c] = Array2[i + 1][x - c];
//	}
//}
//
//void setting(int x, int y, int size)
//{
//	Rotate(x, y, size);
//}
//
////������ �ƴϰ� �����̹Ƿ� idx ���� �ȉ�
//void DFS(int cnt)
//{
//	if (cnt == K)
//	{
//		memcpy(Array, Array3, sizeof(Array2)); //���� �迭 ����
//
//		for (int i = 0; i < v2.size(); i++)
//		{
//			memcpy(Array2, Array, sizeof(Array)); //�ѹ� ������ �ٲ� �迭�� �̿��ϱ� ���ؼ� ���� ����
//			setting(v2[i].x, v2[i].y, v2[i].size);
//		}
//
//		int m = row_MIN();
//
//		MIN = min(m, MIN);
//		return;
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (visit[i] == true) continue;
//
//		visit[i] = true;
//		v2.push_back(v[i]);
//		DFS(cnt + 1);
//		v2.pop_back();
//		visit[i] = false;
//
//	}
//}
//
//void solve()
//{
//	//DFS�� ���� ¥�� �ѹ��� ����ذ��� �ּڰ� ����
//	DFS(0);
//
//	cout << MIN << endl;
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