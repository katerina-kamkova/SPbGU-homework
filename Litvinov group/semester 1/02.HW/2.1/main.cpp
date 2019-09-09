#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

int recursion(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    return recursion(n - 1) + recursion(n - 2);
}

int iteration(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    int a = 1;
    int b = 1;
    while (n - 2 > 0) {
        --n;
        swap(a, b);
        a += b;
    }
    return a;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    cout << "������� ����� �������� �����: ";
    int n = 0;
    cin >> n;

    cout << endl << "������� ������ �����: (1) - ��������, (2) - �������� ";
    int type = 0;
    cin >> type;

    if (type == 1) {
        cout << endl << "����� ��������� ��� ������� " << n << " = " << recursion(n) << endl;
    } else {
        cout << endl << "����� ��������� ��� ������� " << n << " = " << iteration(n) << endl;
    }

    return 0;
}
