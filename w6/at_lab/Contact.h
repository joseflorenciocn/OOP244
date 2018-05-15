// TODO: header file guard
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
// TODO: create namespace
namespace sict
{

	class Contact
	{
	public:
		Contact();
		Contact(const char* name, const long long* num, const int size);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool isValid(const long long& test_num) const;


	private:

		char m_name[20];
		long long* m_pnum;
		int m_size;
	};

	//-- helper functions --//

	// convert and empty array to an array of digits
	int* convertToArray(int* emptyArray, long long number, const int& numberOfDigits);

	// returns the number of digits of a long long number
	int numberOfDigits(long long phone);
	
}

#endif