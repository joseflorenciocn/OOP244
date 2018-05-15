// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 2.0
// Date: 2017/12/15
// Author: Jose Florencio Coelho Neto
// Description:
// This file implements the Account class
///////////////////////////////////////////////////

#include "Account.h"

namespace sict
{

	double Account::balance() const
	{
		return m_balance;
	}

	// TODO: constructor initializes account balance, defaults to 0.0 
	Account::Account(double bal)
	{

		if (bal > 0) m_balance = bal;
		else m_balance = 0;

	}

	// TODO: credit adds +ve amount to the balance 
	bool Account::credit(double bal)
	{
		if (bal > 0)
		{
			m_balance += bal;
			return 1;
		}

		else return 0;
	}

	// TODO: debit subtracts a +ve amount from the balance
	bool Account::debit(double bal)
	{
		if (bal > 0)
		{
			m_balance -= bal;
			return 1;
		}

		else return 0;
	}

}