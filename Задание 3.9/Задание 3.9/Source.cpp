#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int A, B;
	cout << "������� �����\n";
	cin >> A;
	for (int i = A - 1; i > 1; i--)
	{
		B = i;
		if ((A % (B * B) == 0) && (A % (B * B * B) != 0))
		{
			cout << "�����, ��� ������� ���� ����� �������� ��� �������: " << B << "\n";
		}
	}
	return 0;
}