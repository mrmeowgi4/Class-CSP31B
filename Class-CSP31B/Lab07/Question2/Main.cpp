#include <iostream>

using namespace std;

template<typename T>
int partition(T a[], int L, int H)
{
    T p = a[H - 1];
    int i = L-1;

    for (int j = L; j < H - 1; j++)
    {
        if (a[j] <= p)
        {
            i++;
            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    T temp = a[i + 1];
    a[i + 1] = a[H - 1];
    a[H - 1] = temp;

    return i + 1;
}

template<typename T>
void quickSort(T l[], int s)
{
    if (s > 1)
    {
        int pI = partition(l, 0, s);
        quickSort(l, pI - 1);
        quickSort(l, s - pI - 1);
    }
}

template<typename T>
void printArray(T a[], int s)
{
    for (int i = 0; i < s; i++)
        cout << a[i] << ",";
    cout << endl;
}

int main()
{
    int intArray[10] = { 34, 7, 23, 5, 62, 11, 1, 99, 32, 40 }; 
    double doubleArray[10] = { 34.5, 7.1, 23.3, 5.5, 62.2, 32.8, 99.6, 1.9, 11.4, 54.7 }; 

    quickSort(intArray, 10);
    quickSort(doubleArray, 10);

    cout << "array of int:";
    printArray(intArray, 10);

    cout << "array of double: ";
    printArray(doubleArray, 10);
    return 0;
}