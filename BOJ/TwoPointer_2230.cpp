#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[100001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int en = 1;
	int mn = 0x7fffffff;
	sort(a, a + n);
	for (int st = 0; st < n-1; st++) {
		while (1) {
			if (a[en] - a[st] >= m) {
				mn = min(a[en] - a[st], mn);
				break;
			}
			if (en == n) {
				break;
			}
			en++;
		}
	}
	cout << mn;
	return 0;
}