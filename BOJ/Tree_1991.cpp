#include <bits/stdc++.h>
using namespace std;

int n;
int lc[27];
int rc[27];

void preorder(int cur) {
	cout << char(cur + 'A' - 1);
	if (lc[cur] != 0) preorder(lc[cur]);
	if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
	if (lc[cur] != 0) inorder(lc[cur]);
	cout << char(cur + 'A' - 1);
	if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
	if (lc[cur] != 0) postorder(lc[cur]);
	if (rc[cur] != 0) postorder(rc[cur]);
	cout << char(cur + 'A' - 1);
}

int main() {
	cin >> n;
	while (n--) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') lc[a - 'A' + 1] = b - 'A' + 1;
		if (c != '.') rc[a - 'A' + 1] = c - 'A' + 1;
	}
	preorder(1); cout << '\n';
	inorder(1); cout << '\n';
	postorder(1); cout << '\n';
}