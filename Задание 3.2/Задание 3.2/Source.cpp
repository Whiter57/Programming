#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int x, y, f;
	float p;
	p = 1;
	cout << "������� ����� ������� ������ �������� � ������� \n";
	cin >> x;
	cout << "������� ������� \n";
	cin >> y;
	if (y == 0)
	{
		p = 1;

	}
	else
	{
		f = 1;
		
		while (f <= abs(y))
		{
			p = p * x;
			f = f++;

		}
		if (y < 0)
		{

			p = 1 / p;

		}
	}
	cout << "��������� = " << p;
	
	return 0;
	

}