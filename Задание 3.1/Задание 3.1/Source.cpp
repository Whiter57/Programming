#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int sum, n;
	sum = 0;
	cout << "������� ����� ����� \n";
	cin >> n;
	while ( n <= 500)
	{
		sum = sum + n;
		n = n++;
	}
	cout << "����� ����� ����� = " << sum;


	return 0;



}