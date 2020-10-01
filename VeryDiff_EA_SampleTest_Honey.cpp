//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//#define endl "\n"
//
////다시 하나하나 생각해보며 따라가봅시다
//
//int N, M, C;
//int Array[11][11];
//int visit[11][11];
//int ans = 0;
//
//vector<int> Worker[2];
//
//void input()
//{
//	cin >> N >> M >> C;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> Array[i][j];
//}
//
//int calcul(int Person, int idx, int cnt, int sum, int profit)
//{
//	//개수나 용량을 초과한 경우 -1 리턴
//	if (cnt > M || sum > C) return -1;
//
//	//M개 탐색 완료
//	if (idx == M) return profit;
//
//	//visit을 사용하지 않고 백트래킹 ! e.g) 수영장 문제.
//
//	//선택된 M개중 해당 idx 꿀을 담는경우
//	int take = calcul(Person, idx + 1, cnt + 1, sum + Worker[Person][idx], profit + pow(Worker[Person][idx], 2));
//
//	//idx꿀을 담지 않는 경우
//	int nontake = calcul(Person, idx + 1, cnt + 1, sum, profit);
//
//	int re = 0;
//
//	if (take != -1) re = take;
//	if (nontake != -1 && take < nontake) re = nontake;
//
//	return re;
//
//	////두 경우중 최댓값을 return
//	//return max(take, nontake);
//}
//
//void gather(int Person, int y)
//{
//	//2명 다 채집이 끝난 경우 수익 정산
//	if (Person == 2)
//	{
//		int sum = calcul(0, 0, 0, 0, 0) + calcul(1, 0, 0, 0, 0);
//		ans = max(ans, sum);
//		return;
//	}
//
//	// y번째부터 하는 이유는 위에서부터 모든 경우의 수를 하면서 내려오기 때문에 굳이 다시 0부터 할 필요가 없음
//	// e.g) 1번이 1,2번 체크하고 2번이 10, 11체크하는 경우는 1번이 10, 11 체크할 때 2번이 1, 2를 체크하는 경우와 같으므로 값이 똑같다. 따라서 쓸모없는 연산.
//	for (int i = y; i < N; i++)
//	{
//		for (int j = 0; j < N; j++) // 단순히 j < N 으로 하면 오답. 범위 넘어가는 경우를 처리해줘야 하나봄. j < N 으로 할거면 68 line 처럼 예외처리 추가
//		{
//			if (j + M > N) continue;
//
//			int flag = true;
//
//			// M개의 칸 중 이미 선택된 곳이 있으면 연속해서 M개를 선택 못하는 경우므로 다음 탐색으로
//			for (int k = j; k < j + M; k++)
//				if (visit[i][k] == true)
//				{
//					flag = false;
//					break;
//				}
//
//			if (flag == false) continue;
//
//			//탐색이 가능한 경우
//
//			//선택 표시하고 벡터에 넣기
//			for (int k = j; k < j + M; k++)
//			{
//				visit[i][k] = true;
//				Worker[Person].push_back(Array[i][k]);
//			}
//
//			gather(Person + 1, i);
//
//			//선택표시 지우기
//			for (int k = j; k < j + M; k++)
//			{
//				visit[i][k] = false;
//				Worker[Person].pop_back();
//			}
//		}
//	}
//}
//
//void solve()
//{
//	//1번이 채취한다음 그 환경에서의 최대값 구하기 -> 반복갱신
//
//	gather(0, 0); // i 인덱스(2번째 인자)를 넣어줌으로써 쓸모없는 연산을 줄여줌. 안넣을 경우 시간초과. 설명은 55 Line
//
//	cout << ans << endl;
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int T;
//	cin >> T;
//	for (int num = 1; num < T + 1; num++)
//	{
//		Worker[0].clear();
//		Worker[1].clear();
//		memset(visit, 0, sizeof(visit));
//		memset(Array, 0, sizeof(Array));
//		ans = 0;
//
//		input();
//
//		cout << "#" << num << " ";
//		solve();
//	}
//
//	return 0;
//}