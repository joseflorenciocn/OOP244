// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingAccount.h
// Version: 2.0
// Date: 2017/12/15
// Author: Jose Florencio Coelho Neto
// Description:
// This file defines the SavingsAccount class
///////////////////////////////////////////////////

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {

	class SavingsAccount : public Account 
	{

		double m_rate;

	public:
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

			// TODO: perform month end transactions
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
		void display(std::ostream&) const;
	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char*, double);

}
#endif
