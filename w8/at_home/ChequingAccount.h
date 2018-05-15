// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Version: 2.0
// Date: 2017/12/15
// Author: Jose Florencio Coelho Neto
// Description:
// This file defines the ChequingAccount class
///////////////////////////////////////////////////

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account
	{
		double m_tfee;
		double m_mfee;


	public:
		// TODO: constructor initializes account balance and transaction fee
		ChequingAccount(double, double = 0, double = 0);

		// TODDO: credit adds +ve amount to the balance
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);

		// TODO: month end
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream&) const;

	};
}
#endif