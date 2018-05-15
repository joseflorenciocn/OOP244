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

		if (name != nullptr && name[0] != '\0')
		{
			int name_size = strlen(name);

			if (name_size <= 20)
			{
				strncpy(m_name, name, name_size);
				m_name[name_size] = '\0';
			}
			else {
				strncpy(m_name, name, 19);
				m_name[19] = '\0';
			}

			int m_flag = 0, flag = 0;
			for (int i = 0; i < size; i++)
			{
				if (isValid(num[i]))
				{
					m_flag++;
				}
			}

			if (m_flag > 0) 
			{

				long long* valid_phone = new long long[m_flag];

				for (int i = 0; i < size; i++)
				{
					if (isValid(num[i]))
					{
						valid_phone[flag] = num[i];
						flag++;
					}

				}

				m_pnum = new long long[m_flag];
				for (int i = 0; i < m_flag; i++)
				{
					m_pnum[i] = valid_phone[i];
				}
				this->m_size = m_flag;

				delete[] valid_phone;
				valid_phone = nullptr;
			}

			else
			{
				this->m_size = 0;
				this->m_pnum = nullptr;

			}

		}

		else
		{
			this->m_name[0] = '\0';
		}
		

	}

	Contact::~Contact()
	{
		delete[] m_pnum;
		
	}


	//Copy Constructor
	Contact::Contact(const Contact& other)
	{
		this->m_size = other.m_size;
		strcpy(this->m_name, other.m_name);

		if (other.m_pnum != nullptr)
		{

			this->m_pnum = new long long[this->m_size];
			
			for (int i = 0; i < m_size; i++)
			{
				this->m_pnum[i] = other.m_pnum[i];
			}

		}

		else this->m_pnum = nullptr;
		
	}

	//Copy assignment
	Contact& Contact::operator=(const Contact& other)
	{
		if (this != &other)
		{
			this->m_size = other.m_size;
			strcpy(this->m_name, other.m_name);

			if (other.m_pnum != nullptr)
			{
				delete[] this->m_pnum;

				this->m_pnum = new long long[this->m_size];

				for (int i = 0; i < m_size; i++)
				{
					this->m_pnum[i] = other.m_pnum[i];
				}

			}

			else this->m_pnum = nullptr;
		}

		return *this;

	}

	//Overload Operator
	Contact& Contact::operator+=(const long long num)
	{
			
		Contact tmp;

		strcpy(tmp.m_name, this->m_name);
		tmp.m_size = this->m_size;

		tmp.m_pnum = new long long[tmp.m_size];

		for (int i = 0; i < this->m_size; i++)
		{

			tmp.m_pnum[i] = this->m_pnum[i];

		}

		delete[] this->m_pnum;

		this->m_pnum = new long long[this->m_size + 1];


		for (int i = 0; i < this->m_size; i++)
		{
			this->m_pnum[i] = tmp.m_pnum[i];

		}

		this->m_pnum[this->m_size] = num;
		this->m_size++;

		return *this;

	}

	Contact Contact::operator+(const long long num)
	{
		Contact tmp;

		strcpy(tmp.m_name, this->m_name);
		tmp.m_size = this->m_size + 1;

		delete[] tmp.m_pnum;

		tmp.m_pnum = new long long[tmp.m_size];


		if (this->m_size != 0)
		{
			for (int i = 0; i < this->m_size; i++)
			{

				tmp.m_pnum[i] = this->m_pnum[i];

			}

			
		}

		else tmp.m_pnum[tmp.m_size - 1] = num;
		
		return tmp;


	}

		
	bool Contact::isValid(const long long& test_num) const
	{
		long long num_aux = test_num;
		int num_dig=0;
		int* num_final = nullptr;

		if (test_num > 0) num_dig = numberOfDigits(test_num);

	
		if (num_dig == 11 || num_dig == 12) 
		{

			// allocate memory for the phone digits array
			num_final = new int[num_dig];

			// convert int to array
			convertToArray(num_final, num_aux, num_dig);

			if (num_final[num_dig - 7] != 0 && num_final[num_dig - 10] != 0 && (num_final[0] + num_final[num_dig - 11]) != 0) return 1;

			// deallocate memory
			delete[] num_final;
			num_final = nullptr;
		}
	
	return 0;
	}

	bool Contact::isEmpty() const
	{
		if (m_name != nullptr && m_name[0] != '\0' ) return 0;
		else return 1;
	}
	void Contact::display() const
	{
		if (isEmpty()) 
		{
			cout << "Empty contact!" << endl;
		}
		else 
		{
			cout << m_name << endl;

			if (m_size > 0) 
			{
				for (int i = 0; i < m_size; i++) 
				{
					// check number of digits and declare the array
					int digits = numberOfDigits(m_pnum[i]);
					int* num_final = new int[digits];

					// convert the number to array of digits
					convertToArray(num_final, m_pnum[i], digits);

									// print the phone number depending on the number of digits
					if (digits == 11) {
						// country code
						cout << "(+" << num_final[0] << ") ";
						// area code
						cout << num_final[1] << num_final[2] << num_final[3] << " ";
						// number
						cout << num_final[4] << num_final[5] << num_final[6] << "-" << num_final[7] << num_final[8] << num_final[9] << num_final[10] << endl;
					}
					else if (digits == 12) {
						// country code
						cout << "(+" << num_final[0] << num_final[1] << ") ";
						// area code
						cout << num_final[2] << num_final[3] << num_final[4] << " ";
						// number
						cout << num_final[5] << num_final[6] << num_final[7] << "-" << num_final[8] << num_final[9] << num_final[10] << num_final[11] << endl;
					}

					// deallocate memory for the array
					delete[] num_final;
					num_final = nullptr;
				}
			}
		}

	}


	// convert to array helper function
	int* convertToArray(int* emptyArray, long long number, const int& numberOfDigits) 
	{

		//fill the array with the split number
		for (int i = numberOfDigits - 1; i >= 0; i--) 
		{
			emptyArray[i] = number % 10;
			number /= 10;
		}

		return emptyArray;
	}

	// number of digits
	int numberOfDigits(long long phone) 
	{
		int result = 0;

		// count number of digits
		while (phone) 
		{
			result++;
			phone /= 10;
		}

		return result;
	}

}