#include <bits/stdc++.h>
using namespace std;

int Lower_Search(int t);
int Upper_Search(int t);

int num[500001];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	
	sort(num, num + n);
	int m;
	cin >> m;
	while (m--) {
		int k;
		cin >> k;
		int a = Lower_Search(k);
		int b = Upper_Search(k);
		cout << b - a << '\n';
	}
	
}

int Lower_Search(int t) {
	int st = 0;
	int en = n;

	while (st < en) {
		int mid = (st + en) / 2;
		if (num[mid] < t) 
			st = mid + 1;
		else
			en = mid;
	}
	return st;
}

int Upper_Search(int t) {
	int st = 0;
	int en = n;
	while (st < en) {
		int mid = (st + en) / 2;
		if (num[mid] <= t)
			st = mid + 1;
		else
			en = mid;
	}
	return st;
}