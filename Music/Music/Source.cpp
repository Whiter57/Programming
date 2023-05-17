#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
struct Music
{
	char Name[20];
	char executor[15];
	char Albom[20];
	int Long;
	int Year;
	char gener[20];
	char land[20];
};
Music Vvod()
{
	Music tmp;
	cout << "������� �������� �����: ";
	gets_s(tmp.Name);
	cout << "������� ��� �����������: ";
	gets_s(tmp.executor);
	cout << "������� �������� �������: ";
	gets_s(tmp.Albom);
	cout << "������� ����������������� �����: ";
	cin >> tmp.Long;
	cout << "������� ��� �������: ";
	cin >> tmp.Year;
	cout << "������� ���� �����: ";
	gets_s(tmp.gener);
	cout << "������� ������: ";
	gets_s(tmp.land);
	cin.ignore();
	return tmp;
}
void Add(Music*& mas, int& n)
{
	mas = (Music*)realloc(mas, (n + 1) * sizeof(Music));
	mas[n] = Vvod();
	n++;
}
void Show(Music tmp)
{
	cout << tmp.Name << "\n" << tmp.executor << "\n" << tmp.Albom << "\n" << tmp.Long << "\n" << tmp.Year << "\n" << tmp.gener << "\n" << tmp.land << "\n";
}
void Print(Music* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		Show(mas[i]);
	}
}
void Del(Music*& mas, int& n, char* Nazv)
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
			mas = (Music*)realloc(mas, (n - 1) * sizeof(Music));
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

void Write_File(Music* mas, int n, const char* puth)
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
void Read_File(Music*& mas, int& n, const char* puth)
{
	FILE* pf;
	fopen_s(&pf, puth, "rb");
	if (pf)
	{
		fread(&n, sizeof(n), 1, pf);
		mas = (Music*)malloc(n * sizeof(Music));
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
	Music* Catalog = NULL;
	char str[20];
	do
	{
		system("cls");
		cout << "����:\n";
		cout << "1-���������� �����.\n";
		cout << "2-�������� �����.\n";
		cout << "3-����� ���� �����.\n";
		cout << "4-������ � ����.\n";
		cout << "5-������ �� �����.\n";
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
				Write_File(Catalog, n, "data.txt");
				cout << "������ �����������.\n";
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '5':system("cls");
			Read_File(Catalog, n, "data.txt");
			cout << "������ �����������.\n";
			Sleep(2000);
			break;
		}
	} while (ch != 27);
	free(Catalog);
}