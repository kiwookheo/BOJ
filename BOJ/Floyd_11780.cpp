#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int d[102][102];
	int nxt[102][102];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fill(d[i], d[i] + n + 1, INF);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
		nxt[a][b] = b;
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					nxt[i][j] = nxt[i][k];
				}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) cout << "0 ";
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 0 || d[i][j] == INF) {
				cout << '0' << '\n';
				continue;
			}
			vector<int> path;
			int st = i;
			while (st != j) {
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << ' ';
			for (auto x : path) cout << x << ' ';
			cout << '\n';
		}
	}
}