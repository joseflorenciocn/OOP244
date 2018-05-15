// Final Project Milestone 5
// Version 2.0.1
// Date	2017-12-22
// Author Jose Florencio Coelho Neto
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Perishable.h"

//using namespace std;

namespace sict 
{
			
	//Public Functions

		
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{

			if (!file.is_open()) 
			{
				std::cerr << "File is not open" << std::endl;
			}
			else 
			{
				NonPerishable::store(file, false);
				file << "," << m_date;

				if (newLine == true) file << std::endl;

							
			}	

			return file;
					
	}

	std::fstream& Perishable::load(std::fstream& file)
	{
		Perishable tmp;

		if (!file.is_open())
		{
			std::cerr << "File is not open" << std::endl;
		}
		else
		{
		//	file.seekg(0);

			tmp.NonPerishable::load(file);
			file.ignore(1);
			file >> tmp.m_date;

			*this = tmp;
				
		}

		

		return file;

	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{

		NonPerishable::write(os, linear);
		
		if (!m_date.emptyState() && !m_date.bad())
		{
			if (linear)
			{
				os << m_date;
			}

			else
			{
				os << std::endl << "Expiry date: " << m_date;
			}

		}

		return os;

	}

	std::istream& Perishable::read(std::istream& is)
	{
		Perishable tmp;

		tmp.NonPerishable::read(is);
			
		is.clear();

		// expiry date
		std::cout << "Expiry date (YYYY/MM/DD): ";
		is >> tmp.m_date;

		if (tmp.m_date.bad())
		{


			// set the error message
			if (tmp.m_date.errCode() == 1)
			{
				tmp.message("CIN_FAILED");
				// force the istr to fail
				is.setstate(std::ios::failbit);
			}

			if (tmp.m_date.errCode() == 2)
			{
				tmp.message("Invalid Year in Date Entry");
				// force the istr to fail
				is.setstate(std::ios::failbit);
			}

			if (tmp.m_date.errCode() == 3)
			{
				tmp.message("MON_ERROR ");
				// force the istr to fail
				is.setstate(std::ios::failbit);
			}

			if (tmp.m_date.errCode() == 4)
			{
				tmp.message("DAY_ERROR");
				// force the istr to fail
				is.setstate(std::ios::failbit);
			}
					
		}
				
		*this = tmp;
		
		return is;
	
	}

	const Date& Perishable::expiry() const
	{
		return this->m_date;
	}

	//Helper Functions

	Product* CreatePerishable()
	{
		return new Perishable;
	}

}