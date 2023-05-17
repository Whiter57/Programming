#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

vector<string> responses =
{
  "���?",
  "��� �������",
  "� � ������ ����",
  "��",
  "������ ���"
  "� �� ����"
  "� ������� ������"
};

random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int> uni(0, responses.size() - 1);

int main()
{
    setlocale(LC_ALL, "rus");
    while (true)
    {
        cout << "� ����� ��������� ������� ������� �� ����� ��� ������: ";
    string message;
    while (getline(cin, message))
    {
        cout << responses[uni(rng)] << endl;
    }
    return 0;
    }
}