//#include <iostream>
//#include <cstring>
//#include <vector>
//using namespace std;
//
//#define endl "\n"
//
////��ٸ� �����ϴ� ��Ʈ��ŷ ���� ����
//// -> 2���� �迭�� ��Ʈ��ŷ ������ 2���� ������ �ϳ��� idx�� ������Ű�� ������� ����
//// ���⼭�� ���η� ���ӵǼ� �̾����� ��찡 �����̹Ƿ� ���̸� �����ϰ� ���θ� �ٲ��ָ� ���������� �˻��ϴ� ���� ����
//// �ð��ʰ��� �߰ɷ��� ����ġ�⸦ �����ִ� ���� ����Ʈ. �������� �۾� �ִ��� �ٿ��ֱ�
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
////�߰��� ��ٸ� �Է��ϱ�
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
//			}   //<- �� ����� ������ ��� x
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
//	////���� �õ� ��� : ���� ������ ���󰡱�
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
////��ٸ� �߰� ��Ʈ��ŷ
//void add(int idx, int cnt, int C)
//{
//	if (cnt == C)
//	{
//		init();
////		Add_connect(cnt);   //move1 ������� ��� -> ���� ��� ������ ���� ���� ���󰡸� ���������� -> �ð��ʰ�
//
//		//��� ��� �˻��ϸ� �ð��ʰ� �ɸ�, �ϳ��� ���� ������ ���� �ٷ� return ���༭ �������� �۾� �ٿ���� �ð��ʰ� �Ȱɸ�
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
//		////��α� ��� 
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
//			if (visit[i][j] == 1) continue; //�̹� üũ�� ��
//			else if (visit[i][j - 1] == 1) continue; //���ӵǴ� ���
//			else if (visit[i][j + 1] == 1) continue; //���ӵǴ� ���
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
//	// �־��� ��ٸ� ������ ���� �߱�
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