#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<>> pq;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		pq.push(x);
	}
	
	int res = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		res += a + b;
		pq.push(a + b);
	}
	cout << res;
}