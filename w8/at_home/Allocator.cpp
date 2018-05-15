// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2017/12/15
// Author: Jose Florencio Coelho Neto
// Description:
// This file allocates an Account object in dynamic memory
///////////////////////////////////////////////////
#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace sict {

	// define interest rate
	const double rate = 0.05;
	const double t_fee = 0.5;
	const double m_fee = 2;


	// TODO: Allocator function
	iAccount* CreateAccount(const char* name, double balance)
	{
		iAccount* tmp = nullptr;
		
		if (name[0] == 'S')
		{
			tmp = new SavingsAccount(balance, rate);
		}

		else 
		{
			if (name[0] == 'C')
			{
				tmp = new ChequingAccount(balance, t_fee, m_fee);
			}

		}
		return tmp;

	}



}
