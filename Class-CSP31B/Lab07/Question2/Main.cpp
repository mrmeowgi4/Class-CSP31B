#include <iostream>

using namespace std;

template<typename T>
int partition(T a[], int L, int H)
{
    T p = a[H - 1];
    int i = L;

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

void printArray(int a[], int s)
{
    for (int i = 0; i < s; i++)
        cout << a[i] << ",";
    cout << endl;
}

int main()
{
    int testingArr[3] = { 0, 12, -1 };
    quickSort(testingArr, 3);
    printArray(testingArr, 3);
    cout << endl;

    return 0;
}