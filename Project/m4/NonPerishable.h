// Final Project Milestone 4
// Version 2.0.1
// Date	2017-12-14
// Author Jose Florencio Coelho Neto
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_NONPERISHABLE_H
#define SICT_NONPERISHABLE_H

#include <fstream>
#include "Product.h"
#include "ErrorMessage.h"

namespace sict
{

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class NonPerishable : public Product
	{

		char m_type;
		char m_sku[max_sku_length + 1];
		char* m_pname;
		char m_unit[max_unit_length + 1];
		int m_qtyin;
		int m_qtyneed;
		double m_price;
		bool m_tax;

		ErrorMessage m_error;

	protected:

		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:

		NonPerishable(const char typ=char(0));
		NonPerishable(const char* sku, const char* prod, const char* unit, int prodin=0, bool tax=1, double price=0, int prodneed=0);
		~NonPerishable();
		NonPerishable(const NonPerishable& other);
		NonPerishable& operator=(const NonPerishable& other);

		virtual std::fstream& store(std::fstream& file, bool newLine = true) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear) const;
		virtual std::istream& read(std::istream& is);
		virtual bool operator == (const char*) const;
		virtual double total_cost() const;
		virtual void quantity(int);
		virtual int qtyNeeded() const;
		virtual int quantity() const;
		virtual int operator += (int);
		virtual bool operator >(const Product&) const;

		bool isEmpty() const;
		bool operator>(const char*) const;

		void setEmpty();
		
	
		

	};

	//Helper Functions

	std::ostream& operator <<(std::ostream&, const Product&);
	std::istream& operator >>(std::istream&, Product&);
	double operator += (double&, const Product&);
	Product* CreateProduct();



}


#endif