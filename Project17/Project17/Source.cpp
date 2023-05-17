#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
struct Book
{
	char Name[20];
	char author[15];
	int Year;
	char Ganr[15];
	char Izd[20];
	float Cena;
};
Book Vvod()
{
	Book tmp;
	cout << "������� �������� �����: ";
	gets_s(tmp.Name);
	cout << "������� ������ �����: ";
	gets_s(tmp.author);
	cout << "������� ��� ���������: ";
	cin >> tmp.Year;
	cin.ignore();
	cout << "������� ���� �����: ";
	gets_s(tmp.Ganr);
	cout << "������� ������������ �����: ";
	gets_s(tmp.Izd);
	cout << "������� ���� �����: ";
	cin >> tmp.Cena;
	cin.ignore();
	return tmp;
}
void Add(Book*& mas, int& n)
{
	mas = (Book*)realloc(mas, (n + 1) * sizeof(Book));
	mas[n] = Vvod();
	n++;
}
void Show(Book tmp)
{
	cout << tmp.Name << "\n" << tmp.author << "\n" << tmp.Year << "\n" << tmp.Ganr << "\n" << tmp.Izd << "\n" << tmp.Cena << "\n";
}
void Print(Book* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		Show(mas[i]);
	}
}
void Del(Book*& mas, int& n, char* Nazv)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(mas[i].Name, Nazv) == 0)
		{
			k = 1;
			for (int j = i; j < n - 1; j++)
			{
				mas[j] = mas[j + 1];
			}
			mas = (Book*)realloc(mas, (n - 1) * sizeof(Book));
			n--;
			i--;
		}
	}
	if (k == 0)
	{
		cout << "��� ����������.\n";
	}
	else
	{
		cout << "�������� ���������.\n";
	}
}
void Find_author(Book* mas, int n, char* Fio)
{
	bool f = 0;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(mas[i].author, Fio) == 0)
		{
			f = 1;
			Show(mas[i]);
		}
	}
	if (f == 0)
	{
		cout << "��� ����������.\n";
	}
}
void Find_Name(Book* mas, int n, char* Fio)
{
	bool f = 0;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(mas[i].Name, Fio) == 0)
		{
			f = 1;
			Show(mas[i]);
		}
	}
	if (f == 0)
	{
		cout << "��� ����������.\n";
	}
}
void Sort_Imdb(Book* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (mas[j].Izd < mas[j + 1].Izd)
			{
				Book tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}

void Sort_Name(Book* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (_stricmp(mas[j].Name, mas[j + 1].Name) > 0)
			{
				Book tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void Sort_author(Book* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (_stricmp(mas[j].author, mas[j + 1].author) > 0)
			{
				Book tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void Sort_Izd(Book* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (_stricmp(mas[j].Name, mas[j + 1].Name) > 0)
			{
				Book tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void Sort_a(Book* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (_stricmp(mas[j].author, mas[j + 1].author) > 0)
			{
				Book tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void Write_File(Book* mas, int n, const char* puth)
{
	FILE* pf;
	fopen_s(&pf, puth, "wb");
	if (pf)
	{
		fwrite(&n, sizeof(n), 1, pf);
		fwrite(mas, sizeof(mas[0]), n, pf);
		fclose(pf);
	}
	else
	{
		cout << "Error.\n";
	}
}
void Read_File(Book*& mas, int& n, const char* puth)
{
	FILE* pf;
	fopen_s(&pf, puth, "rb");
	if (pf)
	{
		fread(&n, sizeof(n), 1, pf);
		mas = (Book*)malloc(n * sizeof(Book));
		fread(mas, sizeof(mas[0]), n, pf);
		fclose(pf);
	}
	else
	{
		cout << "Error.\n";
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	char ch;
	int n = 0;
	Book* Catalog = NULL;
	char str[20];
	do
	{
		system("cls");
		cout << "����:\n";
		cout << "1-���������� �����.\n";
		cout << "2-�������� �����.\n";
		cout << "3-����� ���� ����.\n";
		cout << "4-����� �� ������.\n";
		cout << "5-����� �� ��������.\n";
		cout << "6-���������� �� �������� �����.\n";
		cout << "7-���������� �� ������ �����.\n";
		cout << "8-���������� �� ������������ �����.\n";
		cout << "9-������ � ����.\n";
		cout << "10-������ �� �����.\n";
		cout << "Esc-�����.\n";
		ch = _getch();
		switch (ch)
		{
		case '1':system("cls");
			Add(Catalog, n);
			cout << "����� ���������.\n";
			Sleep(2000);
			break;
		case '2':system("cls");
			if (n != 0)
			{
				cout << "������� �������� ��������� �����: ";
				gets_s(str);
				Del(Catalog, n, str);
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '3':system("cls");
			if (n != 0)
			{
				Print(Catalog, n);
				system("pause");
			}
			else
			{
				cout << "������� ����.\n";
				Sleep(2000);
			}
			break;
		case '4':system("cls");
			if (n != 0)
			{
				cout << "������� ������ �����: ";
				gets_s(str);
				Find_author(Catalog, n, str);
			}
			else
			{
				cout << "������� ����.\n";
			}
			system("pause");
			break;
		case '5':system("cls");
			if (n != 0)
			{
				cout << "������� �������� �����: ";
				gets_s(str);
				Find_Name(Catalog, n, str);
			}
			else
			{
				cout << "������� ����.\n";
			}
			system("pause");
			break;

		case '7':system("cls");
			if (n != 0)
			{
				Sort_Name(Catalog, n);
				cout << "���������� �����������.\n";
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '8':system("cls");
			if (n != 0)
			{
				Sort_author(Catalog, n);
				cout << "���������� �����������.\n";
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '9':system("cls");
			if (n != 0)
			{
				Sort_Izd(Catalog, n);
				cout << "���������� �����������.\n";
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '10':system("cls");
			if (n != 0)
			{
				Write_File(Catalog, n, "data.txt");
				cout << "������ �����������.\n";
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '11':system("cls");
			Read_File(Catalog, n, "data.txt");
			cout << "������ �����������.\n";
			Sleep(2000);
			break;
		}
	} while (ch != 27);
	free(Catalog);
}