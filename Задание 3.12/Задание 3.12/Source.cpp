#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int num1, num2;
    cout << "������� 2 �����\n";
    cin >> num1 >> num2;
    int i;
    for (i = 1; i <= num1 && i <= num2; i++) 
    {
        if (num1 % i == 0 && num2 % i == 0)
        cout << "����� ��� �������� ��� ����� ����� ������� ��� �������: " << i << "\n";
    }

}