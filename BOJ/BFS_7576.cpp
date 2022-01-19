#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

/* �� ������ ���� �丶�䰡 �Ϸ簡 ������ ������ ���� ���� �丶�並 �Ͱ� �����. ���ڿ� �� ������ �ִ�.
 �� �� ������ �ڽ��� ���� �丶�䰡 ��� ��ǥ�� �ְ�, �� ��ǥ���� ���� BFS�� �����Ű�� �� �� ����.
 �׷��� �̹� �丶�䰡 ��� �ִٸ� �� ��ǥ�� ť�� �߰����ְ� �丶�䰡 ���� �ʾҴٸ� -1�� �Ÿ��� �������ش�.
 dist�迭���� �丶�䰡 ���ٸ� 0, ���� ���� �丶��� -1�� �⺻���̴�. 
 ������ �Ǵ� �丶��κ��� �Ÿ��� ���ϴ� ���̳� ���������̴�. ���� dist�迭�� �Ÿ��� �߰����ְ�, �������� �˻縦 �ؼ�
 ���� ���� �丶�䰡 �ִٸ� -1�� ���, ��� �;��ٸ� ���� ū dist���� ����ϸ� ��
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    int nx, ny;//���� ��ǥ
    int x = 0, y = 0;
    int n, m, i, j, dir;
    int ans = 0;
    cin >> m >> n;

    int** dist = new int* [n];
    for (i = 0; i < n; i++)//2���� �迭 ���� �Ҵ�
        dist[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dist[i][j] = 0;
        }
    }

    int** board = new int* [n];
    for (i = 0; i < n; i++)//2���� �迭 ���� �Ҵ�
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
}