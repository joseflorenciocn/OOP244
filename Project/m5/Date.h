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
#ifndef SICT_DATE_H
#define SICT_DATE_H

namespace sict {

	const int min_year = 2000;
	const int max_year = 2030;
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int DAY_ERROR = 4;

  class Date {

	  int m_year;
	  int m_month;
	  int m_day;
	  int m_comparator;
	  int m_error;

     int mdays(int, int)const;
	 
	 void errCode(int errorCode);
	 void comparator();
 
  public:
 
	  Date();
	  Date(int year, int month, int day);
	  void setEmpty();
	  bool isEmpty(const Date& date);
	  bool emptyState() const;


	  bool operator == (const Date& rhs);
	  bool operator != (const Date& rhs);
	  bool operator < (const Date& rhs);
	  bool operator > (const Date& rhs);
	  bool operator <= (const Date& rhs);
	  bool operator >= (const Date& rhs);

	  int errCode() const;

	  bool bad() const;

	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;

  };

  //Helper Functions

  std::ostream& operator << (std::ostream& ostr, const Date& date);
  std::istream& operator >> (std::istream& istr, Date& date);

  
}
#endif