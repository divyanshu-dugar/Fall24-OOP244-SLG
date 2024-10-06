## Coding Question Answer

```cpp
#include <iostream>
using namespace std;

class Bottle {
public:
   // Part 2: Print function that displays the size and name of the bottle
   ostream& print(ostream& ostr = cout) {   
      ostr << m_size;
      ostr.width(20);
      ostr.fill('.');
      ostr.setf(ios::right);
      ostr << m_name;
      ostr.fill(' ');
      ostr.unsetf(ios::right);
      return ostr;
   }            

   // Part 1: Read function to read comma-separated input of name and size
   istream& read(istream& istr = cin) {
      istr.getline(m_name, 21, ',');
      istr >> m_size;
      istr.ignore(10000, '\n');
      return istr;
   }

   // Part 3: Default constructor - Bottle is initialized as empty by default
   Bottle() = default; 

private:
   char m_name[21]{};
   int m_size{};  // Changed from char to int for correct storage of bottle size
};

class Winerack {
   Bottle* m_bottles{};  // dynamic array of bottles
   int m_size{};         // maximum number of bottles on the winerack
   int m_num{};          // number of bottles on the winerack
public:
   // Part 4: Constructor with validation for Winerack size between 6 and 300
   Winerack(int size) {      
      if (size >= 6 && size <= 300) {
         m_bottles = new Bottle[size]{};
         m_size = size;
      }
   }

   // Part 5: Destructor to deallocate memory
   ~Winerack() {      
      delete[] m_bottles;
   }

   // Part 6: Set empty state for invalid Winerack
   void setEmpty() {   
      delete[] m_bottles;
      m_size = m_num = 0;
   }

   // Part 7: Boolean casting operator to check validity of Winerack
   operator bool() {  
      return bool(m_bottles);
   }

   // Part 8: Overload += operator to add a bottle to the Winerack
   Winerack& operator+=(Bottle M) {  
      if (m_num == m_size) {
         setEmpty();
      } else {
         m_bottles[m_num++] = M;
      }
      return *this;
   }

   // Part 9: Display function for printing all bottles if Winerack is valid
   ostream& display(ostream& ostr = cout) {    
      for (int i = 0; *this && i < m_num; i++) {
         m_bottles[i].print() << endl;
      }
      return ostr;
   }

   // Part 10: Read function to fill empty bottles in the Winerack
   istream& read(istream& istr = cin) {  
      while (m_num < m_size) {
         m_bottles[m_num++].read();
      }
      return istr;
   }
};
```

## Coding Header File Answer

```cpp
#ifndef TECH_LAPTOP_H
#define TECH_LAPTOP_H

namespace tech {

class Laptop {
   char serialNumber[21]{};
   int ramSize = 8;
   char* brandModel = nullptr;

public:
   // Constructors
   Laptop();
   Laptop(const char* brandModel, const char* serialNumber, int ramSize = 8);

   // Destructor
   ~Laptop();

   // Assignment Operators
   Laptop& operator=(int value);            // To set RAM size
   Laptop& operator=(const char* brandModel); // To set brand and model

   // Boolean Cast Operator
   operator bool() const;

   // Addition Operator
   Laptop operator+(const Laptop& right) const;

   // Input/Output Functions
   std::istream& read(std::istream& istr);
   std::ostream& print(std::ostream& ostr = std::cout) const;
};

// Helper function to compare two laptops' RAM size
bool compare(const Laptop& left, const Laptop& right);

}

#endif // TECH_LAPTOP_H
```

---
