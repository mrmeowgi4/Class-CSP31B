#include<iostream>
#include<stdexcept>
#include<string>
#include<cctype>
using namespace std;

#define p(FMT, ...) \
    do { \
        printf(FMT "\n", __VA_ARGS__); \
    } while(0);       


int hex2Dec(const string& hexString);
int convertHexToDec(char ch);

int hex2Dec(const string& hexString)
{
    int value = 0;
    for (unsigned int i = 0; i < hexString.size(); i++)
        value = value * 16 + convertHexToDec(toupper(hexString[i]));
    return value;
}

// The function returns an int for a hex digit. 
// Throws an invalid_argument("Not a hex number") if the hex character is invalid
int convertHexToDec(char ch)
{
    auto hi = ch;

    return  (hi >= '0' && hi <= '9') * (hi - '0') +
            (hi >= 'A' && hi <= 'F') * (hi - 'A' + 10) +
            (hi >= 'a' && hi <= 'f') * (hi - 'a' + 10);
}

int main()
{
    string hexString;


    try
    {
        p("Please type in a string: ");
        cin >> hexString;

        auto idk = hex2Dec(hexString);
        p("Value: %d", idk);

    }
    catch (invalid_argument& ex)
    {
        p("Not a valid hex number.");
    }

    return 0;
}