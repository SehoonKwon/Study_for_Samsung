//#include <iostream>
//#include <cstring>
//#include <vector>
//using namespace std;
//
//#define endl "\n"
//
////사다리 연결하는 백트래킹 구현 못함
//// -> 2차원 배열의 백트래킹 문제는 2개의 변수중 하나의 idx를 고정시키는 방식으로 구현
//// 여기서는 가로로 연속되서 이어지는 경우가 문제이므로 높이를 고정하고 가로를 바꿔주며 유망한지를 검사하는 것이 좋음
//// 시간초과가 잘걸려서 가지치기를 잘해주는 것이 포인트. 쓸데없는 작업 최대한 줄여주기
//
//int N, M, H;
//int Array[32][11], Array2[32][11];
//int visit[32][11];
//int cnt;
//int flag;
//
//struct point
//{
//	int x;
//	int y;
//	int connect;
//	int next;
//};
//
//vector<point> v;
//
//void input()
//{
//	cin >> N >> M >> H;
//
//	int a, b;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//
//		v.push_back({ b, a, 1, b + 1 });
//		visit[a][b] = true;
//	}
//}
//
//int check()
//{
//	for (int i = 1; i < N + 1; i++)
//		if (Array[H + 1][i] != i) return 0;
//
//	return 1;
//}
//
//void connect()
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		int x = v[i].x;
//		int y = v[i].y;
//		int next = v[i].next;
//
//		Array[y][x] = next;
//		Array[y][next] = x;
//	}
//
//	v.clear();
//}
//
//void init()
//{
//	memcpy(Array, Array2, sizeof(Array2));
//}
//
////추가할 사다리 입력하기
//void Add_connect(int Add_c)
//{
//	int cnt = 0;
//
//	for (int i = 1; i < H + 1; i++)
//	{
//		for (int j = 1; j < N + 1; j++)
//		{
//			if (visit[i][j] != 0)
//			{
//				Array[i][j] = j + 1;
//	//			Array[i][j + 1] = j;
//	//			cnt++;
//	//			if (cnt == (M + Add_c)) return;
//			}
//
//			else if (visit[i][j - 1] != 0)
//			{
//				Array[i][j] = j - 1;
//			}   //<- 이 방법도 느려서 통과 x
//		}
//	}
//
//	return;
//}
//
//void move(int n)
//{
//	int x = n;
//
//	////기존 시도 방법 : 직접 움직임 따라가기
//	//for (int h = 1; h < H + 2; h++)
//	//{
//	//	if (h == H + 1)
//	//	{
//	//		Array[h][x] = n;
//	//		break;
//	//	}
//
//	//	if (Array[h][x] == 0) continue;
//	//	else
//	//		x = Array[h][x];
//	//}
//
//	for (int h = 1; h < H + 2; h++)
//	{
//		if (h == H + 1)
//		{
//			Array[h][x] = n;
//			return;
//		}
//
//		if (Array[h][x] != 0)
//		{
//			if (Array[h][x + 1] != 0) x++;
//			else if (Array[h][x - 1] != 0) x--;
//		}
//	}
//
//	return;
//}
//
//bool move2(int n)
//{
//	int x = n;
//
//	for (int h = 1; h < H + 1; h++)
//	{
//		if (visit[h][x] == 1) x++;
//		else if (visit[h][x - 1] == 1) x--;
//	}
//
//	if(x == n) return true;
//	else return false;
//}
//
//bool Game()
//{
//	for (int i = 1; i < N + 1; i++)
//	{
//		int x = i;
//
//		for (int h = 1; h < H + 1; h++)
//		{
//			if (visit[h][x] == 1) x++;
//			else if (visit[h][x - 1] == 1) x--;
//		}
//
//		if (x != i) return false;
//	}
//
//	return true;
//}
//
////사다리 추가 백트래킹
//void add(int idx, int cnt, int C)
//{
//	if (cnt == C)
//	{
//		init();
////		Add_connect(cnt);   //move1 방법쓸때 사용 -> 직접 모두 연결한 다음 전부 따라가며 움직여보기 -> 시간초과
//
//		//모든 경우 검사하면 시간초과 걸림, 하나라도 오답 나오는 순간 바로 return 해줘서 쓸데없는 작업 줄여줘야 시간초과 안걸림
//		int ans_cnt = 0;
//		for (int i = 1; i < N + 1; i++)
//		{	//	move(i);
//				int ch = move2(i);
//				if (ch == 0) return;
//				else ans_cnt++;
//		}
//
////		int ans = check();
//
//		if (ans_cnt == N) flag = 1;
//
//		////블로그 대로 
//		//if (Game() == true)
//		//{
//		//	flag = 1;
//		//	return;
//		//}
//
//		return;
//	}
//
//	for (int i = idx; i < H + 1; i++)
//	{
//		for (int j = 1; j < N; j++)
//		{
//			if (visit[i][j] == 1) continue; //이미 체크한 곳
//			else if (visit[i][j - 1] == 1) continue; //연속되는 경우
//			else if (visit[i][j + 1] == 1) continue; //연속되는 경우
//
//			visit[i][j] = true;
//			add(i, cnt + 1, C);
//			visit[i][j] = false;
//		}
//	}
//
//	return;
//}
//
//void solve()
//{
//	// 주어진 사다리 정보에 따라 긋기
//	connect();
//	memcpy(Array2, Array, sizeof(Array));
//
//	cnt = -1;
//
//	for (int i = 0; i < 4; i++)
//	{
//		init();
//		add(1, 0, i);
//		if (flag == 1)
//		{
//			cout << i << endl;
//			return;
//		}
//	}
//
//	cout << cnt << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	input();
//
//	solve();
//
//	return 0;
//}