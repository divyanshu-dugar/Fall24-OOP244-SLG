# Derived Classes & Custom I/O Operators

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `seneca` namespace.

## `DepositUtility` Module

A `DepositUtility` module has already been created for you. It contains a `Date` class and `DepositInfo` class that you can use when implementing the `BankAccount` and `SavingsAccount` classes. Study this class and understand how it works.

## `BankAccount` Class

Design and code a class named `BankAccount` that holds information about a bank account. Place your class definition in a header file named `BankAccount.h` and your function definitions in an implementation file named `BankAccount.cpp`.

### `BankAccount` - Private Members

The class will contain the following private members.

- `m_name`: The name of the person that owns the account (holds up to 50 chars).
- `m_openDate`: An instance of the `Date` class to hold the date the account was opened.
- `m_depInfo`: An instance of the `DepositInfo` class to hold the direct deposit information.
- `m_balance`: A doubleing point number to hold the current balance of the account.

### `BankAccount` - Protected Members

The class will contain the following protected members.

- `double getBalance() const`: A query method to return the current balance of the account (m_balance).
- `void setBalance(double balance)`: A mutator that sets the current balance of the account (m_balance).
- `void writeCurrency(ostream& out, double amount) const`: A utility method that inserts into `out` a formatted dollar amount. The amount is written with a leading '$' sign and a precision of 2.  For example, if `amount` is 1.2, `$1.20` is written to `out`. 

### `BankAccount` - Public Members

The class will contain the following public members.

- `BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)`: A constructor that updates all of the data members of the object. _Assume all data is valid._
- `ostream& write(ostream& out)`: A query that inserts into `out` the content of the object _as formatted below_. The method will use `writeCurrency()` to output the account balance.
  ```txt
  >> [Name] | [Balance] | [Date Opened] | [Deposit Info]
  ```
- `istream& read(istream& in)`: A mutator that reads from the stream `in` the data for the current object.
  ```txt
  Name: [USER TYPES HERE]
  Opening Balance: [USER TYPES HERE]
  Date Opened (year month day): [USER TYPES HERE]
  Transit #: [USER TYPES HERE]
  Institution #: [USER TYPES HERE]
  Account #: [USER TYPES HERE]
  ```
  
### `BankAccount` - Helper Functions

- `istream& operator>>(istream& in, BankAccount& acct)`: Overload the extraction operator to extract a `BankAccount` from a stream. The extraction operator will call the `read` member function in the class `BankAccount`.
- `ostream& operator<<(ostream& out, const BankAccount& acct)`: Overload the insertion operator to insert a `BankAccount` into a stream. The insertion operator will call the `write` member function in the class `BankAccount`.

## `SavingsAccount` Class

Design and code a class named `SavingsAccount` that holds information about a savings account.  Place your class definition in a header file named `SavingsAccount.h` and your function definitions in an implementation file named `SavingsAccount.cpp`.

**This class must be inherited from the `BankAccount` class.**

### `SavingsAccount` - Private Members and method

The class will contain the following private members.

- `m_interest`: A double number to hold the current interest rate of the account _(specified as a fraction, for example, 0.05 means 5%)_.
- `m_interestDate`: An instance of the `Date` class to hold the date interest was last applied to the account.
- `void writeInterest(ostream& out) const`: A query that inserts into `out` interest rate (m_interest) formatted so that the precision is 3 and a '%' sign follows.  For example, if `m_interest` is 0.12, `0.120%` is written to `out`.

### `SavingsAccount` - Public Members

The class will contain the following public members.

- `SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate)`: A constructor that updates all data members of the object. It must call the constructor of the base class and pass the required data. _Assume all data is valid_.
- `void applyInterest(Date& dt)`: A mutator that increases the account balance by the amount of interest; updates the date interest was last applied; and outputs a message to `cout`. The method will use `writeCurrency()` to output the account balances and `writeInterest()` to output the interest rate. _There are three spaces at the front._
```txt
   [Original Balance] + [Interest Amount] ([Interest Rate]) = [New Balance] | [Original Interest Date] => [New Interest Date]
  ```
- `ostream& write(ostream& out)`: A query that inserts into `out` the content of the object _as formatted below_. The method must call the `write()` function of the base class.  It will call `writeInterest()` to output the interest rate and the insertion operator to output the interest date.
  ```txt
  >> [Name] | [Balance] | [Date Opened] | [Deposit Info] | [Interest Rate] | [Interest Date]
  ```
- `istream& read(istream& in)`: A mutator that reads from the stream `in` the data for the current object. It must call the `read()` function of the base class.
  ```txt
  Name: [USER TYPES HERE]
  Opening Balance: [USER TYPES HERE]
  Date Opened (year month day): [USER TYPES HERE]
  Transit #: [USER TYPES HERE]
  Institution #: [USER TYPES HERE]
  Account #: [USER TYPES HERE]
  Interest Date (year month day): [USER TYPES HERE]
  Interest Rate: [USER TYPES HERE]
  ```
### `SavingsAccount` - Helper Functions

- `istream& operator>>(std::istream& in, SavingsAccount& acct)`: Overload the extraction operator to extract a `SavingsAccount` from a stream. The extraction operator will call the `read` member function in the class `SavingsAccount`.
-`ostream& operator<<(std::ostream& out, const SavingsAccount& acct)`: Overload the insertion operator to insert a `SavingsAccount` into a stream. The insertion operator will call the `write` member function in the class `SavingsAccount`.

## `main` Module (supplied)

**Do not modify this module!**  Review the code and make sure you understand it.

[main.cpp](Week10/main.cpp)

## Sample Output

[correct_output.txt](Week10/correct_output.txt)
