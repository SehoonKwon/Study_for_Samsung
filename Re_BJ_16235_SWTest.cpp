//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//using namespace std;
//
////��� �� Ǯ��ô�
//
//int N, M, K;
//int dx[] = { -1,0,1,-1,1,-1,0,1 };
//int dy[] = { -1,-1,-1, 0, 0,1,1,1 };
//int A[11][11]; //�ش� ĭ�� �߰��Ǵ� ���
//int d[11][11]; //�ش� ĭ�� ���
//int p[11][11]; //�ش� ĭ�� �ִ� �߰��� ������ ��
//vector<int> tree[11][11]; //�ش� ĭ�� �ִ� ������. ���� ������ ���� �����ϹǷ� int��
//
//void init()
//{
//	for (int i = 1; i < N + 1; i++)
//		for (int j = 1; j < N + 1; j++)
//			d[i][j] = 5; //�ʱ� ���
//}
//
//void input()
//{
//	cin >> N >> M >> K;
//
//	init();
//
//	for (int i = 1; i < N + 1; i++)
//		for (int j = 1; j < N + 1; j++)
//		{
//			cin >> A[i][j]; //�ų� �߰��Ǵ� ���
//		}
//
//	int x, y, age;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> x >> y >> age;
//		tree[x][y].push_back(age); //�̰� [y][x]�� �ϸ� Ʋ��. why? = r,c�� �����ϰ� �ڿ� �̾ ��ǥ�� x,y�� �߱⶧���� r == x, c == y�̴�!
//	}
//}
//
//int check()
//{
//	int cnt = 0;
//	for (int i = 1; i < N + 1; i++)
//		for (int j = 1; j < N + 1; j++)
//			cnt += tree[i][j].size();
//	
//	return cnt;
//}
//
//void solve()
//{
//	for (int i = 0; i < K; i++)
//	{
//		memset(p, 0, sizeof(p));
//		//������ ������ �ʰ� �� ĭ�� ���ؼ� ����. ���� ���� ������ 2�������� 4��. �̷��� �ϸ� 2������ 1��
//		for (int i = 1; i < N + 1; i++)
//		{
//			for (int j = 1; j < N + 1; j++)
//			{
//				sort(tree[i][j].begin(), tree[i][j].end()); // �ش� ĭ�� ���� ������ ����
//
//				vector<int> temp; //tree������Ʈ��
//				int dead = 0; // ���� ������� ���� ���� ���
//				for (int k = 0; k < tree[i][j].size(); k++) //for(int x : tree[i][j]) �� ���� �˾Ƶα�. ==> x = tree[i][j][0] -> x = tree[i][j][1] ->...
//				{
//					//�ڱ⸸ŭ ����� ������
//					if (tree[i][j][k] <= d[i][j])
//					{
//						temp.push_back(tree[i][j][k] + 1);
//						d[i][j] -= tree[i][j][k];
//					}
//					else
//					{
//						dead += (tree[i][j][k] / 2); //���� ������ �ش�
//					}
//				}
//
//				//���� ����
//				for (int k : temp)
//				{
//					if ((k % 5) == 0)
//					{
//						for (int l = 0; l < 8; l++)
//						{
//							int nx = j + dx[l];
//							int ny = i + dy[l];
//
//							if (nx > 0 && nx < N + 1 && ny > 0 && ny < N + 1)
//								p[ny][nx]++;
//						}
//					}
//				}
//
//				//�ܿ�
//				d[i][j] += A[i][j] + dead;
//				tree[i][j] = temp;
//			}
//		}
//
//		//�� ������ ���ĵ� ������ �߰�
//		for (int i = 1; i < N + 1; i++)
//		{
//			for (int j = 1; j < N + 1; j++)
//			{
//				for (int k = 0; k < p[i][j]; k++)
//					tree[i][j].push_back(1);
//			}
//		}
//
//	}
//
//	int ans = check();
//	cout << ans;
//}
//
//int main()
//{
//	input();
//	solve();
//
//	return 0;
//}