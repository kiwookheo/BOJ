#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	while (t--) {
		int k;
		cin >> k;
		multiset<int> m;
		while (k--) {
			char a;
			int b;
			cin >> a >> b;
			if (a == 'D' && !m.empty()) {
				if (b == 1)
					m.erase(prev(m.end()));
				else if (b == -1)
					m.erase(m.begin());
			}
			else if (a == 'I')
				m.insert(b);
		}
		if (m.empty())
			cout << "EMPTY" << '\n';
		else 
			cout << *prev(m.end()) << " " << *m.begin() << '\n';
	}
}