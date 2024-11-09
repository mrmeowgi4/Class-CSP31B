// Search for "WRITE YOUR CODE" to complete this program
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename ElementType, typename ContainerType>
ElementType maxElement(const ContainerType& container)
{
    int size,i,j;
    ElementType bigOutOfCompare;

    size = container.size();
    bigOutOfCompare = container[0];

    for (i = 0; i < size; i++)
    {
        
        if (container[i] > bigOutOfCompare)
        {
            bigOutOfCompare = container[i];
        }
    }

    return bigOutOfCompare;
}

template<typename ElementType, typename ContainerType>
ElementType minElement(const ContainerType& container)
{
    int size, i;
    ElementType small;

    size = container.size();
    small = container[0];

    for (i = 0; i < size; i++)
    {

        if (container[i] < small)
        {
            small = container[i];
        }
    }

    return small;
}

int main()
{
    vector<string> stringVector{ "red", "green", "blue", "yellow", "orange", "purple", "gray", "white" };
    cout << "The maximum string is " <<
        (maxElement<string, vector<string>>(stringVector)) << endl;
    

    vector<int> intVector(8);
    cout << "Enter eight integers: ";
    for (unsigned i = 0; i < 8; i++)
        cin >> intVector[i];
    cout << "The maximum int is " <<
        (maxElement<int, vector<int>>(intVector)) << endl;
    cout << "The minimum int is " <<
        (minElement<int, vector<int>>(intVector)) << endl;

    return 0;
}