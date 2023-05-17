#include "Reservoir.h"

void Reservoir::AddRes(const char* name)
{
    strcpy(this->Name, name);
    cout << "������� ������ (m): ";
    cin >> Width;
    cout << "������� ������ ������� (m):";
    cin >> Long;
    cout << "������� ������� ������� (m): ";
    cin >> Depth;
}

void Reservoir::PrintRes()
{
    cout << "��������: " << Name << endl;
    cout << "������ (m): " << Width << endl;
    cout << "������ (m):" << Long << endl;
    cout << "������� (m): " << Depth << endl;
}

void Reservoir::Volume()
{

    cout << "Volume: " << Long * Width * Depth << " m3" << endl;
}

void Reservoir::Area()
{

    cout << "Area: " << Long * Width << " m2" << endl;
}

void Reservoir::Srav()
{
    if (Long * Width * Depth < 10000)
    {
        cout << Name << " - pool" << endl;
    }
    else
    {
        cout << Name << " - sea" << endl;
    }

}

int Reservoir::Getsea()
{
    return Long * Width * Depth;
}

Reservoir::Reservoir(const Reservoir& obj)
{
    strcpy(Name, obj.Name);
    Long = obj.Long;
    Width = obj.Width;
    Depth = obj.Depth;
}

Reservoir::Reservoir()
{
    strcpy(Name, "qwerty");
    Long = 1 + rand() % 1000;
    Width = 1 + rand() % 50;
    Depth = 1 + rand() % 20;
}

Reservoir::~Reservoir()
{
    delete[] Name;
}