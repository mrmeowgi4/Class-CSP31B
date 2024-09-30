
#include <iostream>
#include "Saving.h"
#include "Checking.h"

#define p(FMT, ...) \
    do { \
        printf(FMT "\n", __VA_ARGS__); \
    } while(0);       

using namespace std;


int main()
{
    Saving saving;
    Checkings checking;
    saving.setBalance(123);
    checking.setBalance(243);
    saving.setOverdraftLimit(500);
    cout << saving.toString() << endl;
    cout << checking.toString() << endl;

    return 0;
}