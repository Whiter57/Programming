#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Reservoir
{
public:

	int id;
	int code;
	char* Reservoir_Name = nullptr;
	double width;
	double length;
	double depth;
	char* Tip = nullptr;
	long double area;
	long double volume;
	
	Reservoir();
	Reservoir(int id, int code, const char* name, double width, double length, double depth, const char* tip, const char* info);

	Reservoir(const Reservoir& obj);

	void DeleteReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	void AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	//������ ������ ������� �� ������������ ������ ���� S = a * b, ��� S � �������; a - ����� � b - ������.
	//������������ �������, ����� ��������� ������ �� ��������� �������
	long double SearchArea(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	//����� ��� ��������� ������� �������� ������ ���� (����� ��������� �������)
	//���� ������ ���� ����� "�" �� � ��������� ������� ��� ����, ��� ���� ��� �����
	void SearchAreaTip(Reservoir* vodoem, char const* charsearch, int const countreservoir);

	//������ ������ ���� (Q = width * length * depth, ��� Q � �����; width * length * depth � ������, ����� � �������)
	long double SearchVolume(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	bool CheckTip(Reservoir* vodoem, int const countreservoir, int _code1, int _code2, int* _idarray1, int* _idarray2);

	//����� ���� �������
	void Show_Tip();

	//����� �������� �� �����
	void Show_Reservoir();

	//����� ������ ������� �� �����
	void Show_One_Reservoir();

	~Reservoir();
	//�������

	int Getid();
	int Getcode();
	char* GetReservoir_Name();
	double Getwidth();
	double Getlength();
	double Getdepth();
	char* GetDop_Info();
	char* GetTip();
	long double Getarea();
	long double Getvolume();

	//�������
	void Setid(int _id);
	void Setcode(int _code);
	void SetReservoir_Name(char* _Reservoir_Name);
	void Setwidth(double _width);
	void Setlength(double _length);
	void Setdepth(double _depth);
	void SetTip(char* _Tip);
	void Setarea(long double _area);
	void Setvolume(long double _volume);
};