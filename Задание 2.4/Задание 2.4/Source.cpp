#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	float weight, ras, s1, s2, smax = 0;
	float const maxcapacity = 300;
	cout << "������� ��� ������������ ����� (� ��)\n";
	cin >> weight;
	if (weight > 2000)
	{
		cout << "������� �� �������!\n";
	}
	if (weight >= 1501 && weight <= 2000)
	{
	   ras = 9; smax = maxcapacity / ras;
	}
	if (weight >= 1001 && weight <= 1500)
	{
	   ras = 7; smax = maxcapacity / ras;
	}
	if (weight >= 501 && weight <= 1000)
	{
	   ras = 4; smax = maxcapacity / ras;
	}
	if (weight >= 0 && weight <= 500)
	{
		ras = 1; smax = maxcapacity / ras;
	}
	cout << "������� ���������� ����� ����������� A � B (� ��)\n";
	cin >> s1;
	if (smax <= s1)
	{
		cout << "������� �� ��������� � �� ������!\n";
	}
	else
	{
		s1 = smax - s1;
	}
	cout << "������� ���������� ����� ����������� � � � (� ��)\n";
	cin >> s2;
	if (smax <= s2) { cout << "���� ����������! ������� �� ������ �� ����� C!\n";  }        
	if (smax > s2) {                                                                                               
		s2 = (s2 - s1) * ras; {                                                                                  
			if (s2 < 0) { cout << "��� ������������� �������� �������, � ���� ���������� �������.\n";  }}
		cout << "� ����� B ���������� ������ " << s2 << " ������ ������� ��� ����� �� ����� C.\n";
	}
	return 0;

}