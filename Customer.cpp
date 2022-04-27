//Customer.cpp
#include "Customer.h"
#include<stdexcept>
#include<iomanip>
#include<string>
#include<iostream>
#include "Date.h"

using namespace std;

ostream& operator<<(ostream& output, const Person& person) {
	const Customer *customer = ( Customer*)&person;
	string fullName = customer->getFirstName() + " " + customer->getLastName();
	output << left<<setw(20) << fullName << setw(10) << customer->getNumberOfBankAccounts()<<"$" << customer->getTotalBalance()<<endl;
	return output;
}

Customer::Customer(string fN, string lN,string user,string pass, int m, int d, int y) :Person(fN,lN,user,pass,m,d,y) {
	
}

void Customer::addBankAccount(BankAccount *account)
{
	bankAccounts.push_back(account);
}
BankAccount* Customer::getBankAccount(string accountNumber) {
	for (int i = 0; i < bankAccounts.size();i++) {
		if (bankAccounts[i]->getAccountNumber() == accountNumber) {
			return bankAccounts[i];
		}
	}
	return NULL;
}
float Customer::getBalanceForAccount(string accountNumber)
{
	for (BankAccount* account : bankAccounts) {
		if (account->getAccountNumber() == accountNumber) {
			return account->getBalance();
		}
	}
	return -1;
}

float Customer::getTotalBalance()const
{
	float sum = 0;
	for (BankAccount* account : bankAccounts) {
		sum = *account + sum;
	}
	return sum;
}

int Customer::getNumberOfBankAccounts() const
{
	return bankAccounts.size();
}

bool Customer::checkAccountNumber(string accountNumber)
{
	for (BankAccount* account : bankAccounts) {
		if (account->getAccountNumber() == accountNumber)
			return true;
	}
	return false;
}

bool Customer::withdraw(string accountNumber, float amount)
{
	BankAccount* account = getBankAccount(accountNumber);
	if (account == NULL) {
		cout << "Invalid account"<<endl<<endl;
		return false;
	}
	return account->withdraw(amount);
}

bool Customer::deposit(string accountNumber, float amount)
{
	BankAccount* account = getBankAccount(accountNumber);
	if (account == NULL) {
		cout << "Invalid account"<<endl<<endl;
		return false;
	}

	return account->deposit(amount);
}


void Customer::printInfo() 
{
	cout << "--------------------------" << endl;
	cout << "customer: " << getFirstName()  << " " << getLastName()<<endl<<endl;
	
	cout<<left<<setw(10)<<"Account"<< setw(11)<<"Balance"<<"Type"<<endl;
	for (BankAccount* account : bankAccounts) {
		account->printInfo();
	}
	cout << endl;
	cout << setw(10)<<"Total:" << "$"<<getTotalBalance() << endl << endl;
	cout << "--------------------------" << endl;
}

string Customer::getRole() {
	return "customer";
}

