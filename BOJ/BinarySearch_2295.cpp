#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1001];
	vector<int> two;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
			two.push_back(a[i] + a[j]);
	}
	
	two.erase(unique(two.begin(), two.end()), two.end());
	sort(two.begin(), two.end());

	for (int l = n - 1; l >= 0; l--) {
		for (int k = 0; k < n; k++) {
			if (binary_search(two.begin(),two.end(),a[l]-a[k])) {
				cout << a[l];
				return 0;
			}
		}
	}
}