//BankAccount.cpp
#include "BankAccount.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

BankAccount::BankAccount(string sn, float bal) {

	accountNumber = sn;
	balance = bal;
}
void BankAccount::setAccountNumber(string x) {
	string accountnumber = x;
}

float BankAccount::operator+(float num) {
	float sum = 0;
	sum = balance + num;
	return sum;
}

string BankAccount::getAccountNumber() {
	return accountNumber;
}

bool BankAccount::withdraw(float amount) {
	if (amount < 0) {
		cout << "Invalid ammount" << endl<<endl;
		return false;
	}
	if (amount > balance) {
		cout << "Ammount exceeds balance" << endl<<endl;
		return false;
	}
	balance -= amount;
	return true;
}

bool BankAccount::deposit(float amount) {
	if (amount < 0) {
		cout << "Invalid ammount" << endl<<endl;
		return false;
	}
	balance += amount;
	return true;
}

void BankAccount::setBalance(float bal) {
	balance = bal;
}
float BankAccount::getBalance()
{
	return balance;
}

void BankAccount::printInfo() {
	cout <<left<<setw(10)<< accountNumber
		<<"$" <<setw(10) <<std::fixed<< setprecision(1) << balance<<getAccountType()<<endl;
}
string BankAccount::getAccountType()
{
	return "normal";
}


