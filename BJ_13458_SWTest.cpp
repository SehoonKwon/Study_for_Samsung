//#include <iostream>
//using namespace std;
//
//#define endl "\n"
//
////N 최대값이 100만이므로 N^2으로는 절대 통과못함
////최악의 경우 : 총감독, 부감독들이 1명만 감시 가능할때 각 시험장마다 인원이 최대로 차있으면 필요한 감독수는 (1 + 99만) * N개 => 100만^2
////long int = int !! long long int로 해야함, long long int => int * 4배,  90억대
//
//int N, B, C;
//int Array[1000001];
//long long int ans = 0;
//
//void input()
//{
//	cin >> N;
//	for (int i = 1; i < N + 1; i++)
//		cin >> Array[i];
//
//	cin >> B >> C;
//}
//
////부감독 수 구하기
//int calcul(int x)
//{
//	int res = Array[x] / C;
//
//	if ((res * C) == Array[x]) return res;
//	else return res + 1;
//}
//
//void solve()
//{
//	//각 시험장마다 총시험감독관 1명 필수배치.
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		int cnt = 0;
//		
//		//총시험감독관 배치
//		Array[i] -= B;
//		ans++;
//
//		//총시험감독관으로도 충분하면 다음 시험장
//		if (Array[i] <= 0)
//			continue;
//
//		//남은 인원만큼 부감독 명수 채우기
//		cnt = calcul(i);
//
//		ans += cnt;
//	}
//
//	cout << ans << endl;
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