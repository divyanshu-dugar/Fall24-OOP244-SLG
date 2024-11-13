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
