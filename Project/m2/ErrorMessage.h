// Final Project Milestone 2
// Version 1.0
// Date 12/03/2017	
// Author Jose Florencio Coelho Neto	
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason

#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H

namespace sict {

	class ErrorMessage
	{
	public:
		explicit ErrorMessage(const char* ErrorMessage = nullptr);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual	~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;

	private:

		char* m_perrmsg;

	};

	//Helper Functions

	std::ostream& operator<<(std::ostream& ost, const ErrorMessage& msg);
	
		
}


#endif // !SICT_ERRORMESSAGE_H


