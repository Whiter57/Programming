#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    
    float fuel, count, res;
    cout << "������ ������� ������";
    cin >> count;
    cout << "������ ������� �� 100 ��";
    cin >> fuel;
    
    res = (count / fuel) * 100;
    cout << res;




}