#include <iostream>
#include "Queue.h"
int main()
{
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front: " << q.pop() << std::endl; 
    std::cout << "Front: " << q.pop() << std::endl;
    std::cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;

	return 0;
}