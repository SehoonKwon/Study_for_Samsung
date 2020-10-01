//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//
//#define endl "\n"
//
////�� �й�� ������ ��� ���3��, ������ ���� �̿��� �����ϴ°� ��~~~~~~�� �����
//
//int T, N;
//int Array[11][11];
//int S_num[11];
//int ans = 9999;
//
//struct P
//{
//	int x, y;
//	int dist1, dist2;
//};
//
//struct S
//{
//	int x, y, time;
//};
//
//vector<P> person;
//vector<S> stair;
//
//void input()
//{
//	cin >> N;
//	for (int i = 1; i < N + 1; i++)
//	{
//		for (int j = 1; j < N + 1; j++)
//		{
//			cin >> Array[i][j];
//			if (Array[i][j] > 1) stair.push_back({ j, i, Array[i][j] });
//			else if (Array[i][j] == 1) person.push_back({ j, i });
//		}
//	}
//}
//
//bool cmp1(const  P &v, const P &u)
//{
//	if (v.dist1 < u.dist1) return true;
//	else return false;
//}
//
//bool cmp2(const P& v, const P &u)
//{
//	if (v.dist2 < u.dist2) return true;
//	else return false;
//}
//
//int getTime1(vector<P> v)
//{
//	if (v.empty()) return 0;
//
//	//���� ������� ����
//	sort(v.begin(), v.end(), cmp1);
//
//	//����� 3�� �̿밡���ϹǷ�
//	int use[3] = { 0 };
//	int time = v[0].dist1; // ���۽ð��� ���� ����� �̿��ڰ� ������ �ð�
//
//	while (1)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			//����� ������ ����ǰ�� ���� ���
//			if (v[i].dist1 == 0) continue;
//
//			//�����ð� Ȯ��
//			if (v[i].dist1 <= time) //���� �����ð��� ����ð����� ���ų� �������(=�մ��� ���)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					//����̿��ڰ� ���찡 ������ ����
//					if (use[j] <= 0)
//					{
//						//�������µ� �ɸ��½ð�. �ؿ��� 1�о� ����
//						use[j] = stair[0].time;
//						v[i].dist1 = 0; //�����ؼ� ����̿��ߴٰ� ǥ��
//
//						//������ ����ΰ��
//						if (i == v.size() - 1)
//						{
//							return time + stair[0].time; // +1; // ����ð� + ��ܳ������� �ð� + ����ϴ½ð� 1�� 
//						}
//
//						break;
//					}
//
//
//				}
//			}
//		}
//
//		//��� ��� üũ�� �� ��� ��ĭ�� ��������
//		for (int i = 0; i < 3; i++)
//			use[i]--;
//
//		time++;
//	}
//}
//
//int getTime2(vector<P> v)
//{
//	if (v.empty()) return 0;
//
//	//���� ������� ����
//	sort(v.begin(), v.end(), cmp2);
//
//	//����� 3�� �̿밡���ϹǷ�
//	int use[3] = { 0 };
//	int time = v[0].dist2; // ���۽ð��� ���� ����� �̿��ڰ� ������ �ð�
//
//	while (1)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			//�̹� ������ ����ǰ�� ���� ���
//			if (v[i].dist2 == 0) continue;
//
//			//�����ð� Ȯ��
//			if (v[i].dist2 <= time) //���� �����ð��� ����ð����� ���ų� �������(=�մ��� ���)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					//����̿��ڰ� ���찡 ������ ����
//					if (use[j] <= 0)
//					{
//						//�������µ� �ɸ��½ð�. �ؿ��� 1�о� ����
//						use[j] = stair[1].time;
//						v[i].dist2 = 0; //�����ؼ� ����̿��ߴٰ� ǥ��
//
//						//������ ����ΰ��
//						if (i == v.size() - 1)
//						{
//							return time + stair[1].time; // +1; // ����ð� + ��ܳ������� �ð� + ����ϴ½ð� 1�� 
//						}
//
//						break;
//					}
//
//
//				}
//			}
//		}
//
//		//��� ��� üũ�� �� ��� ��ĭ�� ��������
//		for (int i = 0; i < 3; i++)
//			use[i]--;
//
//		time++;
//	}
//}
//
//void DFS(int idx)
//{
//	if (idx == person.size())
//	{
//		//��� ������
//
//		vector<P> v1, v2;
//		for (int i = 0; i < person.size(); i++)
//		{
//			if (S_num[i] == 1) v1.push_back(person[i]);
//			else v2.push_back(person[i]);
//		}
//
//		ans = min(ans, max(getTime1(v1), getTime2(v2)));
//		return;
//	}
//
//	// idx��° ��� 1�� ��� �̿�
//	S_num[idx] = 1;
//	DFS(idx + 1);
//
//
//	// 2�� ��� �̿�
//	S_num[idx] = 2;
//	DFS(idx + 1);
//}
//
//void solve()
//{
//	//�� ����� �ⱸ������ �Ÿ� ���ϱ�
//	for (int i = 0; i < person.size(); i++)
//	{
//		person[i].dist1 = abs(person[i].x - stair[0].x) + abs(person[i].y - stair[0].y);
//		person[i].dist2 = abs(person[i].x - stair[1].x) + abs(person[i].y - stair[1].y);
//	}
//
//	//DFS�� ���� ��� �ⱸ�� ���� �������� ������ BFS�� �ð� ���ϰ� �ּڰ� �����ϱ�
//	DFS(0);
//
//	cout << ans << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	cin >> T;
////	T = 1;
//	for (int num = 1; num < T + 1; num++)
//	{
//		memset(Array, 0, sizeof(Array));
//		person.clear();
//		stair.clear();
//		ans = 9999;
//
//		input();
//
//		cout << "#" << num << " ";
//		solve();
//	}
//	return 0;
//}