//Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Date.h"
#include "Person.h"
#include "BankAccount.h"
using namespace std;


class Customer : public Person
{
	friend ostream& operator<<(ostream& output, const Person& person);

private:
	vector<BankAccount*> bankAccounts;

public:
	Customer(string = "", string = "",string="",string="",int=0, int = 0, int = 0);
	void addBankAccount(BankAccount*);
	float getBalanceForAccount(string);
	float getTotalBalance()const;
	int getNumberOfBankAccounts()const;
	bool checkAccountNumber(string);
	bool withdraw(string,float);
	bool deposit(string,float);
	void printInfo() override;
	BankAccount* getBankAccount(string);
	string getRole() override;
};
#endif
