#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

/*기본적으로 모든 1들을 다 방문해야 해. 그 와중에 그림의 개수를 세야하겠지? 일단 시작점 0,0부터 검사를 할 것이고 상하좌우 뻗어나갈것이다. 만약 끊긴다면, 즉 상하좌우 모두 0 값을 만난다면?
 다음 출발값은 어디로 가야할까? 우리 0,0부터 했으니까 0,1을 검사해야할까? 이런식으로 다음 0이 아닌 값이 나오는 좌표에서 다시 시작해야 하는 것인가? 뭔가 살짝 비효율적인것 같기도 하다.
 이미 방문해서 1인 값을 알고 있으니까. 하지만 이 방법말고는 애매한 것 같네. 그림이 어떤 식으로 생겼는지 모르니까, 아무래도 개별 그림의 시작점을 저장하는 변수도 하나 만들어야겠다. 
 0,0부터 검사해서 n,m까지 검사하겠지. 그러는 동시에 큐가 비었을 때 그림 개수를 저장하는 count를 1씩 더해주면 되겠다. 우리가 출력해야할 정보는 그림의 개수와 가장 큰 그림의 넓이니까 
 넓이를 저장해주는 변수도 필요하겠지 또한 각 그림에서 넓이를 계산하는 변수도 필요할 것 같아. 넓이는 큐가 비었을 때 현재 제일 넓은 넓이와 비교하는 식으로 하면 될 것 같아. 코드를 짜보자
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    int count = 0;//그림의 개수
    int maxWidth=0;//그림의 최대 넓이
    int nowWidth;//그림의 현재 넓이
    int nx, ny;//현재 좌표
    int x=0, y=0;//현재 그림의 시작 좌표
    int n, m, i, j, dir;
	cin >> n >> m;
    int** board = new int* [n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
        board[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int** vis = new int* [n];
    for (i = 0; i < n; i++)//2차원 배열 동적 할당
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