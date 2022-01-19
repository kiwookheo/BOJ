/*#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

/* 이 문제는 0,0에서 n,m까지의 최단 거리를 구하는 것이다. 이 때 생각해야 할 것이 방문했다고 단순히 1을 표시하는것이 아닌 거리를 나타내는 거리에 대한 2차원 배열이 있어야겠네.
 검사한 좌표값이 1이라면 거리 배열 해당 좌표에도 거리를 1만큼 추가해야겠지. 0,0에서 n,m까지 가는 다양한 방법이 있을거야 이 다양한 방법중 최단 거리를 어떻게 구할까?
 그 거리배열에 값이 들어있는지 검사해주면 돼, 이미 들어있다면 다른 지점에서 빨리 도착한 것이고 그 경로가 최단 거리가 되는 것이겠지. 그러한 이유로 vis 대신 dist 배열로 방문 여부를 알 수 있겠네.


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    int nx, ny;//현재 좌표
    int x = 0, y = 0;
    int n, m, i, j, dir;
    cin >> n >> m;

    string* board = new string[n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        cin >> board[i];

    int** dist = new int* [n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        dist[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }

    q.push({ 0,0 });
    dist[0][0] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (dir = 0; dir < 4; dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if (nx<0 || nx>=n || ny<0 || ny>=m) 
                continue;
            if (board[nx][ny] != '1' || dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx,ny });
        }
    }
    cout << dist[n - 1][m - 1] + 1;
}*/