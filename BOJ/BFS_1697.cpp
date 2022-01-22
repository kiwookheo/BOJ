//#include <bits/stdc++.h>
//using namespace std;
//
///*일단 이 문제는 다른 문제와는 다르게 BFS를 1차원 배열에서 탐색하는 것이다.
// X-1,X+1,2X를 탐색하는 것이고 거기에 시간을 입력하다가 목적지가 나오면 멈추는 그런 문제이다.
// 언니의 위치와 동생의 위치를 입력받고 시작점은 언니의 위치가 된다.
// 언니의 위치에서 X-1,X+1,2X를 모두 큐에 넣고 계속 진행하다가 동생의 위치가 나오면 멈춘다.
//*/
//
//int main() {
//	queue<int> q;
//	int n, k;
//	cin >> n >> k;
//	int dist[100002];
//	for (int i = 0; i < 100002; i++)
//		dist[i] = -1;
//	q.push(n);
//	dist[n] = 0;
//	while (dist[k]==-1) {
//		int cur = q.front();
//		q.pop();
//		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
//			if (nxt < 0 || nxt >= 100002)
//				continue;
//			if (dist[nxt] != -1)
//				continue;
//			dist[nxt] = dist[cur] + 1;
//			q.push(nxt);
//		}
//	}
//	cout << dist[k];
//}