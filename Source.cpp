//Source.cpp
#include "Customer.h"
#include"BankAccount.h"
#include"Date.h"
#include<iostream>
#include"Employee.h"
#include<iomanip>
#include <string>
#include<stdexcept>
#include<algorithm>
#include "LimitedBankAccount.h"

using namespace std;
vector<Person*>people; 
Person* user = NULL;
void init() { 
	
	static Employee employee1("Jacob", "Oconnor", "jacob", "jacob",3500.0, 12, 12, 1981); //initializes objects
	static Employee employee2("Martha", "Rogen", "martha", "martha", 2700.5, 1, 4, 1998);
	static Employee employee3("Ralph", "Archur", "ralph", "ralph",3000.0, 7, 30, 1981); 
	static Customer customer1("Marshal", "Mathers", "marshal", "marshal", 10, 17, 1972);
	static Customer customer2("Jon", "Bosewick", "jon", "jon", 2, 29, 1996);

	static BankAccount bc1 = BankAccount("123", 3500.50);  
	static BankAccount b1c2 = BankAccount("124", 2200.20);
	static LimitedBankAccount b2c2 = LimitedBankAccount("125", 9306.50);
	static BankAccount b3c2 = BankAccount("128", 79951.50);

	customer1.addBankAccount(&bc1);
	customer2.addBankAccount(&b1c2);
	customer2.addBankAccount(&b2c2);
	customer2.addBankAccount(&b3c2);

	people.push_back(&employee1);
	people.push_back(&employee2);
	people.push_back(&employee3);
	people.push_back(&customer1);
	people.push_back(&customer2);
}

Person* validateUser(string username, string password) {
	for (int i = 0; i < people.size(); i++) {
		if (username == people[i]->getUsername()) {
			if (password == people[i]->getPassword())
				return people[i];
			return NULL;
		}
	}
	return NULL;
}
Customer* searchCustomer(string firstName, string lastName) {
	for (int i = 0; i < people.size(); i++) {
		if (firstName == people[i]->getFirstName() && lastName == people[i]->getLastName() && people[i]->getRole()=="customer") {
			return (Customer*)people[i];
		}
	}
	return NULL;
}
void handleEmployee() {
	int choice = 0;
	while (choice != -1 && choice !=4) {
		cout << endl
			<< "***Employee Menu" << endl
			<< "Type the number of the option you want to execute" << endl
			<< "1) View personal information" << endl
			<< "2) Search for customer" << endl
			<< "3) View all customer information" << endl
			<< "4) Log out" << endl
			<< "-1) exit" << endl << endl
			<< "Choice: ";
		cin >> choice; 
		cout << endl;

		if (choice == 1) {
			user->printInfo();
		}
		else if (choice == 2) {
			string firstName;
			string lastName;
			Customer* customer = NULL;
			while (customer == NULL && firstName != "-1" && lastName != "-1") {  
				cout << "Enter customer's first name and last name" << endl;
				cout << "customer: ";
				
				cin >> firstName >> lastName;
				cout << endl;

				if (firstName == "-1" || lastName == "-1") {
					cout << "search canceled" << endl;
					continue;
				}
				customer = searchCustomer(firstName, lastName);
				if (customer==NULL) {   
					cout << "Customer not found"<<endl;
					cout << "******************" << endl;
					continue;
				}
				customer->printInfo();
			}
			
		}
		else if (choice == 3) {
			cout << left << setw(20) << "Customer name" << setw(10) << "Accounts" << "Total Balance" << endl;
			for (Person* person: people) {
				if (person->getRole() == "customer") {
					cout << *person; 
				}
					
			}
		}
		else if (choice == 4) {
			cout << "See you again!" << endl << endl;
			user = NULL;
		}
		else if (choice == -1) {
			cout << "Goodbye!" << endl<<endl;
		}          
		else {
			cout << "Invalid choice" << endl << endl;
		}
		cout << "*********************************************"<<endl;
	}
	
	
}
void handleCustomer() {
	int choice = 0;
	while (choice != -1 && choice != 4) {
		cout << endl 
			<< "***Customer Menu" << endl
			<< "Type the number of the option you want to execute" << endl
			<< "1) View personal information" << endl
			<< "2) Withdraw from account" << endl
			<< "3) deposit to account" << endl
			<< "4) Log out" << endl
			<< "-1) exit" << endl << endl
			<< "Choice: ";
		cin >> choice;
		cout << endl;

		if (choice == 1) {
			user->printInfo();
		}
		else if (choice == 2) {
			Customer* customer = (Customer*)user;
			float amount;
			string accountNumber = "";
			while (accountNumber == "") {
				cout << "Enter Account Number,-1 to cancel" << endl;
				cout << "account number: ";
				cin >> accountNumber;
				if (accountNumber == "-1")
					continue;
				bool valid = customer->checkAccountNumber(accountNumber);
				if (!valid) {
					cout << "Invalid account Number" << endl << endl;
					accountNumber = "";
					continue;
				}
				cout << endl;
				cout << "Enter amount to withdraw" << endl;
				cout << "Amount: $";
				cin >> amount;
				cout << endl;

				bool success = customer->withdraw(accountNumber, amount);
				if (success) {    
					cout << "Transaction succeeded, remaining balance: $ " << std::fixed << setprecision(2) << customer->getBalanceForAccount(accountNumber)<<endl<<endl;
				}
				else {
					cout << "Transaction failed"<<endl<<endl;
				}
			}

		}
		else if (choice == 3) {
			Customer* customer = (Customer*)user;
			float amount;
			string accountNumber= "";
			while (accountNumber == "") {
				cout << "Enter Account Number,-1 to cancel"<<endl;
				cout << "account number: ";
				cin >> accountNumber;
				if (accountNumber == "-1")
					continue;
				bool valid = customer->checkAccountNumber(accountNumber);
				if (!valid) {
					cout << "Invalid account Number" << endl << endl;
					accountNumber = "";
					continue;
				}
				cout << endl;
				cout << "Enter amount to deposit" << endl;
				cout << "Amount: $";
				cin >> amount;
				cout << endl;

				bool success = customer->deposit(accountNumber, amount);
				if (success) {
					cout << "Transaction succeeded, updated balance: $ " <<std::fixed<<setprecision(2)<< customer->getBalanceForAccount(accountNumber) << endl << endl;
				}
				else {
					cout << "Transaction failed" << endl << endl;
				}
			}
			
		}
		else if (choice == 4) {
			cout << "See you again!" << endl << endl;
			user = NULL;
		}
		else if (choice == -1) {
			cout << "Goodbye!" << endl << endl;
		}
		else {
			cout << "Invalid choice" << endl << endl;
		}
		cout << "*********************************************" << endl;
	}
}

int main() {
	init();

	string role;
	string username = "";
	string password = "";
	//string dummyValidationNumber;

	
		
	while (user == NULL) {
		cout << "Please log in" << endl;
		cout << "username: ";
		cin >> username;
		cout << "password: ";
		cin >> password;
		user = validateUser(username, password);
		if (user == NULL) {
			if (username != "-1" && password != "-1") {
				cout << "invalid username/password" << endl<<endl;
				continue;
			}
			else {
				cout << "Goodbye!" << endl;
				return 0;
			}
		}
		
		if (user->getRole() == "employee") {
			handleEmployee();
		}
		else if (user->getRole() == "customer") {
			handleCustomer();
		}
		else {
			cout << "invalid role" << endl;
			user = NULL;
		}
	}

	return 0;
}

