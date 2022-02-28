#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> mst[100001];
int p[305];

int getParent(int x) {
	if (p[x] == x) return x;
	return p[x] = getParent(p[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x > y) p[x] = y;
	else if (x < y) p[y] = x;
}

bool findParent(int x, int y) {
	return getParent(x) == getParent(y);
}

int main() {
	int v,e=1;
	cin >> v;
	for (int i = 1; i <= v+1; i++) 
		p[i] = i;
	
	for (int i = 1; i <= v; i++) {
		int cost;
		cin >> cost;
		mst[e++] = { cost,i,v + 1 };
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			int cost;
			cin >> cost;
			if (i >= j) continue;
			mst[e++] = { cost,i,j };
		}
	}
	v++;
	sort(mst, mst + e);
	int cnt = 0;
	int sum = 0;
	for (int i = 1; i <= e; i++) {
		int a, b, cost;
		tie(cost, a, b) = mst[i];
		if (findParent(a, b)) continue;
		sum += cost;
		unionParent(a, b);
		cnt++;
		if (cnt == v - 1) break;
	}
	cout << sum;
}