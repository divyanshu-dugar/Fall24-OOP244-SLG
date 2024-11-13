#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BankAccount.h"
using namespace std;
namespace seneca {
	// Protected Members Definiton
	double BankAccount::getBalance() const
	{
		return m_balance;
	}
	void BankAccount::setBalance(double balance)
	{
		if (balance) {
			m_balance = balance;
		}
	}
	void BankAccount::writeCurrency(std::ostream& out, double amount) const
	{
		out.precision(2);
		out.setf(ios::fixed);
		out << "$" << amount;
	}
	// Public Members Definition
	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
	{
		strcpy(m_name, name);
		m_openDate = openDate;
		m_depInfo = depInfo;
		m_balance = balance;
	}

	std::ostream& BankAccount::write(std::ostream& out) const
	{
		
		out << ">> " << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | " << m_openDate.getYear() << "-";
		out.width(2);
		out.fill('0');
		out << m_openDate.getMonth() << "-";
		out.width(2);
		out.fill('0');
		out << m_openDate.getDay() << " | " << m_depInfo.getTransit() << "," << m_depInfo.getInstitution() << "," << m_depInfo.getAccount();
		return out;
	}
	std::istream& BankAccount::read(std::istream& in)
	{
		cout << "Name: ";
		in.getline(m_name, MAX_NAME);
		cout << "Opening Balance: ";
		in >> m_balance;
		in.ignore(10, '\n');
		cout << "Date Opened ";
		m_openDate.read(in);
		m_depInfo.read(in);
		return in;
	}
	istream& operator>>(istream& in, BankAccount& acct)
	{
		return acct.read(in);
	}
	ostream& operator<<(ostream& out, const BankAccount& acct)
	{
		return acct.write(out);
	}
}
