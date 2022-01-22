#include <bits/stdc++.h>
using namespace std;

void hanoi(int a, int b, int n);
int main() {
	int n, a, b;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(1, 3, n);
}

void hanoi(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	hanoi(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	hanoi(6 - a - b, b, n - 1);
}
//재귀함수의 표본, 하노이의 탑. 모든 재귀함수를 코드로 설계하는 것에는 공식이 있다.
//첫 번째 base condition 설정, 두 번째 n개일 때 실행하면 어떤 식으로 동작을 하는지.
//n개의 원판을 옮긴다면, 
//1.n-1개를 기둥1에서 2로 옮긴다.->hanoi(a,6-a-b,n-1)
//2.n번째 원판 한개를 기둥1에서 3으로 옮긴다.->cout << a << ' ' << b << endl; (한 개니까 재귀 필요 없이 바로 출력. 마치 base condition과 같은 조건)
//3.n-1개를 다시 기둥 2에서 3으로 옮긴다.->hanoi(6-a-b,b,n-1)
//6-a-b는 기둥이 3개니까 자연스럽게 기둥 2개를 뺀 나머지 기둥이 된다.
//하노이의 탑의 총 이동횟수는 1->3->7->15 ..... 등비수열로 이루어진 계차수열이다. 계차수열의 일반항은 a(초항)+등비수열의합이다. 등비수열의 일반항은 2^n이고 
//2^n의 합은 a(2^n-1)/(2-1) = 2(2^n-1) = 2^n - 2이다. 즉 일반항은 a+ 2^n - 2 = 1 + 2^n - 2 = 2^n - 1 이다.