/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 9/22/2017
// Author Jose Florencio Coelho Neto
// Description
// Function definition
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

using namespace std;

// TODO: the sict namespace
namespace sict
{

	void display(const Kingdom& pKingdom)
	{
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}

	// TODO:definition for display(...)
	void display(const Kingdom* pKingdom, int counter)
	{

		int total = 0;


		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

			for (int i = 0; i < counter; i++)
			{
				total += pKingdom[i].m_population;
				cout << i+1 << ". " << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
			}
		
			cout << "------------------------------" << endl;
			cout << "Total population of SICT: " << total << endl;
			cout << "------------------------------" << endl;

		
	}

}
     
