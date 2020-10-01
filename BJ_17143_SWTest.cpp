//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//#define endl "\n"
//
//int Array[101][101];
//int cnt[101][101];
//int R, C, M;
//int ans;
//
//struct shark
//{
//	int r;
//	int c;
//	int move;
//	int dir;
//	int size;
//	int isLive;
//};
//
//vector<shark> v;
//
//int fishing(int man)
//{
//	int fish_size;
//	int idx = -1, minR = 99999;
//	for (int i = 0; i < R + 1; i++)
//	{
//		//���ò� ���� ����Ⱑ ������ �տ������� ��� ( ���� ����� ����� �ε��� ���� )
//		if (cnt[i][man] == 1)
//		{
//			idx = Array[i][man];
//			int fish_size = v[idx].size;
//			v[idx].isLive = 0;
//			v[idx].c = -10;
//			cnt[i][man] = 0;
//			return fish_size;
//		}
//	}
//
//	return 0;
//}
//
//int kill(int pre, int now)
//{
//	int big, small;
//	if (v[pre].size > v[now].size)
//	{
//		big = pre;
//		small = now;
//	}
//	else
//	{
//		big = now;
//		small = pre;
//	}
//
//	v[small].r = -100; //���Ⱑ ���� -> �ذ�(100��°�ٿ��� big�� alive�� ���Ϲް� i���ƴ� alive�� �̿������ ��. �ֳ��ϸ� i�� small���� ���� ��� �̹� c�� ������ �Ķ� �ʿ��� ���ϴ� ���� ���� ����
//	v[small].isLive = 0; //���� �̷��� �������ηθ� �ص� ����
//
//	return big;
//}
//
//void shark_move()
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		//���� ������ �Ѿ��
//		if (v[i].c == -100) continue; 
//		if (v[i].isLive == 0) continue;
//
//		int alive;
//
//		//����
//		if (v[i].dir == 1)
//		{
//			int pos = v[i].r;
//			int flag = 0; //0�� ����, 1�� �Ʒ���
//			for (int j = 0; j < v[i].move; j++)
//			{
//				if (flag == 0 && (pos == 1))  flag = 1;
//				else if (flag == 1 && (pos == R)) flag = 0;
//
//				if (flag == 0) pos--;
//				else pos++;
//			}
//
//			if (flag == 1) v[i].dir = 2;
//			else v[i].dir = 1;
//			v[i].r = pos;
//
//			//�ش� �迭�� ����Ⱑ ��� ����
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2�� �̻��� ��� ������ ���ؼ� ���� ��� ����
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //����� �ε��� ����
//			continue; //��Ƽ�� �����ָ� �Ʒ��������� �̵� �� �ٽ� �ٷ� �ؿ� if���� �ɸ�
//		}
//
//		//�Ʒ���
//		if (v[i].dir == 2)
//		{
//			int pos = v[i].r;
//			int flag = 1; //0�� ����, 1�� �Ʒ���
//			for (int j = 0; j < v[i].move; j++)
//			{
//				if (flag == 0 && (pos == 1))  flag = 1;
//				else if (flag == 1 && (pos == R)) flag = 0;
//
//				if (flag == 0) pos--;
//				else pos++;
//			}
//
//			if (flag == 1) v[i].dir = 2;
//			else v[i].dir = 1;
//			v[i].r = pos;
//
//			//�ش� �迭�� ����Ⱑ ��� ����
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2�� �̻��� ��� ������ ���ؼ� ���� ��� ����
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //����� �ε��� ����
//			continue;
//		}
//
//		//������
//		if (v[i].dir == 3)
//		{
//			int pos = v[i].c;
//			int flag = 0; //0�� ������, 1�� ����
//			for (int j = 0; j < v[i].move; j++)
//			{
//				if (flag == 0 && (pos == C))  flag = 1;
//				else if (flag == 1 && (pos == 1)) flag = 0;
//
//				if (flag == 0) pos++;
//				else pos--;
//			}
//
//			if (flag == 1) v[i].dir = 4;
//			else v[i].dir = 3;
//			v[i].c = pos;
//
//			//�ش� �迭�� ����Ⱑ ��� ����
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2�� �̻��� ��� ������ ���ؼ� ���� ��� ����
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //����� �ε��� ����
//			continue;
//		}
//
//		//����
//		if (v[i].dir == 4)
//		{
//			int pos = v[i].c;
//			int flag = 1; //0�� ������, 1�� ����
//			for (int j = 0; j < v[i].move; j++)
//			{
//				if (flag == 0 && (pos == C))  flag = 1;
//				else if (flag == 1 && (pos == 1)) flag = 0;
//
//				if (flag == 0) pos++;
//				else pos--;
//			}
//
//			if (flag == 1) v[i].dir = 4;
//			else v[i].dir = 3;
//			v[i].c = pos;
//
//			//�ش� �迭�� ����Ⱑ ��� ����
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2�� �̻��� ��� ������ ���ؼ� ���� ��� ����
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //����� �ε��� ����
//			continue;
//		}
//	}
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> R >> C >> M;
//
//	for (int i = 0; i < M; i++)
//	{
//		int r, c, s, d, z;
//		cin >> r >> c >> s >> d >> z;
//
//		v.push_back({ r, c, s, d, z, 1 });
//		Array[v[i].r][v[i].c] = i;
//		cnt[v[i].r][v[i].c]++;
//	}
//
//	if (M == 0)
//	{
//		cout << "0";
//		return 0;
//	}
//
//	//���ÿ��� 1���� �����ؼ� �̵�->���->���� ����� ������Ʈ
//	for (int i = 1; i <= C; i++)
//	{
//		int a = fishing(i);
//		ans += a;
//		memset(cnt, 0, sizeof(Array));
//		shark_move();
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}