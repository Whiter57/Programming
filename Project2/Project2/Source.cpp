#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	float monthe, money, a, b;

	cout << "������� ����� �������� ";
	cin >> money;
	cout << "������� ���������� ������� ";
	cin >> monthe;

	b = money * (5 / 100) / 365 * monthe;
	cout << b;
}