#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int s, m, h;
	cout << "������� ����� � ��������\n";
	cin >> s;
	m = s / 60;
	s = s % 60;
	h = m / 60;
	m = m % 60;
	cout << "����� : " << h << "\n";
	cout << "����� : " << m << "\n";
	cout << "������ : " << s << "\n";

	return 0;

}