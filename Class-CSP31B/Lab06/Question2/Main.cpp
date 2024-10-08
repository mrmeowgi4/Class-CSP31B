#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string hi;
	string abc;
	cout << "enter string:" << endl;
	cin >> abc;

	cout << "Enter other string:" << endl;
	cin >> hi;

	// I found this in the docs and i managed to make this 10 times more simpler
	auto hiMalmauga = ::search(abc.begin(), abc.end(), hi.begin(), hi.end()); // for some reason it wasnt recognizing the namespace so i had to do ::search and ::distance
	if (hiMalmauga != abc.end())
	{
		auto dist = ::distance(abc.begin(),hiMalmauga);
		cout << "Yes, it exists at index: " << dist << endl;
	}
	else {
		cout << "Nope, doesn't exist";
	}

	return 0;
}