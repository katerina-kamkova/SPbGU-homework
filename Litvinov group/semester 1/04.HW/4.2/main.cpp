#include "4.2.h"
#include "sort.h"

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    vector<int> myArray = createVector();

    heapSort(myArray);

    cout << "��������������� ������: ";
    print(myArray);

    cout << endl << endl;
    cout << "�������� ������ ������������� ������� � �������: " << mostFrequent(myArray) << endl;

    return 0;
}
