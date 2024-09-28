#include <iostream>
#include <string>
using namespace std;


// Given string s = "ABCDEF", we let a = 'A', and 
// sum = 0.
// 
// therefore:
//
// "ABCDEF"
//  ^-------- We found 'A', so: sum = sum + 1
// sum=1
//
// "BCDEF"
//  ^--------- This isn't 'A' so: sum = sum + 0
// sum=1
// 
// "CDEF"
//  ^--------- Neither is this, sum = sum+0
// sum=1
// 
// ... and so on and so on... We continue splitting the string into substrings till the final substring is fully empty.
// 
// ""
// ^-------- This is nothing, return 0 in a if condition - leaving our sum equaling to 1. We will then return this value back
// and we will have that, throughout the entire recursive call, sum=1 with a='A' and s="ABCDEF"
//
int count(const string& s, char a)
{
	int sum;

	if (s == "")
	{
		//empty
		return 0;
	}

	sum = 0;

	if (s.c_str()[0] == a) /* probably not the best way to do this */
	{
		sum++;
	}


	return sum += count(s.substr(1), a);
}



int main()
{
	int val = 1234;
	
	
	return 0;
}