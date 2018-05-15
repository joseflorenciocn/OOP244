// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict
{
	
		// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int m_numerator;
		int m_denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
		void setEmpty();

	public:

		Fraction();
		Fraction(int num, int den);
		~Fraction();

		// TODO: declare public member functions
		bool isEmpty() const;
		void display() const;
		
	

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;

		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);

	};

}

#endif