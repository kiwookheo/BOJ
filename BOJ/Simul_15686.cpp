#include <bits/stdc++.h>
using namespace std; 
#define X first
#define Y second

int n, m;
int board[52][52];
vector<pair<int, int>> home;
vector<pair<int, int>> chic;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				home.push_back({ i,j });
			if (board[i][j] == 2)
				chic.push_back({ i,j });
		}
	}
	vector<int> brute(chic.size(), 1);
	fill(brute.begin(), brute.begin() + chic.size() - m, 0);
	int mn = 0x7f7f7f7f;
	do {
		int dist = 0;
		for (auto h : home) {
			int tmp = 0x7f7f7f7f;
			for (int i = 0; i < chic.size(); i++) {
				if (brute[i] == 0) continue;
				tmp = min(tmp,abs( chic[i].X - h.X ) + abs( chic[i].Y - h.Y ));
			}
			dist += tmp;	
		}
		mn = min(mn, dist);
	} while (next_permutation(brute.begin(), brute.end()));
	cout << mn;
}