#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int d[10001];
	int s;
	cin >> s;
	d[1] = 0;
	for (int i = 2; i <= s; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)  d[i] = min(d[i] , d[i / 2] + 1);
		if (i % 3 == 0)  d[i] = min(d[i] , d[i / 3] + 1);
	}
	cout << d[s];
}
