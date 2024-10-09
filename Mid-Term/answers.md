## Coding Question Answer

```cpp
#include <iostream>
using namespace std;

class Jug {
    char m_name[21]{};
    int m_size{}; // size in milliliters
public:
    // Part 1: Read function to read comma-separated input of name and size
    istream& read(istream& istr = cin) {
        istr.getline(m_name, 21, ',');
        istr >> m_size;
        istr.ignore(10000, '\n'); // Ignore until newline to discard any leftover characters
        return istr;
    }

    // Part 2: Write function that displays the size and name of the Jug
    ostream& write(ostream& ostr = cout) const {
        ostr << m_size;
        ostr.width(20);           // Set the width for the right-justified output
        ostr.fill('.');           // Fill empty spaces with dots
        ostr.setf(ios::right);    // Right-justify the output
        ostr << m_name;
        ostr.fill(' ');           // Reset fill to space
        ostr.unsetf(ios::right);  // Unset the right-justified flag
        return ostr;
    }

    // Part 3: Default constructor - Jug is initialized as empty by default
    Jug() = default;
};

class JugRack {
    Jug* m_jugs{};  // dynamic array of jugs
    int m_size{};   // maximum number of jugs on the rack
    int m_num{};    // number of jugs on the rack

public:
    // Part 4: Constructor with validation for JugRack size between 5 and 250
    JugRack(int size) {
        if (size >= 5 && size <= 250) {
            m_jugs = new Jug[size]{};
            m_size = size;
        } else {
            setEmpty(); // Set to an invalid empty state if size is out of bounds
        }
    }

    // Part 5: Destructor to deallocate memory
    ~JugRack() {
        delete[] m_jugs;
    }

    // Part 6: Set empty state for invalid JugRack
    void setEmpty() {
        delete[] m_jugs;
        m_jugs = nullptr;
        m_size = m_num = 0;
    }

    // Part 7: Boolean casting operator to check validity of JugRack
    operator bool() const {
        return m_jugs != nullptr; // Return true if the JugRack is valid (i.e., has allocated memory)
    }

    // Part 8: Overload += operator to add a Jug to the JugRack
    JugRack& operator+=(const Jug& J) {
        if (m_num == m_size) {
            setEmpty(); // Set to invalid state if trying to add more Jugs than the rack can hold
        } else {
            m_jugs[m_num++] = J; // Add the Jug and increment the count
        }
        return *this;
    }

    // Part 9: Display function for printing all Jugs if the JugRack is valid
    ostream& display(ostream& ostr = cout) const {
        if (*this) { // Only display if JugRack is in a valid state
            for (int i = 0; i < m_num; ++i) {
                m_jugs[i].write(ostr) << endl;
            }
        }
        return ostr;
    }

    // Part 10: Read function to fill empty Jugs in the JugRack
    istream& read(istream& istr = cin) {
        while (m_num < m_size) {
            m_jugs[m_num++].read(istr); // Read input for the remaining empty Jugs
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
