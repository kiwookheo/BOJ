/*#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

/* 이 문제는 익은 토마토가 하루가 지나면 인접한 익지 않은 토마토를 익게 만든다. 상자에 빈 공간도 있다.
 즉 이 문제는 박스에 익은 토마토가 어느 좌표에 있고, 그 좌표마다 각각 BFS를 실행시키면 될 것 같다.
 그래서 이미 토마토가 들어 있다면 그 좌표를 큐에 추가해주고 토마토가 익지 않았다면 -1로 거리를 설정해준다.
 dist배열에는 토마토가 없다면 0, 익지 않은 토마토는 -1이 기본값이다. 
 기준이 되는 토마토로부터 거리를 구하는 것이나 마찬가지이다. 각각 dist배열에 거리를 추가해주고, 마지막에 검사를 해서
 익지 않은 토마토가 있다면 -1을 출력, 모두 익었다면 가장 큰 dist값을 출력하면 끝

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    int nx, ny;//현재 좌표
    int x = 0, y = 0;
    int n, m, i, j, dir;
    int ans = 0;
    cin >> m >> n;

    int** dist = new int* [n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        dist[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dist[i][j] = 0;
        }
    }

    int** board = new int* [n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        board[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                q.push({ i,j });
            if (board[i][j] == 0)
                dist[i][j] = -1;

        }
    }
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (dir = 0; dir < 4; dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx,ny });
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}*/