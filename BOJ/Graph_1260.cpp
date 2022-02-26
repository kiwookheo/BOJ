#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool vis[1005];

int n, m, f;

void dfs(int cur) { // Àç±Í dfs
	vis[cur] = true;
	cout << cur << ' ';
	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}

void bfs() {
	queue<int> q;
	q.push(f);
	vis[f] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}


int main() {
	cin >> n >> m >> f;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(f);
	cout << '\n';
	fill(vis + 1, vis + n + 1, false);
	bfs();
	
}