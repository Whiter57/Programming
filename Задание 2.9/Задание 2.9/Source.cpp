#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	double money, deposit;
	cout << "������� ����� ��������� ������ � ����\n";
	cin >> money;
	cout << "������� ������� �������, ������� ����������� ����.\n";
	cin >> deposit;
	deposit = (deposit / 100) / 12;
	money = money * deposit;
	cout << "���� ����� ����������� " << money << " ���� ����������";

	return 0;

}