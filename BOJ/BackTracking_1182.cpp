//#include <bits/stdc++.h>
//using namespace std;
//
//void func(int cur,int sum);
//
//int n, s, cnt=0;
//int arr[20];
//
//int main() {
//	cin >> n >> s;
//	for (int i = 0; i < n; i++) 
//		cin >> arr[i];
//	func(0, 0);
//	if (s == 0) cnt--;
//	cout << cnt;
//}
//
//void func(int cur, int sum) {
//	if (cur == n) {
//		if (sum == s) 
//			cnt++;
//		return;
//	}
//	func(cur + 1, sum);
//	func(cur + 1, sum + arr[cur]);
//}