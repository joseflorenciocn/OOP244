// Final Project Milestone 5
// Version 2.0.1
// Date	2017-12-22
// Author Jose Florencio Coelho Neto
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_PERISHABLE_H
#define SICT_PERISHABLE_H

#include <fstream>
#include "NonPerishable.h"
#include "Date.h"

namespace sict
{


	class Perishable : public NonPerishable
	{

		Date m_date;

public:

		Perishable() : NonPerishable('P') {};

	//	Perishable(const NonPerishable& other); //Copy constructor
	//	Perishable& operator=(const NonPerishable& other); //Copy Assignment

		virtual std::fstream& store(std::fstream& file, bool newLine = true) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear) const;
		virtual std::istream& read(std::istream& is);

		const Date& expiry() const;

	};

	//Helper Functions

	Product* CreatePerishable();



}


#endif