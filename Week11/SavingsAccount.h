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

#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "BankAccount.h"
namespace seneca {
	class SavingsAccount : public BankAccount {
		double m_interest{};
		Date m_interestDate;
		void writeInterest(std::ostream& out) const;
	public:
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		void applyInterest(Date& dt);
		std::ostream& write(std::ostream& out)const;
		std::istream& read(std::istream& in);
		virtual ~SavingsAccount() = default;
	};
	std::istream& operator>>(std::istream& in, SavingsAccount& acct);
	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
}
#endif
