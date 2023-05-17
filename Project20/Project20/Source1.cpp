#include <iostream>
using namespace std;

void fillMassiv(int** pArray, int rowCount, int columnCount);
void printArray(int** pArray, int rowCount, int columnCount);
void addColumn(int** pArray, int rowCount, int columnCount, int index);
void deleteColumn(int** pArray, int rowCount, int columnCount, int index);

int main()
{
    setlocale(LC_ALL, "Rus");

    int const rowCount = 3;
    int const startColumnCount = 10;
    int columnCount = 3;
    int userIndex;
    int** simpleArray = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        simpleArray[i] = new int[startColumnCount];
    }
    fillMassiv(simpleArray, rowCount, columnCount);
    cout << "��������� ������: " << endl;
    printArray(simpleArray, rowCount, columnCount);
    //������� ����� �������� ��� � ��������, ��� � � ����� �������. ������� 0...3
    cout << "������� ����� ������� �� 0 �� " << columnCount << " ����� ������� �� ������ ��������? ";
    cin >> userIndex;
    if (userIndex >= 0 && userIndex <= columnCount)
    {
        columnCount++;
        addColumn(simpleArray, rowCount, columnCount, userIndex);
        printArray(simpleArray, rowCount, columnCount);
    }
    else
    {
        cout << "�� ������ ��������" << endl;
    }
    //�������� �������
    cout << "������� ����� ������� �� 0 �� " << columnCount - 1 << " ����� ������� �� ������ �������? ";
    cin >> userIndex;
    if (userIndex >= 0 && userIndex < columnCount)
    {
        deleteColumn(simpleArray, rowCount, columnCount, userIndex);
        columnCount--;
        printArray(simpleArray, rowCount, columnCount);
    }
    else
    {
        cout << "�� ������ ��������" << endl;
    }
    //�������� �������
    for (int i = 0; i < rowCount; i++)
    {
        delete[] simpleArray[i];
    }
    delete[] simpleArray;
}
//������������� �������
void fillMassiv(int** pArray, int rowCount, int columnCount)
{
    if (pArray == nullptr)
    {
        cout << "������!" << endl;
        return;
    }

    int value = 1;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            pArray[i][j] = value;
            value++;
        }
    }
}
//����� ������� �� �����
void printArray(int** pArray, int rowCount, int columnCount)
{
    if (pArray == nullptr)
    {
        cout << "������!" << endl;
        return;
    }

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            cout << pArray[i][j] << " ";
        }
        cout << endl;
    }
}
//���������� �������
void addColumn(int** pArray, int rowCount, int columnCount, int index)
{
    if (pArray == nullptr)
    {
        cout << "������!" << endl;
        return;
    }

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            //�������� ������ ��������
            if (j == index)
            {
                for (int k = columnCount; k > index; k--)
                {
                    pArray[i][k] = pArray[i][k - 1];
                }
                //��������� ����������� ������� 0��
                pArray[i][j] = 0;
            }
        }
    }
}
//�������� �������
void deleteColumn(int** pArray, int rowCount, int columnCount, int index)
{
    if (pArray == nullptr)
    {
        cout << "������!" << endl;
        return;
    }

    for (int i = 0; i < rowCount; i++)
    {
        //j < columnCount, ����� � ������� ������ ������� ��������� �����,
        //������� �� ����� ��� ������, � �� �������� ���������� �������� ��� �� ��������.
        for (int j = index; j < columnCount; j++)
        {
            pArray[i][j] = pArray[i][j + 1];
        }
    }
}