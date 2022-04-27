//LimitedBankAccount.cpp
#include "LimitedBankAccount.h"
#include<iomanip>
#include<string>
#include<iostream>

LimitedBankAccount::LimitedBankAccount(string accountNumber, float balance):BankAccount(accountNumber,balance)
{
}

bool LimitedBankAccount::withdraw(float amount)
{
	if (amount < 0) {
		cout << "Invalid ammount" << endl << endl;
		return false;
	}
	if (amount > getBalance()) {
		cout << "Amount exceeds balance" << endl << endl;
		return false;
	}
	if (amount > 200) {
		cout << "Invalid. Maximum withdraw amount for limited accounts is $200" << endl << endl;
		return false;
	}
	setBalance(getBalance() - amount);
	return true;
}

string LimitedBankAccount::getAccountType()
{
	return "limited";
}

