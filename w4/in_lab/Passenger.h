// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict
{

	class Passenger
	{
	public:
		Passenger();
		Passenger(const char* name, const char* dest);
		~Passenger();
		void setEmpty();
		bool isEmpty() const;
		void display() const; 

	private:

		char *m_pname;
		char *m_pdest;


	};

}


#endif 
