#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	float monthe, money, a, b;
	float c = 0.5;

	cout << "������� ����� ��������";
	cin >> money;
	cout << "������� ���������� �������";
	cin >> monthe;
	a = monthe * 30;
	b = money * c / 365 * a;
	cout << b;
}
	
