#include <iostream>
using namespace std;

void fun(int x)
{
    
    int c, a1 = 0, a2 = 0;
    if (99999 >= x || x > 999999)
    {
        cout << "�� ���������� ���� �����! \n";
        return;
    }
    else
    {

        for (int i = 0; x; i++)
        {
            int c = x % 10;
            if (i < 3) a1 += c;
            else      a2 += c;
            x = x / 10;
        }
    }
    if (a1 == a2)
    {
        cout << "����������� � ��� ���������� �����!!!";
        return;
    }
    else
    {
        (a1 != a2);
        cout << "��� ��� ����� �� ����������, ���������� � ��������� ���.";
        return;
    }
   
}

int main()
{
    setlocale(LC_ALL, "");
    int x;
    cout << "������� ����� ������������ �����: \n";
    cin >> x;
    fun(x);




}