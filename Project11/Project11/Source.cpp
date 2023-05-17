#include <iostream>
using namespace std;

void CopyReverse(int* orig, int* copy, int length)
{
    for (int i = 0; i < length; i++)
    {
        *(copy + length - 1 - i) = *(orig + i);
    }
}

template <typename T>
void PrintArr(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    const int n = 5;
    int arr1[n] = { 0,1,2,3,4 };
    int arr2[n];
    int* arr1Ptr = arr1;
    int* arr2Ptr = arr2;
    CopyReverse(arr1Ptr, arr2Ptr, n);
    PrintArr(arr2, n);
}