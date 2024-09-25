#include <iostream>
#include "Student.h"
#include "Person.h"
#include "Staff.h"
#include "Employee.h"
#include "FacultyMember.h"
#include "MyDate.h"
#include <vector>
using namespace std;
int main()
{
	vector<Person*> personPtr;

	Person* personObj = new Person("Hi", "eiofjsioef", "2091111111", "abc@gmail.abc");
	Student* studentObj = new Student("Freshman");
	FacultyMember* facMem = new FacultyMember("Global Elite in CS2", 9999);
	Staff* staffMember= new Staff("Grandmaster in Overwatch 2");

	MyDate date(1, 3, 11);

	Employee* employee = new Employee("Office AB", 1, date);


	personPtr.push_back(personObj);
	personPtr.push_back(studentObj);
	personPtr.push_back(facMem);
	personPtr.push_back(staffMember);
	personPtr.push_back(employee);


	for (Person* p : personPtr)
	{
		cout << p->toString() << endl;
	}

	return 0;
}