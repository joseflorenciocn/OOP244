// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/15
// Author: Jose Florencio Coelho Neto
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double balance, double trans, double fee) : Account(balance)
	{
		if (trans > 0) m_tfee = trans;
		else m_tfee = 0;

		if (fee > 0) m_mfee = fee;
		else m_mfee = 0;
	}
	
	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double bal)
	{
		double fee;
		fee = (bal-m_tfee);

		if (fee > 0)
		{
			Account::credit(fee);
			return 1;
		}
		
		else return 0;
	}


	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double bal)
	{
		double fee;
		fee = (bal + m_tfee);

		if (fee > 0)
		{
			Account::debit(fee);
			return 1;
		}

		else return 0;
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd()
	{
		debit(m_mfee);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& out) const
	{
		out << "Account type: Chequing" << std::endl;
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << std::endl;
		out << "Per Transaction Fee: " << m_tfee << std::endl;
		out << "Monthly Fee: " << m_mfee << std::endl;

	}



}