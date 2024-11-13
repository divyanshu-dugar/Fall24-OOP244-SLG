# Workshop #7: Derived Classes & Custom I/O Operators

In this workshop, you will work with classes that form a hierarchical structure. The base class is a `BankAccount` that holds common attributes of a bank account.  The child class is a `SavingsAccount` that is derived from the `BankAccount` class.  In each class, you will define private, protected, and public members as well as custom input/output operators.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- inherit a derived class from a base class
- shadow a base class member function with a derived class member function
- access a shadowed member function that is defined in a base class
- utilize custom input/output operators with these classes
- describe to your instructor what you have learned in completing this workshop


## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates

The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit your work up to 2 days after the due date with a 30% penalty for each day. After that, the submission will be closed and the mark will be zero.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.


> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace.


# Part 1 - LAB (100%)

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

[main.cpp](lab/main.cpp)

## Sample Output

[correct_output.txt](lab/correct_output.txt)


## PART 1 Submission (lab)

Follow the instructions of the tester program for data entry.

### Files to submit:  

```Text
DepositUtility.cpp
DepositUtility.h
BankAccount.h
BankAccount.cpp
SavingsAccount.h
SavingsAccount.cpp
main.cpp
```

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
