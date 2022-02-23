#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> u;
	string s[100000];
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		u[name] = i;
		s[i] = name;
	}
	while (m--) {
		string name;
		cin >> name;
		if (isdigit(name[0])) {
			cout << s[stoi(name)] << '\n';
		}
		else
			cout << u[name] << '\n';
	}
}