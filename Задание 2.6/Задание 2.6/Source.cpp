#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	double n;
	int dollar, cent;
	cout << "number : ";
	cin >> n;
	dollar = n;
	cent = (n - dollar) * 100;
	cout << dollar << " �������� " << cent << " ������";
	return 0;
}