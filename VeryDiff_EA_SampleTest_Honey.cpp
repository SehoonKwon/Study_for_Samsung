//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//#define endl "\n"
//
////�ٽ� �ϳ��ϳ� �����غ��� ���󰡺��ô�
//
//int N, M, C;
//int Array[11][11];
//int visit[11][11];
//int ans = 0;
//
//vector<int> Worker[2];
//
//void input()
//{
//	cin >> N >> M >> C;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> Array[i][j];
//}
//
//int calcul(int Person, int idx, int cnt, int sum, int profit)
//{
//	//������ �뷮�� �ʰ��� ��� -1 ����
//	if (cnt > M || sum > C) return -1;
//
//	//M�� Ž�� �Ϸ�
//	if (idx == M) return profit;
//
//	//visit�� ������� �ʰ� ��Ʈ��ŷ ! e.g) ������ ����.
//
//	//���õ� M���� �ش� idx ���� ��°��
//	int take = calcul(Person, idx + 1, cnt + 1, sum + Worker[Person][idx], profit + pow(Worker[Person][idx], 2));
//
//	//idx���� ���� �ʴ� ���
//	int nontake = calcul(Person, idx + 1, cnt + 1, sum, profit);
//
//	int re = 0;
//
//	if (take != -1) re = take;
//	if (nontake != -1 && take < nontake) re = nontake;
//
//	return re;
//
//	////�� ����� �ִ��� return
//	//return max(take, nontake);
//}
//
//void gather(int Person, int y)
//{
//	//2�� �� ä���� ���� ��� ���� ����
//	if (Person == 2)
//	{
//		int sum = calcul(0, 0, 0, 0, 0) + calcul(1, 0, 0, 0, 0);
//		ans = max(ans, sum);
//		return;
//	}
//
//	// y��°���� �ϴ� ������ ���������� ��� ����� ���� �ϸ鼭 �������� ������ ���� �ٽ� 0���� �� �ʿ䰡 ����
//	// e.g) 1���� 1,2�� üũ�ϰ� 2���� 10, 11üũ�ϴ� ���� 1���� 10, 11 üũ�� �� 2���� 1, 2�� üũ�ϴ� ���� �����Ƿ� ���� �Ȱ���. ���� ������� ����.
//	for (int i = y; i < N; i++)
//	{
//		for (int j = 0; j < N; j++) // �ܼ��� j < N ���� �ϸ� ����. ���� �Ѿ�� ��츦 ó������� �ϳ���. j < N ���� �ҰŸ� 68 line ó�� ����ó�� �߰�
//		{
//			if (j + M > N) continue;
//
//			int flag = true;
//
//			// M���� ĭ �� �̹� ���õ� ���� ������ �����ؼ� M���� ���� ���ϴ� ���Ƿ� ���� Ž������
//			for (int k = j; k < j + M; k++)
//				if (visit[i][k] == true)
//				{
//					flag = false;
//					break;
//				}
//
//			if (flag == false) continue;
//
//			//Ž���� ������ ���
//
//			//���� ǥ���ϰ� ���Ϳ� �ֱ�
//			for (int k = j; k < j + M; k++)
//			{
//				visit[i][k] = true;
//				Worker[Person].push_back(Array[i][k]);
//			}
//
//			gather(Person + 1, i);
//
//			//����ǥ�� �����
//			for (int k = j; k < j + M; k++)
//			{
//				visit[i][k] = false;
//				Worker[Person].pop_back();
//			}
//		}
//	}
//}
//
//void solve()
//{
//	//1���� ä���Ѵ��� �� ȯ�濡���� �ִ밪 ���ϱ� -> �ݺ�����
//
//	gather(0, 0); // i �ε���(2��° ����)�� �־������ν� ������� ������ �ٿ���. �ȳ��� ��� �ð��ʰ�. ������ 55 Line
//
//	cout << ans << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int T;
//	cin >> T;
//	for (int num = 1; num < T + 1; num++)
//	{
//		Worker[0].clear();
//		Worker[1].clear();
//		memset(visit, 0, sizeof(visit));
//		memset(Array, 0, sizeof(Array));
//		ans = 0;
//
//		input();
//
//		cout << "#" << num << " ";
//		solve();
//	}
//
//	return 0;
//}