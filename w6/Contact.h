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
		bool isValid(const long long* test);

	private:

		char m_name[20];
		char* m_pnum;
		int m_size;
	};

	
}

#endif