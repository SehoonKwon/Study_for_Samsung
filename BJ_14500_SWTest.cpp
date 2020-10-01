//#include <iostream>
//using namespace std;
//
//int N, M;
//int Array[501][501];
//int ans;
//
//void input()
//{
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			cin >> Array[i][j];
//}
//
//int T0(int x, int y, int r)
//{
//	if (r > 1) return 0; //1�� ��Ʈ��̷δ� ȸ���� 1����
//	
//	int sum = 0;
//	if (r == 0) //����
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (x + i >= M) return 0; //���� ���
//			else sum += Array[y][x + i];
//		}
//	}
//	else //����
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (y + i >= N) return 0; //���� ���
//			else sum += Array[y + i][x];
//		}
//	}
//	
//	return sum;
//}
//
//int T1(int x, int y, int r)
//{
//	if (r > 0) //ȸ�� ���� ����
//		return 0;
//
//	int sum = 0;
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < 2; j++)
//		{
//			if (y + i >= N || x + j >= M) return 0;
//			else sum += Array[y + i][x + j];
//		}
//
//	return sum;
//}
//
//int T2(int x, int y, int r)
//{
//	int sum = 0;
//	switch (r)
//	{
//	case 0:
//		for (int i = 0; i < 3; i++)
//		{
//			if (i + y < N) sum += Array[y + i][x];
//			else return 0;
//		}
//
//		if (y + 2 < N && x + 1 < M) sum += Array[y + 2][x + 1];
//		else return 0;
//		break;
//	case 1:
//		for (int i = 0; i < 3; i++)
//		{
//			if (i + x < M) sum += Array[y][x + i];
//			else return 0;
//		}
//
//		if (x + 2 < M && y - 1 > -1) sum += Array[y - 1][x + 2];
//		else return 0;
//		break;
//	case 2:
//		for (int i = 0; i < 3; i++)
//		{
//			if (y - i > -1) sum += Array[y - i][x];
//			else return 0;
//		}
//
//		if (y - 2 > -1 && x - 1 > -1) sum += Array[y - 2][x - 1];
//		else return 0;
//		break;
//	case 3:
//		for (int i = 0; i < 3; i++)
//		{
//			if (x - i > -1) sum += Array[y][x - i];
//			else return 0;
//		}
//
//		if (x - 2 > -1 && y + 1 < N) sum += Array[y + 1][x - 2];
//		else return 0;
//		break;
//	default:
//		break;
//	}
//
//	return sum;
//}
//
//int T3(int x, int y, int r)
//{
//	if (r > 1) return 0;
//
//	int sum = 0;
//	if (r == 0)
//	{
//		if (y + 1 >= N || x + 1 >= M || y + 2 >= N) return 0;
//		else sum = Array[y][x] + Array[y + 1][x] + Array[y + 1][x + 1] + Array[y + 2][x + 1];
//	}
//	else
//	{
//		if (x + 1 >= M || y - 1 < 0 || x + 2 >= M) return 0;
//		else sum = Array[y][x] + Array[y][x + 1] + Array[y - 1][x + 1] + Array[y - 1][x + 2];
//	}
//
//	return sum;
//}
//
//int T4(int x, int y, int r)
//{
//	int sum = 0;
//	switch (r)
//	{
//	case 0:
//		if (x - 1 < 0 || x + 1 >= M || y + 1 >= N) return 0;
//		sum = Array[y][x] + Array[y][x - 1] + Array[y][x + 1] + Array[y + 1][x];
//		break;
//	case 1:
//		if (y - 1 < 0 || y + 1 >= N || x + 1 >= M) return 0;
//		sum = Array[y][x] + Array[y - 1][x] + Array[y + 1][x] + Array[y][x + 1];
//		break;
//	case 2:
//		if (x - 1 < 0 || x + 1 >= M || y - 1 < 0) return 0;
//		sum = Array[y][x] + Array[y][x - 1] + Array[y][x + 1] + Array[y - 1][x];
//		break;
//	case 3:
//		if (y - 1 < 0 || y + 1 >= N || x - 1 < 0) return 0;
//		sum = Array[y][x] + Array[y - 1][x] + Array[y + 1][x] + Array[y][x - 1];
//		break;
//	default:
//		break;
//	}
//
//	return sum;
//}
//
//int T6(int x, int y, int r)
//{
//	if (r > 1) return 0;
//
//	int sum = 0;
//	if (r == 0)
//	{
//		if (y + 1 >= N || x - 1 < 0 || y + 2 >= N) return 0;
//		else sum = Array[y][x] + Array[y + 1][x] + Array[y + 1][x - 1] + Array[y + 2][x - 1];
//	}
//	else
//	{
//		if (x - 1 < 0 || y - 1 < 0 || x - 2 < 0) return 0;
//		else sum = Array[y][x] + Array[y][x - 1] + Array[y - 1][x - 1] + Array[y - 1][x - 2];
//	}
//
//	return sum;
//}
//
//int T5(int x, int y, int r)
//{
//	int sum = 0;
//	switch (r)
//	{
//	case 0:
//		for (int i = 0; i < 3; i++)
//		{
//			if (i + y < N) sum += Array[y + i][x];
//			else return 0;
//		}
//
//		if (y + 2 < N && x - 1 > -1) sum += Array[y + 2][x - 1];
//		else return 0;
//		break;
//	case 1:
//		for (int i = 0; i < 3; i++)
//		{
//			if (i + x < M) sum += Array[y][x + i];
//			else return 0;
//		}
//
//		if (x + 2 < M && y + 1 < N) sum += Array[y + 1][x + 2];
//		else return 0;
//		break;
//	case 2:
//		for (int i = 0; i < 3; i++)
//		{
//			if (y - i > -1) sum += Array[y - i][x];
//			else return 0;
//		}
//
//		if (y - 2 > -1 && x + 1 < M) sum += Array[y - 2][x + 1];
//		else return 0;
//		break;
//	case 3:
//		for (int i = 0; i < 3; i++)
//		{
//			if (x - i > -1) sum += Array[y][x - i];
//			else return 0;
//		}
//
//		if (x - 2 > -1 && y - 1 > -1) sum += Array[y - 1][x - 2];
//		else return 0;
//		break;
//	default:
//		break;
//	}
//
//	return sum;
//}
//
//int Tetno(int x, int y, int num, int r)
//{
//	int res = 0;
//	switch (num)
//	{
//	case 0:
//		res = T0(x, y, r);
//		break;
//	case 1:
//		res = T1(x, y, r);
//		break;
//	case 2:
//		res = T2(x, y, r);
//		break;
//	case 3:
//		res = T3(x, y, r);
//		break;
//	case 4:
//		res = T4(x, y, r);
//		break;
//	case 5: // 2�� ��Ī
//		res = T5(x, y, r);
//		break;
//	case 6: //3�� ��Ī
//		res = T6(x, y, r);
//		break;
//	default:
//		break;
//	}
//
//	return res;
//}
//
//void solve()
//{
//	//���� 5�� + ��Ī�Ǵ� 2��(�������� ȸ������ ����) �ؼ� 8���� ��Ʈ��̷� ����� -> ȸ�� �Լ� ���� �� ���� Ž���ϸ� �ִ� ����
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			for (int k = 0; k < 7; k++) //��Ʈ��̷� ����
//			{
//				for (int r = 0; r < 4; r++) //ȸ��
//				{
//					int res = Tetno(j, i, k, r);
//					if (ans < res) ans = res;
//				}
//			}
//		}
//	}
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