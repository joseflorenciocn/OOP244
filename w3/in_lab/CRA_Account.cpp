#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
	
	void CRA_Account::setEmpty()
	{
		m_pfirst_name = nullptr;
		m_plast_name = nullptr;
		m_sin = 0;
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		setEmpty();

		if (nullptr != familyName && nullptr != givenName)
		{

			delete[] m_pfirst_name;
			delete[] m_plast_name;

			int size_family = strlen(familyName);
			int size_given = strlen(givenName);

			m_pfirst_name = new char[size_given + 1];
			m_plast_name = new char[size_family + 1];

			strcpy(m_pfirst_name, givenName);
			strcpy(m_plast_name, familyName);

			m_sin = sin;
		}

	}

	bool CRA_Account::isEmpty() const
	{

		if (m_pfirst_name != nullptr && m_plast_name != nullptr && m_sin != 0)
		{
			if (m_sin > min_sin && m_sin < max_sin)	return false;

			else return true;
		}
		else return true;

	}

	void CRA_Account::display() const
	{
		if (m_pfirst_name != nullptr && m_plast_name != nullptr && m_sin != 0)
		{
			cout << "Family Name: " << m_plast_name << endl;
			cout << "Given Name : " << m_pfirst_name << endl;
			cout << "CRA Account: " << m_sin << endl;
		}

		else cout << "Account object is empty!" << endl;
	}

}
