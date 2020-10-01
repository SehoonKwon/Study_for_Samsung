//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//using namespace std;
//
////몇번 더 풀어봅시다
//
//int N, M, K;
//int dx[] = { -1,0,1,-1,1,-1,0,1 };
//int dy[] = { -1,-1,-1, 0, 0,1,1,1 };
//int A[11][11]; //해당 칸에 추가되는 양분
//int d[11][11]; //해당 칸의 양분
//int p[11][11]; //해당 칸에 있는 추가될 나무의 수
//vector<int> tree[11][11]; //해당 칸에 있는 나무들. 나이 정보를 통해 정렬하므로 int형
//
//void init()
//{
//	for (int i = 1; i < N + 1; i++)
//		for (int j = 1; j < N + 1; j++)
//			d[i][j] = 5; //초기 양분
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
//			cin >> A[i][j]; //매년 추가되는 양분
//		}
//
//	int x, y, age;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> x >> y >> age;
//		tree[x][y].push_back(age); //이게 [y][x]로 하면 틀림. why? = r,c로 설명하고 뒤에 이어서 좌표를 x,y로 했기때문에 r == x, c == y이다!
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
//		//계절을 나누지 않고 각 칸에 대해서 실행. 계절 별로 나누면 2중포문을 4번. 이렇게 하면 2중포문 1번
//		for (int i = 1; i < N + 1; i++)
//		{
//			for (int j = 1; j < N + 1; j++)
//			{
//				sort(tree[i][j].begin(), tree[i][j].end()); // 해당 칸의 나이 순으로 정렬
//
//				vector<int> temp; //tree업데이트용
//				int dead = 0; // 죽은 나무들로 인해 생긴 양분
//				for (int k = 0; k < tree[i][j].size(); k++) //for(int x : tree[i][j]) 이 문법 알아두기. ==> x = tree[i][j][0] -> x = tree[i][j][1] ->...
//				{
//					//자기만큼 양분이 있으면
//					if (tree[i][j][k] <= d[i][j])
//					{
//						temp.push_back(tree[i][j][k] + 1);
//						d[i][j] -= tree[i][j][k];
//					}
//					else
//					{
//						dead += (tree[i][j][k] / 2); //여름 과정에 해당
//					}
//				}
//
//				//가을 과정
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
//				//겨울
//				d[i][j] += A[i][j] + dead;
//				tree[i][j] = temp;
//			}
//		}
//
//		//다 끝나면 번식된 나무들 추가
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