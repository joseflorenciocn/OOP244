#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account
	{

	public:
		//CRA_Account();
		//~CRA_Account();

		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void setEmpty();

	private:

		char* m_plast_name;
		char* m_pfirst_name;
		int m_sin;

	};

}



#endif