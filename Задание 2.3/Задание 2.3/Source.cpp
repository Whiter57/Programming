#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n1, n2, n3, n4, n5, n6, n7, maxNumber;
	cout << "���������� ������ 7 �����\n\n";
	cout << "������� ������ �����:\n";
	cin >> n1;
	cout << "������� ������ �����:\n";
	cin >> n2;
	cout << "������� ������ �����:\n";
	cin >> n3;
	cout << "������� ��������� �����:\n";
	cin >> n4;
	cout << "������� ����� �����:\n";
	cin >> n5;
	cout << "������� ������ �����:\n";
	cin >> n6;
	cout << "������� ������� �����:\n";
	cin >> n7;
	if (n1 > n2)
	{
		maxNumber = n1;
	}
	else
	{
		maxNumber = n2;
	}
	if (n3 > maxNumber)
	{
		maxNumber = n3;
	}
	if (n4 > maxNumber)
	{
		maxNumber = n4;
	}
	if (n5 > maxNumber)
	{
			maxNumber = n5;
	}
	if (n6 > maxNumber)
	{
		maxNumber = n6;
	}
	if (n7 > maxNumber)
	{
		maxNumber = n7;
	}
	cout << "������������ �����:" << maxNumber;
	return 0; 
}