#include <iostream>
#include <cstring>

#include "DepositUtility.h"
#include "BankAccount.h"
#include "SavingsAccount.h"

using namespace std;
using namespace seneca;
void printHeader(ostream& out, const char* title,const char* values = nullptr);

int main()
{
   cout << "SENECA Banking System" << endl << endl;

   // Test the base "BankAccount" class.
   printHeader(cout, "[#1] Bank Account (Constructors)");

   Date bankDate(19, 5, 2023);
   DepositInfo bankDep("04853", "001", "0037857");
   BankAccount bankAcct("Jane Doe", bankDate, bankDep, 0.0f);

   cout << bankAcct << endl << endl;

   printHeader(cout, "[#2] Bank Account (I/O)","John Evans\n100.25\n2022 12 6\n01234\n002\n0012345");
   cin >> bankAcct;
   cout << bankAcct << endl << endl;


   // Test the base "SavingsAccount" class.
   printHeader(cout, "[#3] Savings Account (Constructors)");

   Date savDate(19, 5, 2023);
   Date interestDate = savDate;
   DepositInfo savDep("04853", "001", "0037857");
   SavingsAccount savAcct("Frank Wilson", savDate, savDep, 99.5f, 0.055f, interestDate);

   cout << savAcct << endl;

   interestDate = Date(interestDate.getDay(), interestDate.getMonth() + 1, interestDate.getYear());
   savAcct.applyInterest(interestDate);

   interestDate = Date(interestDate.getDay(), interestDate.getMonth() + 1, interestDate.getYear());
   savAcct.applyInterest(interestDate);

   cout << savAcct << endl << endl;

   printHeader(cout, "[#4] Savings Account (I/O)", "Alivia Wright\n555.55\n2023 2 10\n54321\n003\n1122334\n2023 3 1\n0.047");
   cin >> savAcct;
   cout << savAcct << endl;

   interestDate = Date(10, 2, 2015);
   savAcct.applyInterest(interestDate);

   interestDate = Date(interestDate.getDay(), interestDate.getMonth() + 1, interestDate.getYear());
   savAcct.applyInterest(interestDate);

   cout << savAcct << endl << endl;

   cout << "-- END --" << endl;
}

void printHeader(ostream& out, const char* title, const char* values)
{
   if (values)
   {
      out << "Enter the following values when prompted: "
         << endl
         << values
         << endl
         << "---------------------------" << endl;
   }
   char oldFill = out.fill('-');

   out << title << endl;
   out.width(strlen(title));
   out << "" << endl;

   out.fill(oldFill);
}
