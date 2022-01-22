//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//ll func1(ll a, ll b, ll c);
//
//int main() {
//	ll ans, a, b, c;
//	cin >> a >> b >> c;
//	ans = func1(a, b, c);
//	cout << ans;
//}
//
//ll func1(ll a, ll b, ll c) {
//	ll res;
//	if (b == 1) {
//		res = a % c;
//		return res;
//	}
//	else {
//		res = func1(a, b / 2, c);
//		res = res * res % c;
//		if (b % 2 == 0) return res;
//		else return res * a % c;
//	}
//
//}
////재귀 풀때 base condition을 잘 설정해야 하고, k의 결과를 토대로 k+1, k+2의 결과를 구할 수 있어야 한다.
////위 같은 경우는 1승일 때 계산할 수 있고, k 승일 때 그 결과를 토대로 2k와 2k+1의 결과를 구할 수 잇다.
////res = res * res % c 를 해준 것은 k에서 2k의 결과를 도출한 것이고 아래 if-else 문은 원하는 결과가 2k냐 2k+1이냐에 따라 달라지는 것이다.