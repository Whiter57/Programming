#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int const n = 12;
	int profit[n];
	int start, end, minPrMonth, maxPrMonth;
	for (int i = 0; i < n; i++)
	{
		cout << "������� ���� ������ �� " << i + 1 << " �����\n";
		cout << " ������:\n";
		cin >> profit[i];
	}
	cout << "������� ������ ������������ ��� ����� "
		"�����:\n";
	cin >> start;
	cout << "������� ��������� ������������ ��� ����� "
		"�����:\n";
	cin >> end;
	minPrMonth = start - 1;
	maxPrMonth = start - 1;
	for (int i = start; i <= end - 1; i++)
	{
		if (profit[i] > profit[maxPrMonth])
		{
			maxPrMonth = i;
		}
		if (profit[i] < profit[minPrMonth])
		{
			minPrMonth = i;
		}
	}
	cout << "�� �������� ����������� ������ � "
		<< minPrMonth + 1 << " ������.\n";
	cout << "�� �������� ������������ ������ � "
		<< maxPrMonth + 1 << " ������.\n";
	return 0;
}