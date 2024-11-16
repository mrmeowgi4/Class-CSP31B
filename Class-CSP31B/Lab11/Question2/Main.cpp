#include <iostream>
#include <vector>

using namespace std;

template<typename ElementType, typename ContainerType>
int countElement(ContainerType& container, const ElementType& value) {
	int cnt = 0;

	for (int i = 0; i < container.size(); i++)
	{
		if (container[i] == value)
		{
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	int val = 8;
	int list1[] = { 3,5,1,8,2,8,7,6,8 };
	vector<int> intvector(list1, list1 + 9);
	cout << "Max value in list is: " << countElement<int, vector<int>>(intvector, val);

}