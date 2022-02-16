#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n;
int rope[10001];

bool solve(ll md);

int main() {
	
	cin >> k >> n;
	
	int mx = 0;
	for (int i = 0; i < k; i++) {
		cin >> rope[i];
		mx = max(rope[i], mx);
	}
		
	
	ll st = 1, en = mx;
	while (st<en) {
		ll mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;
}

bool solve(ll md) {
	ll cnt = 0;
	for (int i = 0; i < k; i++) 
		cnt += rope[i] / md;
	return cnt >= n;
	
}