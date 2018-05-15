// TODO: add your headers here
#include <iostream>
#include "Passenger.h"
#include <cstring>

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
			
		else cout << m_pname << " - " << m_pdest << endl;

	}


	void Passenger::setEmpty()
	{
		m_pname = nullptr;
		m_pdest = nullptr;
	}



}

