#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int a[100001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int mx = 0;
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		mx = max(mx , a[i] * (n - i));
	}
	cout << mx;
}