#include"String.h"

//Help Lessons #SimpleCode + ���������� Yarosh Oleksandr

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyString str("������! ");
	MyString str2("���� ���������");

	str.Print();

	MyString resultat = str + str2;

	resultat.Print();

	cout << endl;


	//������ ����� �� ���� ��� �������.

	char buff[80];

	cout << "������� ������ ������: ";
	cin.getline(buff, 80);
	str = buff;

	cout << "������� ������ ������: ";
	cin.getline(buff, 80);
	str2 = buff;
	cout << endl;

	resultat = str + str2;

	resultat.Print();

	system("pause");
}