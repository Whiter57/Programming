#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int r = 4, c = 8, n;
    int side;
    int** arr = new int* [r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }


    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = rand() % 20;

        }

    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << "\t";

        }
        cout << endl;
    }

    cout << "������� ����������� ������\n";
    cout << "Leat - 0 Right - 1\n";                                          //������� ����������� ������ ������ � ����� �����//
    cin >> side;
    cout << "������� ���������� ������� (�� ������ 4-�)\n";
    cin >> n;
    if (n >= 5)
    {
        cout << "�� ������ 4-�!\n";
            return 0;
    }
    
    if (side == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = arr[j][0];

                for (int g = 0; g < c - 1; g++)
                    arr[j][g] = arr[j][g + 1];
                arr[j][c - 1] = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }


    if (side == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = arr[j][c - 1];

                for (int g = c - 1; g > 0; --g)
                    arr[j][g] = arr[j][g - 1];
                arr[j][0] = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "�������� ���� �� �������� ����! \n";
    }

    for (int i = 0; i < r; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}