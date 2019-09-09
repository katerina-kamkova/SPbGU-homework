#include <iostream>
#include <locale.h>

using namespace std;

int headOn(int number, int degree) {
    int num = number;
    while (degree > 1) {
        num *= number;
        --degree;
    }
    return num;
}

int betterWay(int number, int degree) {
    if (degree == 1) {
        return number;
    }
    if (degree % 2 == 0) {
        return betterWay(number * number, degree / 2);
    }
    return number * betterWay(number * number, (degree - 1) / 2);
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    cout << "������� �����, ���������� � �������: ";
    int number = 0;
    cin >> number;

    cout << endl << "������� �������: ";
    int degree = 0;
    cin >> degree;

    cout << endl << "����� �������� �������� � �������: '� ���' - 1 ��� �� O(log n) - 2 : ";
    int choice = 0;
    cin >> choice;

    if (choice == 1) {
        cout << endl << endl << "�����: " << headOn(number, degree) << endl;
    } else {
        cout << endl << endl << "�����: " << betterWay(number, degree) << endl;
    }

    return 0;
}
