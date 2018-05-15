/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
// Version 2.0
// 2017/10/04
// Jose Florencio Coelho Neto
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
//
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
#include <cmath>
#include <iomanip>

using namespace std;

namespace sict
{
	
	void CRA_Account::setEmpty()
	{
		m_pfirst_name = nullptr;
		m_plast_name = nullptr;
		m_sin = 0;

		for (int i = 0; i < max_yrs; i++)
		{
			m_retyear[i] = 0;
			m_balance[i] = 0;
		}
	
		m_year = 0;
		m_numyear = 0;
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{

		setEmpty();

		if (isValid(sin))
		{

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

	}

	void CRA_Account::set(int year, double balance)
	{

		if (m_year < max_yrs && isValid(m_sin))
		{
			this->m_balance[m_year] = balance;
			this->m_retyear[m_year] = year;
			this->m_year++;

		}

	}

	bool CRA_Account::isEmpty() const
	{
		int size_first;
		int size_last;

		if (nullptr != m_pfirst_name && nullptr != m_plast_name)
		{
			size_first = strlen(m_pfirst_name);
			size_last = strlen(m_plast_name);
			if (nullptr != m_pfirst_name && size_first != 0 && m_plast_name != nullptr && size_last != 0 && m_sin != 0)	return false;
			else return true;
		}

		else return true;

	}

	bool CRA_Account::isValid(const int sin)
	{
		if (sin > min_sin && sin < max_sin)
		{

			int sin_split[9], sin_tmp, sum[4], sum_split[2], sum1 = 0, sum_f = 0, sum_tmp, sum_f_split[2], sum_f_tmp;
			int num;

			sin_tmp = sin;

			for (int i = 0; i < 9; i++)
			{
				sin_split[i] = sin_tmp % 10;
				sin_tmp = sin / pow(10, (i + 1));
			}

			sum[0] = sin_split[1] + sin_split[1];
			sum[1] = sin_split[3] + sin_split[3];
			sum[2] = sin_split[5] + sin_split[5];
			sum[3] = sin_split[7] + sin_split[7];

			for (int k = 0; k < 4; k++)
			{
				sum_tmp = sum[k];

				for (int j = 0; j < 2; j++)
				{
					sum_split[j] = sum_tmp % 10;
					sum_tmp = sum[k] / pow(10, (j + 1));
				}

				sum1 += sum_split[1] + sum_split[0];
			}

			sum_f = sum1 + sin_split[2] + sin_split[4] + sin_split[6] + sin_split[8];

			sum_f_tmp = sum_f;

			for (int a = 0; a < 2; a++)
			{
				sum_f_split[a] = sum_f_tmp % 10;
				sum_f_tmp = sum_f / pow(10, (a + 1));
			}

			if (sum_f_split[0] == 0) num = (sum_f_split[1] * 10);
			else num = ((sum_f_split[1] + 1) * 10);

			if ((num - sum_f) == sin_split[0]) return true;
			else return false;
		}

		else return false;
	}

	void CRA_Account::y() const
	{

	
		for (int c = 0; c < max_yrs; c++)
		{
			if (this->m_balance[c] > 2) cout << "Year (" << m_retyear[c] << ") balance owing: " << fixed << setprecision(2) << m_balance[c] << endl;	
			else if (this->m_balance[c] < -2) cout << "Year (" << m_retyear[c] << ") refund due: " << fixed << setprecision(2) << (m_balance[c]*-1) << endl;
				 else cout << "Year (" << m_retyear[c] << ") No balance owing or refund due!" << endl;
		}
		

	}


	void CRA_Account::display() const
	{
		if (m_pfirst_name != nullptr && m_plast_name != nullptr && m_sin != 0)
		{
			cout << "Family Name: " << m_plast_name << endl;
			cout << "Given Name : " << m_pfirst_name << endl;
			cout << "CRA Account: " << m_sin << endl;

			y();
		}

		else cout << "Account object is empty!" << endl;
	}

}
