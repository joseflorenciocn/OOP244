#include <iostream>
#include <cstring>
#include "Contact.h"


using namespace std;

namespace sict
{

	Contact::Contact()
	{
		this->m_pnum = nullptr;
		this->m_name[0] = '\0';
		this->m_size = 0;

	}

	Contact::Contact(const char* name, const long long* num, const int size)
	{
		*this = Contact();
		int m_flag=0, flag=0;
		for (int i = 0; i < size; i++)
		{
			if (isValid(num[i]))
			{
				m_flag++;
			}
		}
		long long* valid_phone = new long long[m_flag];
		//char tel_number[20];
		// allocate memory to store the new array
		//char* tmp = new char[20];
		// copy from the array into the tmp
		//see the valid numbers
		for (int i = 0; i < size; i++)
		{
			if (isValid(num[i]))
			{
				valid_phone[flag] = num[i];
				flag++;
			}

		}

		//converter

		for (int j = 0; j < m_flag; j++)
		{
			m_pnum[j] = num_convert[j];
		}

		strcpy(this->m_name, name);
		this->m_size=m_flag;

	}

	Contact::~Contact()
	{
		delete[] m_pnum;
		
	}

	bool Contact::isValid(const long long* test)
	{
		int num_dig

	bool Contact::isValid(const long long* test)
	{
		int dig = strlen(test);
		if (dig == 11)
		{
			char ccode[2], num_final[18];
		}
		else 
		{ 
			char cccode[3], num_final[19]; 
		}
		char acode[4];
		char num[8];

		num_final[0] = "(+";
		

		
			if ( dig < 11 || dig = > 13) return nullptr;
			else
			{
				if(dig==11)
				{
					ccode[0] = teste[0];
					ccode[1] = "/0";
					for (int i = 1; i < 4; i++)
					{
						acode[i - 1] = teste[i];
					}
					for (int j = 4; j < dig; j++)
					{
						num[j - 4] = teste[j];
					}
				else
				{
					ccode[0] = teste[0];
					ccode[1] = teste[1];
					ccode[2] = "/0";
					for (int i = 2; i < 5; i++)
					{
						acode[i - 2] = teste[i];
					}
					for (int j = 5; j < dig; j++)
					{
						num[j - 5] = teste[j];
					}
				}

				if (ccode[0] == "0" || num[0] =="0") return nullptr;
				else
				{
					strcat(num_final, ccode);
					strcat(num_final, ") ");
					strcat(num_final, acode);
					strcat(num_final, " ");
					strcat(num_final, num);

					return num_final;
				}

			}

	}

	bool isEmpty() const;
	void display() const;

}