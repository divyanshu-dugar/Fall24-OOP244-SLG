/*/////////////////////////////////////////////////////////////////////////
						Workshop-7 Part-1
Full Name  : Divyanshu Dugar
Student ID#: 177110210
Email      : ddugar@myseneca.ca
Section    : ZAA
Date       : 21/03/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"

namespace seneca {
	const int MAX_NAME = 50;
	class BankAccount {
		char m_name[MAX_NAME + 1]{};
		Date m_openDate;
		DepositInfo m_depInfo;
		double m_balance{};
	protected:
		double getBalance() const;
		void setBalance(double balance);
		void writeCurrency(std::ostream& out, double amount) const;
	public:
		// Constructors
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
		// Destructor
		virtual ~BankAccount() = default;
		// Query Method
		virtual std::ostream& write(std::ostream& out) const;
		// Mutators
		virtual std::istream& read(std::istream& in);
	};
	std::istream& operator>>(std::istream& in, BankAccount& acct);
	std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
}
#endif