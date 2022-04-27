//Person.h
#ifndef PERSON_H
#define PERSON_H
#include "Date.h"
#include<string>
using namespace std;

class Person {

	friend ostream& operator<<(ostream& output, const Person& person);

private:
	string firstName;
	string lastName;
	string username;
	string password;
	Date birthDay;

public:
	Person();
	Person(string = "", string = "", string="",string="",int = 0, int = 0, int = 0);
	
	void setFirstName(string);
	void setLastName(string);
	void setUsername(string);
	void setPassword(string);
	string getUsername()const;
	string getPassword()const;
	void setBirthDay(Date);
	Date getBirthDay() const;
	string getFirstName()const;
	string getLastName()const;
	virtual string getRole();
	virtual void printInfo();
};
#endif