// Final Project Milestone 4
// Version 2.0.1
// Date	2017-12-14
// Author Jose Florencio Coelho Neto
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "NonPerishable.h"

//using namespace std;

namespace sict 
{

	
	//Protected Functions
	void NonPerishable::name(const char* name)
	{
		if (name != nullptr)
		{
			if (m_pname == nullptr)
			{
				m_pname = new char[strlen(name) + 1];
				strcpy(m_pname, name);
			}

			else
			{
				delete[] m_pname;
				m_pname = new char[strlen(name) + 1];
				strcpy(m_pname, name);
			}
		}

		else
		{
			if (m_pname != nullptr)
			{
				delete[] m_pname;
				m_pname = nullptr;
			}
		}

	
	}


	const char* NonPerishable::name() const
	{
		return m_pname;
	}

	double NonPerishable::cost() const
	{
		if (m_tax) return (m_price+(m_price*tax_rate));
		else return m_price;
	}

	void NonPerishable::message(const char* msg)
	{
		m_error.message(msg);
	}

	bool NonPerishable::isClear() const
	{
	
		return m_error.isClear();

	}


	//Public Functions

	NonPerishable::NonPerishable(const char typ)
	{
		this->m_type = typ;
		setEmpty();
	}

	NonPerishable::NonPerishable(const char* sku, const char* name, const char* unit, int prodin, bool tax, double price, int prodneed)
	{
		this->m_type = char(0);
		int skulen = strlen(sku);
		int unitlen = strlen(unit);
		
		if (skulen <= max_sku_length)
		{
			strncpy(this->m_sku, sku, strlen(sku));
			this->m_sku[strlen(sku)] = char(0);
		}

		else 
		{
			strncpy(this->m_sku, sku, max_sku_length);
			this->m_sku[max_sku_length] = char(0);
		}
					
		this->m_pname = nullptr;
		this->m_pname = new char[strlen(name) + 1];
		strcpy(this->m_pname, name);
		

		if (unitlen <= max_unit_length)
		{
			strncpy(this->m_unit, unit, strlen(unit));
			this->m_unit[strlen(unit)] = char(0);
		}

		else
		{
			strncpy(this->m_unit, unit, max_unit_length);
			this->m_unit[max_unit_length] = char(0);
		}

		this->m_qtyin = prodin;
		this->m_qtyneed = prodneed;
		this->m_price = price;
		this->m_tax = tax;
		
	}
	NonPerishable::~NonPerishable()
	{

		delete[] m_pname;

	}

	NonPerishable::NonPerishable(const NonPerishable& other)
	{
		this->m_type = char(0);
		this->setEmpty();
		*this = other;
	}

	NonPerishable& NonPerishable::operator=(const NonPerishable& other)
	{

		if (this != &other)
		{

			if (other.m_pname != nullptr)
			{

				delete[] this->m_pname;
				this->m_pname = new char[strlen(other.m_pname) + 1];

				strcpy(this->m_pname, other.m_pname);

				strcpy(this->m_sku, other.m_sku);
				strcpy(this->m_unit, other.m_unit);
				
				this->m_type = other.m_type;
				this->m_qtyin = other.m_qtyin;
				this->m_qtyneed = other.m_qtyneed;
				this->m_price = other.m_price;
				this->m_tax = other.m_tax;

			}

			else
			{
				this->m_type = char(0);
				setEmpty();
			}
		}

		return *this;

	}

	void NonPerishable::setEmpty()
	{

		this->m_sku[0] = char(0);
		this->m_pname = nullptr;
		this->m_unit[0] = char(0);
		this->m_qtyin = 0;
		this->m_qtyneed = 0;
		this->m_price = 0;
		this->m_tax = 0;

	}

	std::fstream& NonPerishable::store(std::fstream& file, bool newLine) const
	{

			if (!file.is_open()) 
			{
				std::cerr << "File is not open" << std::endl;
			}
			else 
			{
				file << this->m_type << ',' <<
					this->m_sku << ',' <<
					this->m_pname << ',' <<
					this->m_unit << ',' <<
					this->m_qtyin << ',' <<
					this->m_qtyneed << ',' <<
					this->m_price << ',' <<
					this->m_tax << ',';

				if (newLine == true) file << std::endl;

				file.clear();
				file.close();
						
			}	

			return file;
					
	}

	std::fstream& NonPerishable::load(std::fstream& file)
	{
		NonPerishable tmp;

		if (!file.is_open())
		{
			std::cerr << "File is not open" << std::endl;
		}
		else
		{
		//	file.seekg(0);

				file >> tmp.m_type;
				file >> tmp.m_sku;
				file >> tmp.m_pname;
				file >> tmp.m_unit;
				file >> tmp.m_qtyin;
				file >> tmp.m_qtyneed;
				file >> tmp.m_price;
				file >> tmp.m_tax;

				file.clear();
				file.close();

		}

		return file;

	}

	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const
	{
			if (linear)
			{
				os << m_sku << '|' << m_pname << '|' << m_price << '|' << m_qtyin << '|' << m_unit << '|' << m_qtyneed;
			}

			else
			{
				os << "Sku: " << m_sku << std::endl;
				os << "Name: " << m_pname << std::endl;
				os << "Price: " << m_price << std::endl;
				if (m_tax) os << "Price after tax: " << (m_price*tax_rate) << std::endl;
				else os << "N/A" << std::endl;
				os << "Quantity On Hand: " << m_qtyin << std::endl;
				os << "Quantity Needed: " << m_qtyneed << std::endl;
			}



		return os;

	}

	std::istream& NonPerishable::read(std::istream& is)
	{
		NonPerishable tmp;

		char tmp_tax;


		std::cout << "Sku: ";
		is >> tmp.m_sku;
		// name
		std::cout << "Name: ";
		is >> tmp.m_pname;
		// unit
		std::cout << "Unit: ";
		is >> tmp.m_unit;
		// taxed
		std::cout << "Taxed? (y/n): ";
		is >> tmp_tax;

		if (tmp_tax != 'Y' && tmp_tax != 'y' && tmp_tax != 'N' && tmp_tax != 'n')
		{
			// set the error message
			m_error.message("Only (Y)es or (N)o are acceptable");
			// force the istr to fail
			is.setstate(std::ios::failbit);
		}
		else 
		{

			if (tmp_tax == 'Y' || tmp_tax == 'y') tmp.m_tax = 1;
			else tmp.m_tax = 0;

			// flush
			is.clear();

			// price
			std::cout << "Price: ";
			is >> tmp.m_price;

			if (is.fail()) 
			{
				// set the error message
				m_error.message("Invalid Price Entry");
				// force the istr to fail
				is.setstate(std::ios::failbit);
			}
			else 
			{
				// flush
				is.clear();

				// quantity on hand
				std::cout << "Quantity On hand: ";
				is >> tmp.m_qtyin;

				if (is.fail()) 
				{
					// set the error message
					m_error.message("Invalid Quantity Entry");
					// force the istr to fail
					is.setstate(std::ios::failbit);
				}
				else 
				{
					is.clear();

					// quantity needed
					std::cout << "Quantity Needed: ";
					is >> tmp.m_qtyneed;

					if (is.fail()) 
					{
						// set the error message
						m_error.message("Invalid Quantity Needed Entry");
						// force the istr to fail
						is.setstate(std::ios::failbit);
					}
					else 
					{
						*this = tmp; 
					}
				}
			}
		}

		return is;
	
	}

	bool NonPerishable::operator == (const char* sku) const
	{
		if (strcmp(this->m_sku, sku)) return 0;
		else return 1;

	}

	double NonPerishable::total_cost() const
	{

		if (m_tax) return ((m_price+(m_price*tax_rate))*m_qtyin);
		else return (m_price*m_qtyin);

	}

	void NonPerishable::quantity(int qty)
	{
		if (qty >= 0) this->m_qtyin = qty;
		else this->m_qtyin = 0;

	}

	bool NonPerishable::isEmpty() const
	{

		return m_sku[0] == char(0) ? 1 : 0;

	}

	int NonPerishable::qtyNeeded() const
	{
		return this->m_qtyneed;
	}


	int NonPerishable::quantity() const
	{
		return this->m_qtyin;
	}

	int NonPerishable::operator += (int prod)
	{
		if (prod > 0)
		{
			this->m_qtyin += prod;
			return (this->m_qtyin);
		}

		else return m_qtyin;

	}

	bool NonPerishable::operator>(const char* sku) const
	{
		if (strcmp(sku, this->m_sku) > 0) return 1;
		else return 0;
	}

	bool NonPerishable::operator >(const Product& other) const
	{
		if (strcmp(this->m_pname, other.name()) > 0) return 1;
		else return 0;

	}

	//Helper Functions

	std::ostream& operator <<(std::ostream& ostr, const Product& prod)
	{
		return prod.write(ostr, false);
	}

	std::istream& operator >>(std::istream& istr, Product& prod)
	{
		return prod.read(istr); 
	}

	double operator += (double& price, const Product& other) 
	{
		price += other.total_cost();
		return price;
	}

	Product* CreateProduct()
	{
		return new NonPerishable('z');
	}

}