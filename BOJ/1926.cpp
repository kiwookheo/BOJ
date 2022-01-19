#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

/*�⺻������ ��� 1���� �� �湮�ؾ� ��. �� ���߿� �׸��� ������ �����ϰ���? �ϴ� ������ 0,0���� �˻縦 �� ���̰� �����¿� ��������̴�. ���� ����ٸ�, �� �����¿� ��� 0 ���� �����ٸ�?
 ���� ��߰��� ���� �����ұ�? �츮 0,0���� �����ϱ� 0,1�� �˻��ؾ��ұ�? �̷������� ���� 0�� �ƴ� ���� ������ ��ǥ���� �ٽ� �����ؾ� �ϴ� ���ΰ�? ���� ��¦ ��ȿ�����ΰ� ���⵵ �ϴ�.
 �̹� �湮�ؼ� 1�� ���� �˰� �����ϱ�. ������ �� �������� �ָ��� �� ����. �׸��� � ������ ������� �𸣴ϱ�, �ƹ����� ���� �׸��� �������� �����ϴ� ������ �ϳ� �����߰ڴ�. 
 0,0���� �˻��ؼ� n,m���� �˻��ϰ���. �׷��� ���ÿ� ť�� ����� �� �׸� ������ �����ϴ� count�� 1�� �����ָ� �ǰڴ�. �츮�� ����ؾ��� ������ �׸��� ������ ���� ū �׸��� ���̴ϱ� 
 ���̸� �������ִ� ������ �ʿ��ϰ��� ���� �� �׸����� ���̸� ����ϴ� ������ �ʿ��� �� ����. ���̴� ť�� ����� �� ���� ���� ���� ���̿� ���ϴ� ������ �ϸ� �� �� ����. �ڵ带 ¥����
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    int count = 0;//�׸��� ����
    int maxWidth=0;//�׸��� �ִ� ����
    int nowWidth;//�׸��� ���� ����
    int nx, ny;//���� ��ǥ
    int x=0, y=0;//���� �׸��� ���� ��ǥ
    int n, m, i, j, dir;
	cin >> n >> m;
    int** board = new int* [n];
    for (i = 0; i < n; i++)//2���� �迭 ���� �Ҵ�
        board[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int** vis = new int* [n];
    for (i = 0; i < n; i++)//2���� �迭 ���� �Ҵ�
        vis[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j]=0;
        }
    }
   
    for (x = 0; x < n; x++) {
        for (y = 0; y < m; y++) {
            if (vis[x][y]==0 && board[x][y] == 1) {
                q.push({ x,y });
                vis[x][y] = 1;
                nowWidth = 1;
                while (!q.empty()) {
                    pair <int, int> cur = q.front();
                    q.pop();
                   
                    for (dir = 0; dir < 4; dir++) {
                        nx = cur.X + dx[dir];
                        ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (vis[nx][ny]==1 || board[nx][ny] == 0)
                            continue;
                        vis[nx][ny] = 1;
                        nowWidth++;
                        q.push({ nx,ny });
                    }
                    
                }
                count++;
                if (maxWidth < nowWidth)
                    maxWidth = nowWidth;
                    
            }
        }
    }
    
    cout << count << endl << maxWidth;
    
    

}