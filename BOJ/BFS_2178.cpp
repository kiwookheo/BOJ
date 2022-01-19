#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

/* �� ������ 0,0���� n,m������ �ִ� �Ÿ��� ���ϴ� ���̴�. �� �� �����ؾ� �� ���� �湮�ߴٰ� �ܼ��� 1�� ǥ���ϴ°��� �ƴ� �Ÿ��� ��Ÿ���� �Ÿ��� ���� 2���� �迭�� �־�߰ڳ�.
 �˻��� ��ǥ���� 1�̶�� �Ÿ� �迭 �ش� ��ǥ���� �Ÿ��� 1��ŭ �߰��ؾ߰���. 0,0���� n,m���� ���� �پ��� ����� �����ž� �� �پ��� ����� �ִ� �Ÿ��� ��� ���ұ�?
 �� �Ÿ��迭�� ���� ����ִ��� �˻����ָ� ��, �̹� ����ִٸ� �ٸ� �������� ���� ������ ���̰� �� ��ΰ� �ִ� �Ÿ��� �Ǵ� ���̰���. �׷��� ������ vis ��� dist �迭�� �湮 ���θ� �� �� �ְڳ�.
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    int nx, ny;//���� ��ǥ
    int x = 0, y = 0;
    int n, m, i, j, dir;
    cin >> n >> m;

    string* board = new string[n];
    for (i = 0; i < n; i++)//2���� �迭 ���� �Ҵ�
        cin >> board[i];

    int** dist = new int* [n];
    for (i = 0; i < n; i++)//2���� �迭 ���� �Ҵ�
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
}