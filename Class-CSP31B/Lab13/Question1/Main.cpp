#include <iostream>
#include <string>
#include "MyMap.h"

using namespace std;

int main()
{
    // Create a map and add five name and age to the map
    MyMap<string, int> map;
    string name;
    int age;
    for (unsigned i = 0; i < 5; i++) {
        cout << "Enter name and age: ";
        cin >> name >> age;
        map.put(name, age);
    }

    vector<string> v = map.getKeys();
    cout << "The keys are: " << endl;
    for (string& s : v)
        cout << s << " ";
    cout << endl;
    return 0;
}
