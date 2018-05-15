// Final Project Milestone 1
//
// Version 1.0
// Date: 26/11/2017
// Author: Jose Florencio Coelho Neto
// Description
// Milestone 1 - Date Class 
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"

namespace sict {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const 
  {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
  }

  void Date::comparator() 
  {
	  this->m_comparator = this->m_year * 372 + this->m_month * 31 + this->m_day;
  }

  void Date::errCode(int errorCode)
  {
	  this->m_error = errorCode;
  }

  void Date::setEmpty()
  {
	  this->m_comparator = 0;
	  this->m_year = 0;
	  this->m_month = 0;
	  this->m_day = 0;
	  errCode(NO_ERROR);
  }

  Date::Date()
  {

	  setEmpty();

  }
  Date::Date(int year, int month, int day)
  {

	  if (month > 0 && month < 13 && year <= max_year && year >= min_year && day > 0 && day <= mdays(month, year))
	  {
		  this->m_month = month;
		  this->m_year = year;
		  this->m_day = day;
		  errCode(NO_ERROR);
		  comparator();
	  }

	  else setEmpty();

  }
  
  bool Date::isEmpty(const Date& date)
  {
	  if (this->m_comparator == 0 || date.m_comparator == 0) return 1;
	  else return 0;

  }
 

  bool Date::operator == (const Date& rhs)
  {
	  if (isEmpty(rhs)) return 0;
	  else  if (this->m_comparator == rhs.m_comparator) return 1;
			else return 0;
  }
  bool Date::operator != (const Date& rhs)
  {
	  if (isEmpty(rhs)) return 0;
	  else  if (this->m_comparator != rhs.m_comparator) return 1;
	  else return 0;
  }
  bool Date::operator < (const Date& rhs)
  {
	  if (isEmpty(rhs)) return 0;
	  else  if (this->m_comparator < rhs.m_comparator) return 1;
	  else return 0;
  }
  bool Date::operator > (const Date& rhs)
  {
	  if (isEmpty(rhs)) return 0;
	  else  if (this->m_comparator > rhs.m_comparator) return 1;
	  else return 0;
  }
  bool Date::operator <= (const Date& rhs)
  {
	  if (isEmpty(rhs)) return 0;
	  else  if (this->m_comparator <= rhs.m_comparator) return 1;
	  else return 0;
  }
  bool Date::operator >= (const Date& rhs)
  {
	  if (isEmpty(rhs)) return 0;
	  else  if (this->m_comparator >= rhs.m_comparator) return 1;
	  else return 0;
  }

  int Date::errCode() const
  {
	  return m_error;
  }

  bool Date::bad() const
  {
	  if (m_error == 0) return 0;
	  else return 1;
  }

  bool Date::emptyState() const
  {
	 return (this->m_year == 0 && this->m_day == 0 && this->m_month == 0) ? 1 : 0;
	 
  }

  std::istream& Date::read(std::istream& istr)
  {
	  int year, month, day;
	  char separator;

	  istr >> year >> separator >> month >> separator >> day;

	  if (istr.fail())
	  {
		  setEmpty();
		  errCode(CIN_FAILED);
		  
	  }

	  else 
	  {
		  m_year = year;
		  m_month = month;
		  m_day = day;

		  if (year < min_year || year > max_year)
		  {
			  setEmpty();
			  errCode(YEAR_ERROR);
		  }
		  else
		  {
			  if (month < 1 || month > 12)
			  {
				  setEmpty();
				  errCode(MON_ERROR);
			  }
			  else
			  {
				  if (day < 1 || day > mdays(month, year))
				  {
					  setEmpty();
					  errCode(DAY_ERROR);
				  }

				  else errCode(NO_ERROR);
			  }
		  }
	  }

	  return istr;
  }
  std::ostream& Date::write(std::ostream& ostr) const
  {
	  ostr << m_year << '/';
	  ostr.width(2);
	  ostr.fill('0');
	  ostr << m_month << '/';
	  ostr.width(2);
	  ostr.fill('0');
	  ostr << m_day;

	  return ostr;
  }

  std::ostream& operator << (std::ostream& ostr, const Date& date)
  {
	  date.write(ostr);
	  return ostr;
  }
  std::istream& operator >> (std::istream& istr, Date& date)
  {
	  date.read(istr);
	  return istr;
  }



}
