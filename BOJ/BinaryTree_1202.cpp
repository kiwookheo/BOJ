#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	pair<int, int> mv[300003];
	multiset<int> bag;

	for (int i = 0; i < n; i++) 
		cin >> mv[i].second >> mv[i].first;

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}
	sort(mv, mv + n, greater<>());
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int v, m;
		tie(v, m) = mv[i];
		auto it = bag.lower_bound(m);
		if (it == bag.end()) continue;
		sum += v;
		bag.erase(it);
	}
	cout << sum;
}