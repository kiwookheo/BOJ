#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int k = n;
	int dp[1000001];
	int way[1000001];
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	way[1] = 0;
	way[2] = 1;
	way[3] = 1;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		way[i] = i - 1;
		if (i % 3 == 0) {
			if (dp[i / 3] + 1 < dp[i]) {
				dp[i] = dp[i / 3] + 1;
				way[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (dp[i / 2] + 1 < dp[i]) {
				dp[i] = dp[i / 2] + 1;
				way[i] = i / 2;
			}
		}
	}
	
	cout << dp[n] << '\n';
	
	do {
		cout << k << ' ';
		k = way[k];
	} while (dp[n]--);
}