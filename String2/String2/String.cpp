#include "String.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string userstring;
    cout << "������� ���� ������\n";
    cin >> userstring;
    cout << "������ ���� �������� � ����� String\n";
    String data(userstring);
    int size = data.returnSize();
    int choice;
    
    cout << "1 - ����� � ������� ������� �� ������� \n";
    cout << "2 - ����� ������� � ������� ��� ������ � ������ \n";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:system("cls");
    {
        cout << "������� ������: \n";
        int index;
        cin >> index;
        if (index > size || index < 1)
        {
            cout << "����������� ����� ������.\n";
        }
        else
        {
            cout << "��������� �� ������� " << index << " ��������: " << data[index] << ".\n";
        }
        break;
    }
    case 2:system("cls");
    {
        cout << "������� ������� ��� ������: ";
        char element;
        cin >> element;
        int elementIndex = data(element);
        if (elementIndex != -1)
            cout << "������ �������� \"" << element << "\": " << elementIndex << ".\n";
        else
            cout << "������� �� ������.\n";
        break;
    }
    default:
    {
        cout << "����� ������� ���.\n";
    }
    }
}