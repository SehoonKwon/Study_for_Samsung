//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//
//#define endl "\n"
//
////팀 분배는 했으나 계단 대기3명, 선착순 등을 이용해 구현하는거 존~~~~~~나 어려움
//
//int T, N;
//int Array[11][11];
//int S_num[11];
//int ans = 9999;
//
//struct P
//{
//	int x, y;
//	int dist1, dist2;
//};
//
//struct S
//{
//	int x, y, time;
//};
//
//vector<P> person;
//vector<S> stair;
//
//void input()
//{
//	cin >> N;
//	for (int i = 1; i < N + 1; i++)
//	{
//		for (int j = 1; j < N + 1; j++)
//		{
//			cin >> Array[i][j];
//			if (Array[i][j] > 1) stair.push_back({ j, i, Array[i][j] });
//			else if (Array[i][j] == 1) person.push_back({ j, i });
//		}
//	}
//}
//
//bool cmp1(const  P &v, const P &u)
//{
//	if (v.dist1 < u.dist1) return true;
//	else return false;
//}
//
//bool cmp2(const P& v, const P &u)
//{
//	if (v.dist2 < u.dist2) return true;
//	else return false;
//}
//
//int getTime1(vector<P> v)
//{
//	if (v.empty()) return 0;
//
//	//도착 순서대로 정렬
//	sort(v.begin(), v.end(), cmp1);
//
//	//계단은 3명만 이용가능하므로
//	int use[3] = { 0 };
//	int time = v[0].dist1; // 시작시간은 가장 가까운 이용자가 도착한 시간
//
//	while (1)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			//계단을 내려간 사람의경우 다음 사람
//			if (v[i].dist1 == 0) continue;
//
//			//도착시간 확인
//			if (v[i].dist1 <= time) //만약 도착시각이 현재시각보다 같거나 작은경우(=합당한 경우)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					//계단이용자가 빈경우가 있으면 투입
//					if (use[j] <= 0)
//					{
//						//내려가는데 걸리는시간. 밑에서 1분씩 차감
//						use[j] = stair[0].time;
//						v[i].dist1 = 0; //도착해서 계단이용했다고 표시
//
//						//마지막 사람인경우
//						if (i == v.size() - 1)
//						{
//							return time + stair[0].time; // +1; // 현재시각 + 계단내려가는 시간 + 대기하는시간 1분 
//						}
//
//						break;
//					}
//
//
//				}
//			}
//		}
//
//		//모든 사람 체크한 뒤 계단 한칸씩 내려가기
//		for (int i = 0; i < 3; i++)
//			use[i]--;
//
//		time++;
//	}
//}
//
//int getTime2(vector<P> v)
//{
//	if (v.empty()) return 0;
//
//	//도착 순서대로 정렬
//	sort(v.begin(), v.end(), cmp2);
//
//	//계단은 3명만 이용가능하므로
//	int use[3] = { 0 };
//	int time = v[0].dist2; // 시작시간은 가장 가까운 이용자가 도착한 시간
//
//	while (1)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			//이미 도착한 사람의경우 다음 사람
//			if (v[i].dist2 == 0) continue;
//
//			//도착시간 확인
//			if (v[i].dist2 <= time) //만약 도착시각이 현재시각보다 같거나 작은경우(=합당한 경우)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					//계단이용자가 빈경우가 있으면 투입
//					if (use[j] <= 0)
//					{
//						//내려가는데 걸리는시간. 밑에서 1분씩 차감
//						use[j] = stair[1].time;
//						v[i].dist2 = 0; //도착해서 계단이용했다고 표시
//
//						//마지막 사람인경우
//						if (i == v.size() - 1)
//						{
//							return time + stair[1].time; // +1; // 현재시각 + 계단내려가는 시간 + 대기하는시간 1분 
//						}
//
//						break;
//					}
//
//
//				}
//			}
//		}
//
//		//모든 사람 체크한 뒤 계단 한칸씩 내려가기
//		for (int i = 0; i < 3; i++)
//			use[i]--;
//
//		time++;
//	}
//}
//
//void DFS(int idx)
//{
//	if (idx == person.size())
//	{
//		//계단 나누기
//
//		vector<P> v1, v2;
//		for (int i = 0; i < person.size(); i++)
//		{
//			if (S_num[i] == 1) v1.push_back(person[i]);
//			else v2.push_back(person[i]);
//		}
//
//		ans = min(ans, max(getTime1(v1), getTime2(v2)));
//		return;
//	}
//
//	// idx번째 사람 1번 계단 이용
//	S_num[idx] = 1;
//	DFS(idx + 1);
//
//
//	// 2번 계단 이용
//	S_num[idx] = 2;
//	DFS(idx + 1);
//}
//
//void solve()
//{
//	//각 사람당 출구까지의 거리 구하기
//	for (int i = 0; i < person.size(); i++)
//	{
//		person[i].dist1 = abs(person[i].x - stair[0].x) + abs(person[i].y - stair[0].y);
//		person[i].dist2 = abs(person[i].x - stair[1].x) + abs(person[i].y - stair[1].y);
//	}
//
//	//DFS로 각각 어느 출구로 갈지 조합정한 다음에 BFS로 시간 구하고 최솟값 갱신하기
//	DFS(0);
//
//	cout << ans << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	cin >> T;
////	T = 1;
//	for (int num = 1; num < T + 1; num++)
//	{
//		memset(Array, 0, sizeof(Array));
//		person.clear();
//		stair.clear();
//		ans = 9999;
//
//		input();
//
//		cout << "#" << num << " ";
//		solve();
//	}
//	return 0;
//}