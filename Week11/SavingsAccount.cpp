#include <iostream>
#include "SavingsAccount.h"
using namespace std;
namespace seneca {
	void SavingsAccount::writeInterest(ostream& out) const
	{
		out.precision(3);
		out.setf(ios::fixed);
		out << m_interest << "%";
	}
	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name,openDate,depInfo,balance),m_interest(interest), m_interestDate(interestDate)
	{
		
	}
	void SavingsAccount::applyInterest(Date& dt)
	{
		cout << "   ";
		double balance = getBalance();
		double interestAmount = balance * m_interest;
		writeCurrency(cout,balance);
		cout << " + $";
		cout << interestAmount << " (";
		writeInterest(cout);
		cout << ")" << " = ";
		balance += interestAmount;
		setBalance(balance);
		writeCurrency(cout, balance);
		cout << " | ";
		m_interestDate.write(cout);
		cout << " => ";
		m_interestDate = dt;
		m_interestDate.write(cout);
		cout << endl;
	}

	std::ostream& SavingsAccount::write(std::ostream& out) const
	{
		BankAccount::write(out);
		out << " | ";
		writeInterest(out);
		out << " | ";
		m_interestDate.write(out);
		return out;
	}

	std::istream& SavingsAccount::read(std::istream& in)
	{
		in.ignore(10, '\n');
		BankAccount::read(in);
		cout << "Interest Date ";
		m_interestDate.read(in);
		cout << "Interest Rate: ";
		in >> m_interest;
		return in;
	}

	std::istream& operator>>(std::istream& in, SavingsAccount& acct)
	{
		return acct.read(in);
	}

	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct)
	{
		return acct.write(out);
	}
}
