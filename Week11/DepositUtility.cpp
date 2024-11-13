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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>

#include "DepositUtility.h"

namespace seneca {

	Date::Date()
	{
		m_day = 0;
		m_month = 0;
		m_year = 0;
	}

	Date::Date(int day, int month, int year) {
		m_day = day;
		m_month = month;
		m_year = year;
	}

	int Date::getDay() const {
		return m_day;
	}

	int Date::getMonth() const {
		return m_month;
	}

	int Date::getYear() const {
		return m_year;
	}

	void Date::write(std::ostream& out) const {
		char oldFill = out.fill('0');

		out << m_year << "-" << std::setw(2) << m_month << "-" << std::setw(2) << m_day;

		out.fill(oldFill);
	}

	void Date::read(std::istream& in) {
		std::cout << "(year month day): ";

		in >> m_year >> m_month >> m_day;
	}

	std::ostream& operator<<(std::ostream& out, const Date& dt) {
		dt.write(out);
		return out;
	}

	std::istream& operator>>(std::istream& in, Date& dt) {
		dt.read(in);
		return in;
	}


	DepositInfo::DepositInfo()
	{
		m_transit[0] = '\0';
		m_institution[0] = '\0';
		m_account[0] = '\0';
	}

	DepositInfo::DepositInfo(const char* transit, const char* institution, const char* account)
	{
		strncpy(m_transit, transit, TRANSIT_NUM_LEN);
		m_transit[TRANSIT_NUM_LEN] = 0;
		strncpy(m_institution, institution, INSTITUTION_NUM_LEN);
		m_institution[INSTITUTION_NUM_LEN] = 0;
		strncpy(m_account, account, ACCT_NUM_LEN);
		m_account[ACCT_NUM_LEN] = 0;
	}

	const char* DepositInfo::getTransit() const {
		return m_transit;
	}

	const char* DepositInfo::getInstitution() const {
		return m_institution;
	}

	const char* DepositInfo::getAccount() const {
		return m_account;
	}

	void DepositInfo::write(std::ostream& out) const {
		out << m_transit << "," << m_institution << "," << m_account;
	}

	void DepositInfo::read(std::istream& in) {
		std::cout << "Transit #: ";
		in >> m_transit;

		std::cout << "Institution #: ";
		in >> m_institution;

		std::cout << "Account #: ";
		in >> m_account;
	}


	std::ostream& operator<<(std::ostream& out, const DepositInfo& info) {
		info.write(out);
		return out;
	}

	std::istream& operator>>(std::istream& in, DepositInfo& info) {
		info.read(in);
		return in;
	}

}