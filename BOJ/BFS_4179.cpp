/*#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

/* 이 문제 같은 경우는 지훈이와 불에 대한 BFS를 각각 만들어줘야 해. 일단 불에 대한 BFS 탐색을 마친 후
 불의 시간이 저장된 dist가 있겠지?? 그걸 가지고 지훈이 BFS와 비교를 하는거야 만약 지훈이 BFS를 돌렸는데 
 #(벽)을 만나거나 불이 이미 번졌다면(불의 DIST가 더 작다면) 그곳으로는 못가겠지 그렇게 진행을 하다가 만약 범위를 벗어나게 되면
 (탈출을 성공한다면) 탈출한 dist를 출력하면 되고 아니면 IMPOSSIBLE을 출력하면 되겠지

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    int nx, ny;//현재 좌표
    int x = 0, y = 0;
    int n, m, i, j, dir;
    int ans = 0;
    cin >> n >> m;

    string* board = new string[n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        cin >> board[i];

    int** dist1 = new int* [n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        dist1[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dist1[i][j] = -1;
        }
    }

    int** dist2 = new int* [n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        dist2[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dist2[i][j] = -1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                q1.push({ i,j });
                dist1[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                q2.push({ i,j });
                dist2[i][j] = 0;
            }
                
        }
    }

    while (!q1.empty()) {
        pair<int, int> cur = q1.front();
        q1.pop();
        for (dir = 0; dir < 4; dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny]=='#' || dist1[nx][ny] >= 0)
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({ nx,ny });
        }
    }

    while (!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();
        for (dir = 0; dir < 4; dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || dist2[nx][ny] >= 0)
                continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
                continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({ nx,ny });
        }
    }

    cout << "IMPOSSIBLE";
}*/