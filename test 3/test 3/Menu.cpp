#include"Reservoir.h"

//������� ���������� �������� � �������
int countreservoir = 4;

//������� ���������� �����
int countrountry = 1;

//ID ������� � �������. ��������� ��������
int number = 1;

//�������������� ���������� ����������� �����
Reservoir* vodoem = new Reservoir[countreservoir]
{
	{number++, 2201, "������� �����", 0.72, 0.45, 50, "�����", "������� ����. ���� �����. ������������ �������"},
	{number++, 3301, "����������� �������������", 3.5, 170, 8, "�������������","����������� � ���������������� �������"},
	{number++, 4421, "�������� ����", 20, 180, 7.4, "����", "����������, ����������� � �������� �������"},
	{number++, 4478, "������ ����", 100, 310, 25, "����", "����������, ������������ � �������� �������"}
};


//-----------------------------------------------------------------------------------------------
string* MenuItems()
{
	string* item = new string[7];
	item[0] = "1. ������ ��������";
	item[1] = "2. ���������� �������. �������� �������";
	item[2] = "3. ������ ������ �������";
	item[3] = "4. ����������� ������� ������ �����������";
	item[4] = "5. �������� ���� �������";
	item[5] = "6. ��������� ������� ������ �����������";
	item[6] = "7. ����� �� ���������";

	return item;
}
//-----------------------------------------------------------------------------------------------
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
//-----------------------------------------------------------------------------------------------
void MenuFun1()
{
	system("cls");

	gotoxy(1, 6);
	cout << "������ ��������\n\n";
	gotoxy(17, 6);

	gotoxy(1, 7);
	cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";
	gotoxy(1, 8);
	cout << "|���    | ������������               | ������, �� | �����, �� | �������, � | ���             | �������������� ����������                       |\n";
	gotoxy(1, 9);
	cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";

	for (size_t i = 0; i < countreservoir; i++)
	{
		gotoxy(1, 10 + i);
		vodoem[i].Show_Reservoir();

	}
	cout << " +-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun2()
{
	system("cls");
	gotoxy(9, 5);
	cout << endl;
	gotoxy(0, 6);

	int choose;
	cout << "1. ���������� �������" << endl;
	cout << "2. �������� �������" << endl;
	cout << "3. �����" << endl;
	cout << "������� ����� ����: ";
	cin >> choose;
	cout << endl << endl;
	if (choose == 1)
		vodoem->AddReservoir(vodoem, &countreservoir, &number);

	if (choose == 2)
		vodoem->DeleteReservoir(vodoem, &countreservoir, &number);

	if (choose > 2)
		cout << "�����..." << endl;

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun3()
{
	system("cls");
	int _code;
	int idarray = NULL;
	int check = 0;

	gotoxy(0, 9);
	cout << "������ ������ �������\n";
	cout << "������� ����������� ����� �������: ";
	cin >> _code;
	vodoem->SearchVolume(vodoem, countreservoir, _code, &idarray, &check);

	if (check)
	{
		cout << "����� ������� ";
		vodoem[idarray].Show_One_Reservoir();
		cout << " = " << vodoem[idarray].Getvolume() << " ��3";
	}

	else
		cout << "�� ������� ������ �� �������...";

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun4()
{
	system("cls");
	int _code;
	int idarray = NULL;
	int check = 0;

	gotoxy(0, 9);
	cout << "����������� ������� ������ �����������\n";
	cout << "������� ����������� ����� �������: ";
	cin >> _code;
	vodoem->SearchArea(vodoem, countreservoir, _code, &idarray, &check);

	if (check)
	{
		cout << "������� ������� ";
		vodoem[idarray].Show_One_Reservoir();
		cout << " = " << vodoem[idarray].Getarea() << " ��.";
	}

	else
		cout << "�� ������� ������ �� �������...";

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun5()
{
	system("cls");

	bool checktip = 0;
	int code1;
	int code2;
	int idarray1 = NULL;
	int idarray2 = NULL;
	int checkcode1 = 0;
	int checkcode2 = 0;

	gotoxy(0, 9);
	cout << "�������� ��������� �� ������� � ������ ����\n";
	cout << "������� ����������� ����� ������� �������: ";
	cin >> code1;
	cout << "������� ����������� ����� ������� �������: ";
	cin >> code2;


	//������ �������� �� ������� �������� � ���� ������

	for (size_t k = 0; k < countreservoir; k++)
	{
		if (vodoem[k].Getcode() == code1)
		{
			checkcode1++;
		}
	}

	if (checkcode1)
	{
		cout << "������ ������ ������ � ����\n";
	}

	else
	{
		cout << "������ ������ �� ������ � ����\n";
	}

	for (size_t k = 0; k < countreservoir; k++)
	{
		if (vodoem[k].Getcode() == code2)
		{
			checkcode2++;
		}
	}

	if (checkcode2)
	{
		cout << "������ ������ ������ � ����\n";
	}

	else
	{
		cout << "������ ������ �� ������ � ����\n";
	}

	if (checkcode1 && checkcode2)
	{
		cout << "��� ������� ���� ������� � ����\n";
		cout << "�������� ��������� ����� ��������\n\n";

		checktip = vodoem->CheckTip(vodoem, countreservoir, code1, code2, &idarray1, &idarray2);

		if (checktip)
		{
			cout << "������� ";
			vodoem[idarray1].Show_One_Reservoir();
			cout << " � ";
			vodoem[idarray2].Show_One_Reservoir();
			cout << " ����� ����� ��� - ";
			vodoem[idarray1].Show_Tip();
		}

		else
		{
			cout << "������� ����� ������ ���\n";
			vodoem[idarray1].Show_One_Reservoir();
			cout << " ��� - ";
			vodoem[idarray1].Show_Tip();
			cout << endl;
			vodoem[idarray2].Show_One_Reservoir();
			cout << " ��� - ";
			vodoem[idarray2].Show_Tip();
		}
	}

	else
	{
		cout << "������� ��������� ������ � ��������� ��� ������...\n";
	}



	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun6()
{
	system("cls");
	gotoxy(0, 9);
	cout << "��������� ������� ������ ����������� �������� ������ ����\n";
	vodoem->AutoSearchArea(vodoem, countreservoir);
	cout << "�������������� ���������� ������� ��� ���� �������� ���������\n";
	cin.ignore();
	char charsearch[30] = "";
	cout << "������� ��� ������� ��� ���������: ";
	cin.getline(charsearch, 30);

	vodoem->SearchAreaTip(vodoem, charsearch, countreservoir);

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void ChangeCursorStatus(bool Visible)
{
	CONSOLE_CURSOR_INFO* c = new CONSOLE_CURSOR_INFO;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Visible)
	{
		c->bVisible = TRUE;
		c->dwSize = 0;
	}
	else
	{
		c->bVisible = FALSE;
		c->dwSize = 1;
	}

	SetConsoleCursorInfo(h, c);
}