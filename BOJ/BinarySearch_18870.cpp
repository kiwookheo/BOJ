#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[1000001];
	vector<int> tmp, uni;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tmp.push_back(a[i]);
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < n; i++) {
		if (i == 0 || tmp[i - 1] != tmp[i])
			uni.push_back(tmp[i]);
		
	}
	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << ' ';
	}
}