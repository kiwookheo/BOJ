//#include <bits/stdc++.h>
//using namespace std;
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n, m;
//	cin >> n >> m;
//	int dp[100001];
//	int res[100001];
//	res[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> dp[i];
//		res[i] = res[i - 1] + dp[i];
//	}
//	while (m--) {
//		int i, j;
//		cin >> i >> j;
//		cout << res[j] - res[i - 1] << '\n';
//	}
//}