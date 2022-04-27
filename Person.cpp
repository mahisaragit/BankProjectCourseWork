#include "Person.h"
#include<iostream>
#include<string>
#include<stdexcept>
#include"Date.h"
using namespace std;



Person::Person(string fN, string lN, string user,string pass,int m, int d, int y) {
	Date date = Date(m, d, y);
	setBirthDay(date);
	setFirstName(fN);
	setLastName(lN);
	setUsername(user);
	setPassword(pass);
}
Person::Person() {

}


void Person::setBirthDay(Date d) {
	birthDay = d;
}
void Person::setFirstName(string fN) {
	if (fN.size() < 2 ) {
	throw invalid_argument("Your Name should be made up of at leat two characters\n");
	}
	else
		firstName = fN;
}

void Person::setLastName(string lN) {
	if (lN.size() < 2 ) {
		throw invalid_argument("Your Last Name should be made up of at least 2 characters\n");
	}
	else
		lastName = lN;
}
void Person::setUsername(string un) {
	username = un;
}

void Person::setPassword(string pw) {
	password = pw;
}
string Person::getUsername()const {
	return username;
}
string Person::getPassword()const {
	return password;
}
Date Person::getBirthDay()const {
	return birthDay;
}
string  Person::getFirstName()const {
	return firstName;
}
string  Person::getLastName()const {
	return lastName;
}

string Person::getRole()
{
	return "person";
}

void Person::printInfo()
{
	cout <<"Person: "<< firstName << " " << lastName<<endl;
}
