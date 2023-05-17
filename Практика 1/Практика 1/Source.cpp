#include <iostream>
using namespace std;

double run(double distance, int days)
{
    for (int d = days; d > 1; --d)
    {
        distance += distance * 0.1;
    }
    return distance;

}
double sumRun(double distance, int days)
{
    double sumDays = distance;
    for (int d = days; d > 1; --d)
    {
        distance += distance * 0.1;
        sumDays += distance;
    }
    return sumDays;
}

int main()
{
    setlocale(LC_ALL, "");

    int days = 0;
    cout << "������� ���������� ���� ���������� ";
    cin >> days;
    double dayDistance = 10;

    //�) ������ ������� �� ������, ������, ..., ������� ���� ����������
    cout << "�. ������ ������� �� " << days << " ���� ���������� " << run(dayDistance, days) << " ��." << endl;
        

    //�) ����� ��������� ���� �� �������� �� ������ 7 ���� ����������.
    cout << "�. ������ ������� �� 7 ���� ����� " << sumRun(dayDistance, 7) << " ��. " << endl << endl;
    
    //�) ��������� ���� �� n ���� ����������
    cout << "������� ���-�� ���� ��� ���������� ������� ";
    cin >> days;
    cout << "�. ��������� ������ �� " << days << " ���� ����� " << sumRun(dayDistance, days) << " ��. " << endl << endl;
       
        
    return 0;
}
