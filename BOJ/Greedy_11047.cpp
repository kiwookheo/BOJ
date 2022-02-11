#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, coin[15];
	cin >> n >> k;
	int tmp = n-1;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		ans += k / coin[i];
		k = k % coin[i];
		if (k == 0) {
			cout << ans;
			return 0;
		}
	}

}