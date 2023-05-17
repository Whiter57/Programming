#include <iostream>
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define POW2(x) ((x)*(x))
#define POW(x,y) ((!y)?1:x*pow(x,y-1))
#define EVEN(x) ( x % 2 == 0 ? " ������" : " �� ������" )

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	cout << "�������� �������������� ��������:\n";
	cout << "1 - ����� ������������ ����� �� ����\n";
	cout << "2 - ����� ������������� ����� �� ����\n";
	cout << "3 - �������� ����� � �������\n";
	cout << "4 - �������� ����� � �������\n";
	cout << "5 - �������� �� ��������\n";
	int choice, a;
	double x, y;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "\n������� ��� �����\n";
		cin >> x >> y;
		cout << "����������� ����� - " << MIN(x, y) << endl;
		break;
	case 2:
		cout << "������� ��� �����\n";
		cin >> x >> y;
		cout << "������������ ����� - " << MAX(x, y) << endl;
		break;
	case 3:
		cout << "������� �����\n";
		cin >> x;
		cout << "������� ����� " << x << " ����� " << POW2(x) << endl;
		break;
	case 4:
		cout << "������� �����\n";
		cin >> x;
		cout << "������� ������� �����\n";
		cin >> y;
		cout << x << "^" << y << " = " << POW(x, y) << endl;
		break;
	case 5:
		cout << "������� ����� �����\n";
		cin >> a;
		cout << "����� " << a << EVEN(a) << endl;
		break;
	default:
		cout << "����������� ����� ������\n";
		break;
	}
}