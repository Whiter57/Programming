#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int day, weeks;
	cout << "������� ���������� ���� \n";
	cin >> day;
	weeks = day / 7;
	day = day % 7;
	cout << "������ : " << weeks << "\n";
	cout << "���� : " << day << "\n";

	return 0;
}