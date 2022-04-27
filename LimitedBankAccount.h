//LimitedBankAccount.h
#ifndef LIMITEDBANKACCOUNT_H
#define LIMITEDBANKACCOUNT_H
#include "BankAccount.h"

#include <string>
using namespace std;


class LimitedBankAccount : public BankAccount
{


public:
	LimitedBankAccount(string, float);
	bool withdraw(float) override;
	string getAccountType() override;
};
#endif
