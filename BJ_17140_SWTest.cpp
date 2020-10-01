//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int r, c, k;
//int Array[101][101];
//int num_cnt[101];
//int cnt_R, cnt_C, cnt_pair = 0;
//
//struct Num
//{
//	int num;
//	int cnt;
//};
//
//vector<Num> v;
//
//int check_rc()
//{
//	int M = 0;
//	for (int i = 1; i < 101; i++)
//	{
//		cnt_C = 0;
//		for (int j = 1; j < 101; j++)
//		{
//			if (Array[i][j] != 0) cnt_C++;
//			else break;
//		}
//		M = max(cnt_C, M);
//	}
//
//	cnt_C = M;
//
//	M = 0;
//	for (int i = 1; i < 101; i++)
//	{
//		cnt_R = 0;
//		for (int j = 1; j < 101; j++)
//		{
//			if (Array[j][i] != 0) cnt_R++;
//			else break;
//		}
//		M = max(cnt_R, M);
//	}
//	cnt_R = M;
//
//	return cnt_R >= cnt_C;
//}
//
//int cmp_Num(Num &u, Num &v)
//{
//	if (u.cnt < v.cnt) return true;
//	else if (u.cnt == v.cnt) return u.num < v.num;
//	else return false;
//}
//
//void oper_R()
//{
//	for (int i = 1; i < cnt_R + 1; i++)
//	{
//		memset(num_cnt, 0, sizeof(num_cnt));
//		v.clear();
//		for (int j = 1; j < cnt_C + 1; j++)
//		{
//			num_cnt[Array[i][j]]++;
//		}
//
//		for (int j = 1; j < 101; j++)
//		{
//			if (num_cnt[j] != 0)
//				v.push_back({ j, num_cnt[j] });
//		}
//
//		sort(v.begin(), v.end(), cmp_Num);
//
//		int cnt_v = 0;
//		//for (int j = 1; j < 101; j = j++)
//		//{
//		//	if (cnt_v >= v.size()) Array[i][j] = 0;
//		//	else
//		//	{
//		//		Array[i][j] = v[cnt_v].num;
//		//		Array[i][j + 1] = v[cnt_v].cnt;
//		//		cnt_v++;
//		//		j++;
//		//	}
//		//}
//
//		//행 초기화는 memset으로 되나 열 초기화는 안됌. 시간초과 걸려서 행만이라도 memset으로 바꿨더니 통과 => 위에 단순 실수였음 j=j++로 되있던거 j++로 고치니 통과 속도 같음
//		memset(Array[i], 0, sizeof(Array[i]));
//		int j = 1;
//		for (; cnt_v < v.size(); cnt_v++)
//		{
//			Array[i][j] = v[cnt_v].num;
//			Array[i][j+1] = v[cnt_v].cnt;
//			j = j + 2;
//		}
//	}
//}
//
//void oper_C()
//{
//	for (int i = 1; i < cnt_C + 1; i++)
//	{
//		memset(num_cnt, 0, sizeof(num_cnt));
//		v.clear();
//		for (int j = 1; j < cnt_R + 1; j++)
//		{
//			num_cnt[Array[j][i]]++;
//		}
//
//		for (int j = 1; j < 101; j++)
//		{
//			if (num_cnt[j] != 0)
//				v.push_back({ j, num_cnt[j] });
//		}
//
//		sort(v.begin(), v.end(), cmp_Num);
//
//		int cnt_v = 0;
//		for (int j = 1; j < 100; j++)
//		{
//			if (cnt_v >= v.size()) Array[j][i] = 0;
//			else
//			{
//				Array[j][i] = v[cnt_v].num;
//				Array[j + 1][i] = v[cnt_v].cnt;
//				cnt_v++;
//				j++;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> r >> c >> k;
//
//	for (int i = 1; i < 4; i++)
//		for (int j = 1; j < 4; j++)
//			cin >> Array[i][j];
//
//	cnt_R = 3; cnt_C = 3;
//
//	int ans, time = 0;
//	while (1)
//	{
//		if (time > 100)
//		{
//			ans = -1;
//			break;
//		}
//
//		else if (Array[r][c] == k)
//		{
//			ans = time;
//			break;
//		}
//
//		int ch = check_rc();
//		if (ch == 1) oper_R();
//		else oper_C();
//		time++;
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}