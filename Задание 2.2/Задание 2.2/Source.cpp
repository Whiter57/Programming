#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	int Number, n1, n2, n3, n4, newNumber, temp;
	cout << "������� 4-������� ����� \n";
	cin >> Number;
	if (Number / 1000 < 1)
	{
		cout << "���� ����� ������ 4-��������� \n";
	}
	else if (Number / 1000 > 9)
	{
		cout << "���� ����� ������ 4-��������� \n";
	}
	else
	{
		cout << "���� ����� �������� \n";
		n4 = Number % 10;
		temp = Number / 10;
		n3 = temp % 10;
		temp = temp / 10;
		n2 = temp % 10;
		n1 = temp / 10;
		cout << n1 << " " << n2 << " " << n3 << " " << n4 << " ";
		cout << "������� ��� �����: \n";
		newNumber = n2 * 1000 + n1 * 100 + n4 * 10 + n3;
		cout << "���� ����� �����:" << newNumber;
	}

	return 0;

}