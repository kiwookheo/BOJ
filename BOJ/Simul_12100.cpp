//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//int board1[22][22];
//int board2[22][22];
//
//
//void func(int dir);
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) 
//		for (int j = 0; j < n; j++)
//			cin >> board1[i][j];
//	int mx = 0;
//	
//	for (int tmp = 0; tmp < 1024; tmp++) {
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				board2[i][j] = board1[i][j];
//
//		int brute = tmp;
//
//		for (int i = 0; i < 5; i++) {
//			int dir = brute % 4;
//			brute /= 4;
//			func(dir);
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				mx = max(mx, board2[i][j]);
//			}
//		}
//	}
//	cout << mx;
//}
//
//
//void func(int dir) {
//	int tmp[22][22];
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			tmp[i][j] = board2[i][j];
//		}
//	}
//	if (dir == 1) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				board2[i][j] = tmp[n - 1 - j][i];
//			}
//		}
//	}
//	else if (dir == 2) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				board2[i][j] = tmp[i][n-1-j];
//			}
//		}
//	}
//	else if (dir == 3) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				board2[i][j] = tmp[j][n - 1 - i];
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		int idx = 0;
//		int line[22] = { 0 };
//		for (int j = 0; j < n; j++) {
//			if (board2[i][j] == 0)
//				continue;
//			if (line[idx] == 0)
//				line[idx] = board2[i][j];
//			else if (board2[i][j] == line[idx])
//				line[idx++] *= 2;
//			else if (board2[i][j] != line[idx])
//				line[++idx] = board2[i][j];
//		}
//		for (int k = 0; k < n; k++) {
//			board2[i][k] = line[k];
//		}
//	}
//
//}