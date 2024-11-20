#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isLessThanTwo(int i)
{
	return i < 2;
}

int main()
{
    std::vector<double> ARR = { 2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0 };

    auto POS_4_5 = std::find(ARR.begin(), ARR.end(), 4.5);
    if (POS_4_5 != ARR.end()) {
        std::cout << "Position of 4.5: " << std::distance(ARR.begin(), POS_4_5) << std::endl;
    }

    auto POS_LT_2 = std::find_if(ARR.begin(), ARR.end(), isLessThanTwo);
    if (POS_LT_2 != ARR.end()) {
        std::cout << "Position of first element less than 2: " << std::distance(ARR.begin(), POS_LT_2) << std::endl;
    }

    std::vector<double> SEQ = { 2.4, 4.5 };
    auto POS_SEQ = std::find_end(ARR.begin(), ARR.end(), SEQ.begin(), SEQ.end());
    if (POS_SEQ != ARR.end()) {
        std::cout << "Position of sequence {2.4, 4.5}: " << std::distance(ARR.begin(), POS_SEQ) << std::endl;
    }

    std::vector<double> LIST = { 34, 55, 2.4, 4.5 };
    auto POS_COMMON = std::find_first_of(ARR.begin(), ARR.end(), LIST.begin(), LIST.end());
    if (POS_COMMON != ARR.end()) {
        std::cout << "Position of first common element: " << std::distance(ARR.begin(), POS_COMMON) << std::endl;
    }

    return 0;
}