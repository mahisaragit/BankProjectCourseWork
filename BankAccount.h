//BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using namespace std;


class BankAccount 
{

private:
	string accountNumber;
	 float balance;

public:
	float operator+(float);

	BankAccount(string,float);

	void setAccountNumber(string);
	string getAccountNumber();

	void setBalance(float);
	float getBalance();

	virtual bool withdraw(float);
	bool deposit(float);

	void printInfo();
	virtual string getAccountType();
};
#endif
