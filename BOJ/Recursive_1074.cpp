#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c);
int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int base = (1 << n-1);
	if (r < base && c < base) return func(n-1, r, c);
	else if (r < base && c >= base) return base * base + func(n-1, r, c-base);
	else if (r >= base && c < base) return 2 * base * base + func(n-1, r-base, c);
	else return 3 * base * base + func(n-1, r-base, c-base);
}

//base condition 설정 : 0,0일 때 0이다
//4사분면이 존재한다. 그 크기가 달라지는 것 뿐 각 4사분면이 결국 n칸에서 한 칸이 될 때 까지 재귀.각 사분면의 시작 좌표를 알아야 한다. 
//n이 2이고 4x4일 때 2사분면은 0, 1사분면은 4, 3사분면은 8, 4사분면은 16이다.
//n이 3이고 8x8일 때 0,16,32,48이다.
//n=2 => 0->4->8->16 / n=3 => 0->16->32->48 / 그다음은? n=4 => 0->64->128->192 일 것이다.
//처음은 무조건 0이고 그 다음은 2x2 / 4x4 / 8x8 로 뻗어나간다. 그럼 그 다음은 16x16일 것이다. 
//즉 두 번째 시작점은 2^n-1 x 2^n-1이다. 세 번째 시작점은 두 번재 시작점의 두배. 마지막은 세 배.
//2^n-1을 변수로 둔다면 기준이 네가지가 될 것이다. 
//r,c가 2^n-1보다 작을경우 (2사분면)
//r은 크고 c는 작을 경우 (1사분면)
//r은 작고 c가 클 경우 (3사분면)
//r,c 모두 클 경우 (4사분면)
//진짜 재귀 쉽다. 그냥 솔직히 말해? n=1일 일때랑 n이 n일 때만 성립하면 끝. 쉽게생각해 절대 절차의 늪에 빠지지 마..