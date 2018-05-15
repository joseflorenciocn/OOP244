// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: 2.0
// Date: 2017/12/15
// Author: Jose Florencio Coelho Neto
// Description:
// This file defines the Account class
///////////////////////////////////////////////////

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount
	{

		double m_balance;

	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double = 0);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char*, double);

}
#endif
