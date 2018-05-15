// TODO: add your headers here
#include <iostream>
#include "Passenger.h"
#include <cstring>
#include <iomanip>

using namespace std;

// TODO: continue your namespace here
namespace sict
{

	// TODO: implement the default constructor here
	Passenger::Passenger() 
	{
		setEmpty();
	}

	Passenger::~Passenger()
	{

//		delete[] m_pname;
//		delete[] m_pdest;

	}
	

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* dest)
	{
		int size_name = 0;
		int size_dest = 0;
		setEmpty();

		if (name != nullptr && dest != nullptr)
		{
			size_name = strlen(name);
			size_dest = strlen(dest);

//			delete[] m_pname;
//			delete[] m_pdest;

			if (size_name != 0 && size_dest != 0)
			{

				m_pname = new char[size_name+1];
				m_pdest = new char[size_dest+1];

				strcpy(m_pname, name);
				strcpy(m_pdest, dest);

				m_year = 2017;
				m_month = 6;
				m_day = 1;

			}
			else setEmpty();
		}
		else setEmpty();


	}


	Passenger::Passenger(const char* name, const char* dest, int year, int month, int day)
	{
		int size_name = 0;
		int size_dest = 0;
		setEmpty();

		if (name != nullptr && dest != nullptr)
		{
			size_name = strlen(name);
			size_dest = strlen(dest);

			//			delete[] m_pname;
			//			delete[] m_pdest;

			bool valid = size_name != 0 && size_dest != 0 && year < 2021 && year > 2016 && month < 13 && month > 0 && day < 32 && day > 0;

			if (valid)
			{

				m_pname = new char[size_name + 1];
				m_pdest = new char[size_dest + 1];

				strcpy(m_pname, name);
				strcpy(m_pdest, dest);

				m_year = year;
				m_month = month;
				m_day = day;

			}
			else setEmpty();
		}
		else setEmpty();


	}


	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const
	{

		if (m_pname == nullptr || m_pdest == nullptr || strlen(m_pname) == 0 || strlen(m_pdest) == 0) return true;
		else return false;


	}
	// TODO: implement display query here
	void Passenger::display() const
	{
		if (isEmpty()) cout << "No passenger!" << endl;
			
		else
		{
			cout << m_pname << " - " << m_pdest << " on " << m_year << "/" << setfill('0') << setw(2) << m_month << "/" << m_day << endl;
		//	cout << setfill('0') << setw(2) << m_day << endl;
		}

	}


	void Passenger::setEmpty()
	{
		m_pname = nullptr;
		m_pdest = nullptr;
		m_year = 0;
		m_day = 0;
		m_month = 0;

	}

	const char* Passenger::name() const
	{

		return m_pname;

	}

	bool Passenger::canTravelWith(const Passenger& check) const
	{
		
		if (check.m_pdest != nullptr)
		{

			if (strcmp(m_pdest, check.m_pdest) == 0) return true;
			else return false;

		}
		else return false;

	}

}

