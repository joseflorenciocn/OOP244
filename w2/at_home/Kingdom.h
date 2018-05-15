/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 9/22/2017
// Author Jose Florencio Coelho Neto
// Description
// Header file
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
	
// TODO: sict namespace
namespace sict
{
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[32];
		int m_population;
		
		
	};

	void display(const Kingdom& pKingdom);
	// TODO: declare the function display(...), also in the sict namespace
	void display(const Kingdom* pKingdom, int counter);
};

	

#endif 
