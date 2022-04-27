#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Person.h"
using namespace std;


class Employee : public Person	
{
	friend ostream& operator<<(ostream& output, const Employee& customer);
private:
	float salary=0.0;


public:
	Employee(string = "", string = "",string="",string="",float = 0.0, int = 0, int = 0, int = 0);

	
	float getSalary()const;
	string getRole() override;
	void printInfo() override;
};
#endif
