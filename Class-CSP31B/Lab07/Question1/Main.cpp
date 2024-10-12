#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
	
	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size - i - 1; j++)
		{
			// pair
			int first = arr[j];
			int last = arr[j + 1];
			//

			if (first > last)
			{
				arr[j] = last;
				arr[j + 1] = first;
				break;
			}
		}
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i]<<", ";
}

int main()
{
	int testingArr[10] = {0};
	testingArr[9] = 63464;
	testingArr[4] = -1;

	
	int otherTestingArr[10] = { 0 };
	otherTestingArr[9] = 4;
	otherTestingArr[4] = -1;

	bubbleSort(testingArr, 10);
	printArray(testingArr, 10);
	cout << endl;
	bubbleSort(otherTestingArr, 10);
	printArray(otherTestingArr, 10);

	return 0;
}