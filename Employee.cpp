#include "Employee.h"
#include<iomanip>
#include<string>
#include<iostream>

using namespace std;

ostream& operator<<(ostream& output, const Employee& customer) {
	output << customer.getFirstName() << " " << customer.getLastName();
	return output;
}

Employee::Employee(string fN, string lN,string username,string password,float slr, int m, int d, int y) :Person(fN, lN,username,password,m, d, y) {
	salary = slr;
}


float Employee::getSalary()const {
	return salary;
}


void Employee::printInfo()
{
	cout << std::fixed
		<< getFirstName() << " " << getLastName() << endl
		<< "Birth Date: " << getBirthDay() << endl
		<<"Salary: $" <<setprecision(1)<<getSalary()<<endl<<endl;
}

string Employee :: getRole() {
	return "employee";
}