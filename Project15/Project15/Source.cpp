#include<iostream>
#include<ctime>

using namespace std;

int* give_memory(int*, int);
int* free_memory(int*);
void init_array(int*, int);
void print_array(int*, int);
int* add_back(int*, int*, int);
int* add_value(int*, int*, int, int);
int* del_pos(int*, int*, int);


int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned)time(0));
	int* arr = NULL, size;
	cout << "Enter the size of the array = ";
	cin >> size;

	arr = give_memory(arr, size);

	init_array(arr, size);
	print_array(arr, size);

	arr = add_back(arr, &size, 700);
	cout << endl;
	print_array(arr, size);

	arr = add_value(arr, &size, 555, 5);
	cout << endl;
	print_array(arr, size);

	arr = del_pos(arr, &size, 6);
	cout << endl;
	print_array(arr, size);

	cout << endl;
	arr = free_memory(arr);
	return 0;
}

int* give_memory(int* A, int size) // ������� ������������� ������������ ������
{
	A = (int*)malloc(size * sizeof(int));
	return A;
}

int* free_memory(int* A) // ������� �������� ������������� �������
{
	free(A);
	A = NULL;
	return A;
}

void init_array(int* A, int size) // ������� ������������� ������������� �������
{
	for (int* i = A; i < A + size; i++)
	{
		*i = rand() % 100;
	}
}

void print_array(int* A, int size) // ������� ������ ������������� �������
{
	for (int i = 0; i < size; i++)
	{
		cout << "A[" << i << "] = " << *(A + i) << "\n";
	}
}

int* add_back(int* A, int* size, int value) // ������� ���������� �������� � ����� �������
{
	int* new_A = NULL;
	new_A = give_memory(new_A, *size + 1);
	for (int i = 0; i < *size; i++)
	{
		new_A[i] = A[i];
	}
	new_A[*size] = value;
	(*size)++;
	A = free_memory(A);
	return new_A;
}

int* add_value(int* A, int* size, int value, int index) // ������� ������� �������� �� ���������� �������
{
	int* new_A = NULL;
	new_A = give_memory(new_A, *size + 1);
	for (int i = 0; i < index; i++)
	{
		new_A[i] = A[i];
	}
	new_A[index] = value;
	for (int i = index + 1; i <= *size; i++)
	{
		new_A[i] = A[i - 1];
	}
	(*size)++;
	A = free_memory(A);
	return new_A;
}

int* del_pos(int* a, int* size, int position) // ������� �������� �������� �� ���������� �������
{
	for (int i = position + 1; i < *size; i++)
	{
		a[i - 1] = a[i];
	}
	(*size)--;
	return a;
}