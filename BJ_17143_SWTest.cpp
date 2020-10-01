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
//		//낚시꾼 열에 물고기가 있으면 앞에서부터 잡기 ( 가장 가까운 물고기 인덱스 저장 )
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
//	v[small].r = -100; //여기가 문제 -> 해결(100번째줄에서 big을 alive로 리턴받고 i가아닌 alive를 이용해줘야 됌. 왜냐하면 i가 small값이 됐을 경우 이미 c가 조정된 후라 맵에서 원하는 곳을 찍지 못함
//	v[small].isLive = 0; //쉽게 이렇게 생존여부로만 해도 가능
//
//	return big;
//}
//
//void shark_move()
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		//잡힌 물고기는 넘어간다
//		if (v[i].c == -100) continue; 
//		if (v[i].isLive == 0) continue;
//
//		int alive;
//
//		//위쪽
//		if (v[i].dir == 1)
//		{
//			int pos = v[i].r;
//			int flag = 0; //0은 위로, 1은 아래로
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
//			//해당 배열에 물고기가 몇갠지 세기
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2개 이상인 경우 이전과 비교해서 작은 상어 삭제
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //물고기 인덱스 저장
//			continue; //컨티뉴 안해주면 아래방향으로 이동 후 다시 바로 밑에 if문에 걸림
//		}
//
//		//아래쪽
//		if (v[i].dir == 2)
//		{
//			int pos = v[i].r;
//			int flag = 1; //0은 위로, 1은 아래로
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
//			//해당 배열에 물고기가 몇갠지 세기
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2개 이상인 경우 이전과 비교해서 작은 상어 삭제
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //물고기 인덱스 저장
//			continue;
//		}
//
//		//오른쪽
//		if (v[i].dir == 3)
//		{
//			int pos = v[i].c;
//			int flag = 0; //0은 오른쪽, 1은 왼쪽
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
//			//해당 배열에 물고기가 몇갠지 세기
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2개 이상인 경우 이전과 비교해서 작은 상어 삭제
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //물고기 인덱스 저장
//			continue;
//		}
//
//		//왼쪽
//		if (v[i].dir == 4)
//		{
//			int pos = v[i].c;
//			int flag = 1; //0은 오른쪽, 1은 왼쪽
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
//			//해당 배열에 물고기가 몇갠지 세기
//			cnt[v[i].r][v[i].c]++;
//			if (cnt[v[i].r][v[i].c] > 1) // 2개 이상인 경우 이전과 비교해서 작은 상어 삭제
//			{
//				int pre = Array[v[i].r][v[i].c];
//				alive = kill(pre, i);
//				cnt[v[alive].r][v[alive].c]--;
//				Array[v[alive].r][v[alive].c] = alive;
//			}
//			else Array[v[i].r][v[i].c] = i; //물고기 인덱스 저장
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
//	//낚시왕은 1부터 시작해서 이동->잡기->잡은 물고기 업데이트
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