//#include <iostream>
//using namespace std;
//
////�ʹ� ����� �ʹ�
//
//#define endl "\n"
//
//int Array[10];
//int M_score = 0;
//int S1_table[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40 };  // ��1
//int S2_table[] = { 10, 13, 16, 19, 25, 26, 27, 28, 30, 32, 34, 36, 38, 40 }; //��2
//int S3_table[] = { 20, 22, 24, 25, 30, 35, 40 };
//int S4_table[] = { 30, 28, 27, 26, 25, 19, 16, 13, 10 };
//
//void input()
//{
//	for (int i = 0; i < 10; i++)
//		cin >> Array[i];
//}
//
//int Move(int dir, int C_idx, int M_idx)
//{
//	int res = 0;
//
//	switch (dir)
//	{
//	case 1: //�⺻ ��Ʈ, ũ�� ���� ����
//		C_idx += M_idx;
//		if (C_idx == 5)
//		{
//			dir = 2;
//			C_idx = 0;
//			res = 10;
//		}
//		else if (C_idx == 10)
//		{
//			dir = 3;
//			C_idx = 0;
//			res = 20;
//		}
//		else if (C_idx == 15)
//		{
//			dir = 4;
//			C_idx = 0;
//			res = 30;
//		}
//		else
//			res = S1_table[C_idx];
//
//		break;
//	case 2: //10������ ���������� ���� ����
//		C_idx += M_idx;
//		if (C_idx == 4) // 25�� ��ġ
//		{
//			dir = 3;
//			C_idx = 3;
//			res = 25;
//		}
//		else if (C_idx == 8)
//		{
//			dir = 4;
//			C_idx = 0;
//			res = 30;
//		}
//		else
//			res = S2_table[C_idx];
//		break;
//	case 3: //20������ ���ΰ��� ����
//		C_idx += M_idx;
//		if (C_idx > 6)
//		{
//			res = 40;
//		}
//		else
//			res = S3_table[C_idx];
//		break;
//	case 4:
//		C_idx += M_idx;
//		if (C_idx == 4) // 25�� ��ġ
//		{
//			dir = 3;
//			C_idx = 3;
//			res = 25;
//		}
//		else if (C_idx == 8)
//		{
//			dir = 2;
//			C_idx = 0;
//			res = 10;
//		}
//		else if (C_idx > 8)
//		{
//			dir = 1;
//			C_idx = (C_idx - 8) + 5; // 10 ��ġ�� �Ѿ�� ĭ �� + dir1 10��ġ�� idx
//			res = S1_table[C_idx];
//		}
//		else
//			res = S2_table[C_idx];
//		break;
//	default:
//		break;
//	}
//
//
//	return res;
//}
//
//void DFS(int S)
//{
//
//}
//
//void solve()
//{
//	DFS(0);
//
//	cout << M_score << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	input();
//	solve();
//	
//	return 0;
//}