//#include <bits/stdc++.h>
//using namespace std;
//
///*�ϴ� �� ������ �ٸ� �����ʹ� �ٸ��� BFS�� 1���� �迭���� Ž���ϴ� ���̴�.
// X-1,X+1,2X�� Ž���ϴ� ���̰� �ű⿡ �ð��� �Է��ϴٰ� �������� ������ ���ߴ� �׷� �����̴�.
// ����� ��ġ�� ������ ��ġ�� �Է¹ް� �������� ����� ��ġ�� �ȴ�.
// ����� ��ġ���� X-1,X+1,2X�� ��� ť�� �ְ� ��� �����ϴٰ� ������ ��ġ�� ������ �����.
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