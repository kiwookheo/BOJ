#include <bits/stdc++.h>
using namespace std;

void func(int n,int s);

int main() {
    int n;
    cin >> n;
    int s = n * 4;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
    func(n,s);
  
}

void func(int n,int s) {
    if (n == 0) {
        for (int i = s; i > n * 4; i--)
            cout << "_";
        cout << "\"����Լ��� ������?\"" << '\n';
        for (int i = s; i > n * 4; i--)
            cout << "_";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
        for (int i = s; i > n * 4; i--)
            cout << "_";
        cout << "��� �亯�Ͽ���." << '\n';
        return;
    }
    for (int i = s; i > n * 4; i--) 
        cout << "_";
    cout << "\"����Լ��� ������?\"" << '\n';
    for (int i = s; i > n * 4; i--)
        cout << "_";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
    for (int i = s; i > n * 4; i--)
        cout << "_";
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
    for (int i = s; i > n * 4; i--)
        cout << "_";
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
       
    func(n - 1,s);
    for (int i = s; i > n * 4; i--)
        cout << "_";
    cout << "��� �亯�Ͽ���." << '\n';
}