#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int array1[225];
int array2[225];
int array3[225];

void func(int cur);

int main() {
	cin >> n;
	func(0);
	cout << cnt;
}

void func(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (array1[i] != 0 || array2[cur + i] != 0 || array3[cur - i + n - 1] != 0)
			continue;
		array1[i] = 1;
		array2[cur + i] = 1;
		array3[cur - i + n - 1] = 1;
		func(cur + 1);
		array1[i] = 0;
		array2[cur + i] = 0;
		array3[cur - i + n - 1] = 0;
	}

}