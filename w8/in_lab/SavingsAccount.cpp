// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Date: 2017/12/15
// Author: Jose Florencio Coelho Neto
// Description:
// This file implements the SavingsAccount class
///////////////////////////////////////////////////

#include "SavingsAccount.h"

namespace sict
{

	// TODO: constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance)
	{

		if (rate > 0) m_rate = rate;
		else m_rate = 0;

	}

	// TODO: perform month end transactions
	void SavingsAccount::monthEnd()
	{
		double interest;
		interest = (balance()*m_rate);
		credit(interest);

	}

	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& out) const
	{

		out << "Account type: Savings" << std::endl;
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Balance: $" <<balance() << std::endl;
		out << "Interest Rate (%): " << m_rate*100 << std::endl;

	}




}

