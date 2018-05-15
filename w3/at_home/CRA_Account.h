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

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account
	{

	public:
		//CRA_Account();
		//~CRA_Account();

		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
		void setEmpty();
		bool isValid(const int sin);
		void y() const;

	private:

		char* m_plast_name;
		char* m_pfirst_name;
		int m_sin;
		int m_retyear[max_yrs];
		float m_balance[max_yrs];
		int m_year;
		int m_numyear;


	};

}



#endif