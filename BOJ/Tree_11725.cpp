#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> adj[100005];
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int p[100005];

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (p[cur] == nxt) continue;
			q.push(nxt);
			p[nxt] = cur;
		}
	}
	for (int i = 2; i <= n; i++) 
		cout << p[i] << '\n';
}