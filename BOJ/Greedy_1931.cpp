#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.Y == b.Y)
		return a.X < b.X;
	else
		return a.Y < b.Y;
}
int main() {
	int n;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), compare);
	
	int tmp = v[0].Y;
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (v[i].X >= tmp) {
			cnt++;
			tmp = v[i].Y;
		}
	}

	cout << cnt;

}