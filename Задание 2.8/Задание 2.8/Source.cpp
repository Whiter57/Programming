#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	double speed, S, t;
	int min, sec;
	cout << "������� ��������� ������\n";
	cin >> S;
	cout << "������� ����� ������\n";
	cin >> t;
	min = t;
	sec = (t - min) * 100;
	t = (min * 60) + sec;
	speed = S / t * 3.6; 
	cout << "����������: " << S << "m\n";
	cout << "�����: " << min << " ����� " << sec << " ������. " << "� �������� - " << t << endl;
	cout << "��������: " << speed << "��/�";
		
	return 0; 
}

