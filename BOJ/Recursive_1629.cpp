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
////��� Ǯ�� base condition�� �� �����ؾ� �ϰ�, k�� ����� ���� k+1, k+2�� ����� ���� �� �־�� �Ѵ�.
////�� ���� ���� 1���� �� ����� �� �ְ�, k ���� �� �� ����� ���� 2k�� 2k+1�� ����� ���� �� �մ�.
////res = res * res % c �� ���� ���� k���� 2k�� ����� ������ ���̰� �Ʒ� if-else ���� ���ϴ� ����� 2k�� 2k+1�̳Ŀ� ���� �޶����� ���̴�.