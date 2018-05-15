// Final Project Milestone 2
// Version 1.0
// Date	12/03/2017
// Author Jose Florencio Coelho Neto	
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "ErrorMessage.h"


namespace sict
{

	ErrorMessage::ErrorMessage(const char* ErrorMessage)
	{
		this->m_perrmsg = nullptr;

		if (ErrorMessage != nullptr)
		{
			message(ErrorMessage);
		}

	}
/*
	ErrorMessage::ErrorMessage(const ErrorMessage& em)
	{
		if (&em != nullptr)
		{
			this->m_perrmsg = nullptr;
			message(em.m_perrmsg);
			
		}

		else this->m_perrmsg = nullptr;	

	}

	ErrorMessage& ErrorMessage::operator=(const ErrorMessage& em)
	{

		if (this != &em)
		{
			if (em.m_perrmsg != nullptr && this->m_perrmsg != nullptr)
			{
				message(em.m_perrmsg);
				return *this;

			}

			else
			{
				this->m_perrmsg = nullptr;
				return *this;
			}

		}

		else return *this;


	}
*/
	ErrorMessage::~ErrorMessage()
	{

		delete[] this->m_perrmsg;

	}

	void ErrorMessage::clear()
	{

			delete[] this->m_perrmsg;
			this->m_perrmsg = nullptr;
		

	}

	bool ErrorMessage::isClear() const
	{
		if (this->m_perrmsg == nullptr) return 1;
		else return 0;
	}

	void ErrorMessage::message(const char* str)
	{
		int len = strlen(str);

		if (len != 0)
		{

			if (this->m_perrmsg != nullptr)
			{
				clear();
				this->m_perrmsg = new char[len+1];

				strcpy(this->m_perrmsg, str);
								
			}

			else
			{
				this->m_perrmsg = new char[len+1];
				strcpy(this->m_perrmsg, str);
			}
		}
		

	}
	const char* ErrorMessage::message() const
	{
		if (this->m_perrmsg != nullptr)	return this->m_perrmsg;

		else return "\0";
		
	}

	std::ostream& operator<<(std::ostream& ost, const ErrorMessage& msg)
	{
		ost << msg.message();

		return ost;
	}

}
	
