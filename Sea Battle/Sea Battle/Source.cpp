#include <iostream>
#include <Windows.h>
using namespace std;

const int ROWS = 6;
const int COLUMNS = 6;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int A[ROWS][COLUMNS] = 
    {
      {0, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}
    };

    int x, y;
    int sum = 3;
    int k = 0;
    int sproba = 0;

    while (k < sum && sproba < 3) {
        cout << "������ ���������� ��� ������� ";
        cin >> x >> y;

        if (A[x][y] == 1) {
            cout << "������!" << endl;
            k++;
        }
        else {
            cout << "�� ������!" << endl;
            sproba++;
        }
    }

    if (k == sum) {
        cout << "�� ������!" << endl;
    }
    else {
        cout << "�� �������!" << endl;
    }

    return 0;
}