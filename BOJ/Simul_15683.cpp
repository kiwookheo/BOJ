#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int,int>> cctv;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
void draw(int x, int y, int dir);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int result = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i, j });
			if (board1[i][j] == 0)
				result++;
		}
	}

	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++)
				board2[i][j] = board1[i][j];

		int brute = tmp;

		for (int i = 0; i < cctv.size(); i++) {
			int x = cctv[i].X;
			int y = cctv[i].Y;
			int dir = brute % 4;
			brute /= 4;
			if (board1[x][y] == 1) 
				draw(x,y,dir);
			else if (board1[x][y] == 2) {
				draw(x,y,dir);
				draw(x,y,dir + 2);
			}
			else if (board1[x][y] == 3) {
				draw(x, y, dir);
				draw(x, y, dir + 1);
			}
			else if (board1[x][y] == 4) {
				draw(x, y, dir);
				draw(x, y, dir + 1);
				draw(x, y, dir + 2);
			}
			else if (board1[x][y] == 5) {
				draw(x, y, dir);
				draw(x, y, dir + 1);
				draw(x, y, dir + 2);
				draw(x, y, dir + 3);
			}		
		}

		int mn = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				if (board2[i][j] == 0)
					mn++;
		result = min(result, mn);
	}
	cout << result;
	
}

void draw(int x, int y, int dir) {
	dir %=  4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return;
		if (board2[x][y] != 0) continue;
		board2[x][y] = -1;
	}

}