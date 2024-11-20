#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<float> arra = { 2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0 };

    sort(arra.begin(), arra.end());

    for (int i = 0; i < arra.size(); i++) {
        cout << arra[i] << endl;
    }

    bool boo = binary_search(arra.begin(), arra.end(), 6.7);
    cout << boo << endl;

    return 0;
}