#include <iostream>
#include <string>
using namespace std;

#define p(FMT, ...) \
    do { \
        printf(FMT "\n", __VA_ARGS__); \
    } while(0);							  // A Much better print function that
										  // allows for easy formatting, and autonewlines.


void reverseDisplay(int value)
{

	if (value == 0)
	{
		//printf("DEBUG!!! REMOVE THIS!!!!");
		return;
	}


	int m = value % 10;
	printf("%d", m);

	reverseDisplay(value/10);
}

int sumDigits(int n)
{
	int sum = 0;
	if (n == 0)
	{
		return 0;
	}
	
	int m = n % 10;

	// Explanation:
	// *------------------------------- |
	// f(123) = m   + f(n/10)----|   |  |
	// f(12) = m   + f(n/10)<----|   |  |
	// f(1) = m   + f(n/10)<-----|   |  |
	// f(0) = equals zero.<------|------|
	sum = m + sumDigits(n / 10); 
									

	return sum;
}

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
	p("Sample value: %d", val);
	p("Sample value but with all digits adding up to a single sum = %d", sumDigits(val));
	p("Sample value in reverse:  ");
	reverseDisplay(val);
	p("\n");


	p("Here is the string AABBAAAMMC But with how many A's there in this entire string: %d", count("AABBAAAMMC", 'A'));

	return 0;
}