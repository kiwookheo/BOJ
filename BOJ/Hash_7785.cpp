#include <bits/stdc++.h>
using namespace std;

  int main() {
	int n;
	cin >> n;
	unordered_map<string, string> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		m[a] = b;
	}
	for (auto it = m.begin(); it != m.end();) {
		if (it->second == "leave")
			it = m.erase(it);
		else
			++it;
	}
	vector<string> v;
	for (auto e : m) {
		v.push_back(e.first);
	}

	sort(v.begin(), v.end(),greater<string>());
	for (auto e : v) {
		cout << e << '\n';
	}
}