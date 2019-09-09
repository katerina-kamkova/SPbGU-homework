#include "6.1.h"
#include "stack.h"

#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    int n = 0;
    cout << "������� ���������� ���������: ";
    cin >> n;

    Stack *stack = createStack();

    cout << "������� ��������: ";
    for (int i = 0; i < n; i ++) {
        string symbol = "";
        cin >> symbol;
        definer(stack, symbol);
    }

    cout << endl << "�����: " << pop(stack) << endl;

    deleteStack(stack);

    return 0;
}
