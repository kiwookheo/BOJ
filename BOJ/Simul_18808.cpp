#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int note[42][42];
int paper[12][12];

void rotate();
bool pastable(int x, int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int result = 0;
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> paper[i][j];
			}
		}
		for (int rot = 0; rot < 4; rot++) {
			bool isPaste = false;
			for (int i = 0; i <= n - r; i++) {
				if (isPaste)
					break;
				for (int j = 0; j <= m - c; j++) {
					if (pastable(i, j)) {
						isPaste = true;
						break;
					}		
				}
			}
			if (isPaste)
				break;
			rotate();
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result += note[i][j];
		}
	}
	cout << result << '\n';
}

void rotate() {
	int tmp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = paper[i][j];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			paper[i][j] = tmp[r - 1 - j][i];
		}
	}
	swap(r, c);
}

bool pastable(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (note[x+i][y+j] == 1 && paper[i][j] == 1) {
				return false;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (paper[i][j] == 1) {
				note[x + i][y + j] = 1;
			}
		}
	}
	return true;
}
