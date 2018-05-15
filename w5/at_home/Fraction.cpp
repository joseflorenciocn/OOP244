// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace

using namespace std;

namespace sict
{

	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		setEmpty();
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int den)
	{

		if (den > 0 && num >=0)
		{
			this->m_denominator = den;
			this->m_numerator = num;

			reduce();
		}

		else setEmpty();

	}

	Fraction::~Fraction()
	{

	}


	// TODO: implement the max query
	int Fraction::max() const
	{
		if (this->m_denominator > this->m_numerator) return m_denominator;
		else if (this->m_denominator < this->m_numerator) return m_numerator;
		else return m_denominator;
	}
	// TODO: implement the min query
	int Fraction::min() const
	{
		if (this->m_denominator < this->m_numerator) return m_denominator;
		else if (this->m_denominator > this->m_numerator) return m_numerator;
		else return m_denominator;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int a;
		a = gcd();
		this->m_numerator = this->m_numerator / a;
		this->m_denominator = this->m_denominator / a;
	}
	// TODO: implement the display query
	void Fraction::display() const
	{
		if (isEmpty()) cout << "no fraction stored";
		else
		{
			if (this->m_denominator == 1)
			{
				cout << m_numerator;
			}

			else
			{
				cout << m_numerator << "/" << m_denominator;
			}
		}

			
		

	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		if (this->m_denominator > 0 && this->m_numerator >= 0) return false;
		else return true;
	}

	void Fraction::setEmpty()
	{
		this->m_denominator = -1;
		this->m_numerator = -1;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const
	{
		Fraction result;

		if (isEmpty())
		{
			result.setEmpty();
		}

		else
		{
			result.m_denominator = this->m_denominator * rhs.m_denominator;
			result.m_numerator = (this->m_numerator * rhs.m_denominator) + (this->m_denominator * rhs.m_numerator);
		}
		return result;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const
	{
		Fraction result;
		if (isEmpty())
		{
			result.setEmpty();
		}

		else
		{
			result.m_denominator = this->m_denominator * rhs.m_denominator;
			result.m_numerator = this->m_numerator * rhs.m_numerator;
		}

		return result;

	}
	bool Fraction::operator==(const Fraction& rhs) const
	{
		if (isEmpty())
		{
			return false;
		}

		else
		{
			if (this->m_denominator == rhs.m_denominator && this->m_numerator == rhs.m_numerator) return true;
			else return false;
		}

	}
	bool Fraction::operator!=(const Fraction& rhs) const
	{
		if (isEmpty())
		{
			return false;
		}

		else
		{
			if (this->m_denominator == rhs.m_denominator && this->m_numerator == rhs.m_numerator) return false;
			else return true;
		}

	}
	Fraction& Fraction::operator+=(const Fraction& rhs)
	{
		if (isEmpty())
		{
			this->setEmpty();
		}

		else
		{
			*this = (*this + rhs);
		}

		return *this;

	}


}
