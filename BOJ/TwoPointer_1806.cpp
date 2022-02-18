#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s;
	int en = 0;
	cin >> n >> s;
	int a[1000001];
	int mn = 0x7fffffff;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int st = 0; st < n; st++) {
		while (sum < s && en < n) {
			sum += a[en];
			en++;
		}
		if (sum >= s) {
			mn = min(mn, en - st);
			sum -= a[st];
		}
		else if (sum < s && en >= n)
			break;
	}
	if (mn == 0x7fffffff)
		cout << 0;
	else
		cout << mn;
}