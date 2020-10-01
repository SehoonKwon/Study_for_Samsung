//#include <iostream>
//#include <cstring>
//using namespace std;
//
////4시간째 테케 통과했지만 fail
//
//#define endl "\n"
//
//int T;
//char Array[6][3][3] = { { { 'w','w','w' }, { 'w','w','w' }, { 'w', 'w', 'w' },  }, {{'y','y','y'},{ 'y','y','y' },{ 'y','y','y' } },
//{{'r','r','r'},{ 'r','r','r' },{ 'r','r','r' }}, {{'o','o','o'},{ 'o','o','o' },{ 'o','o','o' }},
//{{'g','g','g'},{ 'g','g','g' },{ 'g','g','g' }},{{'b','b','b'},{ 'b','b','b' },{ 'b','b','b' }} };
//char Array2[6][3][3];
//char temp[3];
//
//void input()
//{
//	cin >> T;
//	memcpy(Array2, Array, sizeof(Array));
//}
//
//void display()
//{
//	for (int j = 0; j < 3; j++)
//	{
//		cout << endl;
//		for (int k = 0; k < 3; k++)
//			cout << Array[0][j][k] << " ";
//	}
//}
//
//void rotate_U(char dir)
//{
//	if (dir == '+')
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[2][0][2 - i];
//			Array[2][0][2 - i] = Array[5][0][2 - i];
//			Array[5][0][2 - i] = Array[3][0][2 - i];
//			Array[3][0][2 - i] = Array[4][0][2 - i];
//			Array[4][0][2 - i] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[0][0][0];
//				Array[0][0][0] = Array[0][1][0];
//				Array[0][1][0] = Array[0][2][0];
//				Array[0][2][0] = Array[0][2][1];
//				Array[0][2][1] = Array[0][2][2];
//				Array[0][2][2] = Array[0][1][2];
//				Array[0][1][2] = Array[0][0][2];
//				Array[0][0][2] = Array[0][0][1];
//				Array[0][0][1] = temp[0];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[2][0][2 - i];
//			Array[2][0][2 - i] = Array[4][0][2 - i];
//			Array[4][0][2 - i] = Array[3][0][2 - i];
//			Array[3][0][2 - i] = Array[5][0][2 - i];
//			Array[5][0][2 - i] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[0][0][0];
//				Array[0][0][0] = Array[0][0][1];
//				Array[0][0][1] = Array[0][0][2];
//				Array[0][0][2] = Array[0][1][2];
//				Array[0][1][2] = Array[0][2][2];
//				Array[0][2][2] = Array[0][2][1];
//				Array[0][2][1] = Array[0][2][0];
//				Array[0][2][0] = Array[0][1][0];
//				Array[0][1][0] = temp[0];
//			}
//		}
//	}
//}
//
//void rotate_D(char dir)
//{
//	if (dir == '+')
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[2][2][i];
//			Array[2][2][i] = Array[4][2][i];
//			Array[4][2][i] = Array[3][2][i];
//			Array[3][2][i] = Array[5][2][i];
//			Array[5][2][i] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[1][0][0];
//				Array[1][0][0] = Array[1][1][0];
//				Array[1][1][0] = Array[1][2][0];
//				Array[1][2][0] = Array[1][2][1];
//				Array[1][2][1] = Array[1][2][2];
//				Array[1][2][2] = Array[1][1][2];
//				Array[1][1][2] = Array[1][0][2];
//				Array[1][0][2] = Array[1][0][1];
//				Array[1][0][1] = temp[0];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[2][2][i];
//			Array[2][2][i] = Array[5][2][i];
//			Array[5][2][i] = Array[3][2][i];
//			Array[3][2][i] = Array[4][2][i];
//			Array[4][2][i] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[1][0][0];
//				Array[1][0][0] = Array[1][0][1];
//				Array[1][0][1] = Array[1][0][2];
//				Array[1][0][2] = Array[1][1][2];
//				Array[1][1][2] = Array[1][2][2];
//				Array[1][2][2] = Array[1][2][1];
//				Array[1][2][1] = Array[1][2][0];
//				Array[1][2][0] = Array[1][1][0];
//				Array[1][1][0] = temp[0];
//			}
//		}
//	}
//}
//
//void rotate_F(char dir)
//{
//	if (dir == '+')
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][2][i];
//			Array[0][2][i] = Array[4][2 - i][2];
//			Array[4][2 - i][2] = Array[1][0][2 - i];
//			Array[1][0][2 - i] = Array[5][i][0];
//			Array[5][i][0] = temp[i];
//			if (i != 2)
//			{
//				temp[0] = Array[2][0][0];
//				Array[2][0][0] = Array[2][1][0];
//				Array[2][1][0] = Array[2][2][0];
//				Array[2][2][0] = Array[2][2][1];
//				Array[2][2][1] = Array[2][2][2];
//				Array[2][2][2] = Array[2][1][2];
//				Array[2][1][2] = Array[2][0][2];
//				Array[2][0][2] = Array[2][0][1];
//				Array[2][0][1] = temp[0];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][i][2];
//			Array[0][2][i] = Array[5][i][0];
//			Array[5][i][0] = Array[1][0][2 - i];
//			Array[1][2][2 - i] = Array[4][2 - i][2];
//			Array[4][2 - i][2] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[2][0][0];
//				Array[2][0][0] = Array[2][0][1];
//				Array[2][0][1] = Array[2][0][2];
//				Array[2][0][2] = Array[2][1][2];
//				Array[2][1][2] = Array[2][2][2];
//				Array[2][2][2] = Array[2][2][1];
//				Array[2][2][1] = Array[2][2][0];
//				Array[2][2][0] = Array[2][1][0];
//				Array[2][1][0] = temp[0];
//			}
//		}
//	}
//}
//
//void rotate_B(char dir)
//{
//	if (dir == '+')
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][0][2 - i];
//			Array[0][0][2 - i] = Array[5][2 - i][2];
//			Array[5][2 - i][2] = Array[1][2][i];
//			Array[1][2][i] = Array[4][i][0];
//			Array[4][i][0] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[3][0][0];
//				Array[3][0][0] = Array[3][1][0];
//				Array[3][1][0] = Array[3][2][0];
//				Array[3][2][0] = Array[3][2][1];
//				Array[3][2][1] = Array[3][2][2];
//				Array[3][2][2] = Array[3][1][2];
//				Array[3][1][2] = Array[3][0][2];
//				Array[3][0][2] = Array[3][0][1];
//				Array[3][0][1] = temp[0];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][i][2 - i];
//			Array[0][2][i] = Array[5][2 - i][2];
//			Array[5][2 - i][0] = Array[1][2][i];
//			Array[1][2][i] = Array[4][i][0];
//			Array[4][i][0] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[3][0][0];
//				Array[3][0][0] = Array[3][0][1];
//				Array[3][0][1] = Array[3][0][2];
//				Array[3][0][2] = Array[3][1][2];
//				Array[3][1][2] = Array[3][2][2];
//				Array[3][2][2] = Array[3][2][1];
//				Array[3][2][1] = Array[3][2][0];
//				Array[3][2][0] = Array[3][1][0];
//				Array[3][1][0] = temp[0];
//			}
//		}
//	}
//}
//
//void rotate_L(char dir)
//{
//	if (dir == '+')
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][i][0];
//			Array[0][i][0] = Array[3][2 - i][2];
//			Array[3][2 - i][2] = Array[1][i][0];
//			Array[1][i][0] = Array[2][i][0];
//			Array[2][i][0] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[4][0][0];
//				Array[4][0][0] = Array[4][1][0];
//				Array[4][1][0] = Array[4][2][0];
//				Array[4][2][0] = Array[4][2][1];
//				Array[4][2][1] = Array[4][2][2];
//				Array[4][2][2] = Array[4][1][2];
//				Array[4][1][2] = Array[4][0][2];
//				Array[4][0][2] = Array[4][0][1];
//				Array[4][0][1] = temp[0];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][i][0];
//			Array[0][i][0] = Array[2][i][0];
//			Array[2][i][0] = Array[1][i][0];
//			Array[1][i][0] = Array[3][i][2];
//			Array[3][i][2] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[4][0][0];
//				Array[4][0][0] = Array[4][0][1];
//				Array[4][0][1] = Array[4][0][2];
//				Array[4][0][2] = Array[4][1][2];
//				Array[4][1][2] = Array[4][2][2];
//				Array[4][2][2] = Array[4][2][1];
//				Array[4][2][1] = Array[4][2][0];
//				Array[4][2][0] = Array[4][1][0];
//				Array[4][1][0] = temp[0];
//			}
//		}
//	}
//}
//
//void rotate_R(char dir)
//{
//	if (dir == '+')
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][i][2];
//			Array[0][i][2] = Array[2][i][2];
//			Array[2][i][2] = Array[1][i][2];
//			Array[1][i][2] = Array[3][2 - i][0];
//			Array[3][2 - i][0] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[5][0][0];
//				Array[5][0][0] = Array[5][1][0];
//				Array[5][1][0] = Array[5][2][0];
//				Array[5][2][0] = Array[5][2][1];
//				Array[5][2][1] = Array[5][2][2];
//				Array[5][2][2] = Array[5][1][2];
//				Array[5][1][2] = Array[5][0][2];
//				Array[5][0][2] = Array[5][0][1];
//				Array[5][0][1] = temp[0];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			temp[i] = Array[0][i][2];
//			Array[0][i][2] = Array[3][2 - i][0];
//			Array[3][2 - i][0] = Array[1][i][2];
//			Array[1][i][2] = Array[2][i][2];
//			Array[2][i][2] = temp[i];
//
//			if (i != 2)
//			{
//				temp[0] = Array[5][0][0];
//				Array[5][0][0] = Array[5][0][1];
//				Array[5][0][1] = Array[5][0][2];
//				Array[5][0][2] = Array[5][1][2];
//				Array[5][1][2] = Array[5][2][2];
//				Array[5][2][2] = Array[5][2][1];
//				Array[5][2][1] = Array[5][2][0];
//				Array[5][2][0] = Array[5][1][0];
//				Array[5][1][0] = temp[0];
//			}
//		}
//	}
//}
//
//void rotate(char side, char dir)
//{
//	switch (side)
//	{
//	case 'U':
//	{
//		rotate_U(dir);
//		break;
//	}
//	case 'D':
//	{
//		rotate_D(dir);
//		break;
//	}
//	case 'F':
//	{
//		rotate_F(dir);
//		break;
//	}
//	case 'B':
//	{
//		rotate_B(dir);
//		break;
//	}
//	case 'L':
//	{
//		rotate_L(dir);
//		break;
//	}
//	case 'R':
//	{
//		rotate_R(dir);
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//void solve()
//{
//	int n;
//	char side, dir;
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> side >> dir;
//
//		rotate(side, dir);
//
////		cout << "-----------------" << endl;
////		display();
////		cout << endl;
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//			cout << Array[0][i][j];
//		cout << endl;
//	}
//}
//
//int main()
//{
//	input();
//
//	for (int i = 0; i < T; i++)
//	{
//		memcpy(Array, Array2, sizeof(Array));
//		solve();
//	}
//	//	rotate('L', '-');
//
//	//	display();
//
//	return 0;
//}
