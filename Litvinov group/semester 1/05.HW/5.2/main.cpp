#include "5.2.h"

#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    cout << "������� n - ���������� ������: ";
    int n = 0;
    cin >> n;

    cout << "������� m - ����� �����, �������� ����� ���������: ";
    int m = 0;
    cin >> m;

    Position *first = createPosition();

    createCircle(first, n);

    cout << endl << "������� ���� �� �������: " << deleteAllButOne(last(first), n, m);

    return 0;
}
