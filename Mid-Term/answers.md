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

Each part corresponds to the number in your question:
1. The `read` function reads comma-separated values.
2. The `print` function displays size and name.
3. The default constructor initializes an empty bottle.
4. The `Winerack` constructor validates the rack size.
5. The destructor deallocates memory.
6. The `setEmpty` function invalidates the Winerack.
7. The boolean casting operator checks if the Winerack is valid.
8. The `+=` operator adds a bottle to the Winerack or sets it to an empty state if full.
9. The `display` function prints all bottles if the Winerack is valid.
10. The `read` function fills up the empty spots in the Winerack.

---

## Creating Header file Question

### Question:

Write the complete header file for a class called **Laptop** with the following requirements. Ensure the attributes and method prototypes are correctly written; no function definitions are needed. Follow the provided details to structure the class.

#### **Namespace**: `tech`

#### **Encapsulated Attributes**:

1. **Serial Number**: A c-string that stores the laptop’s serial number. By default, it should be set to an empty string.
2. **RAM Size**: An integer representing the RAM size in GB. By default, it should be set to 8.
3. **Brand and Model**: A dynamically allocated c-string to store the laptop's brand and model. By default, it should be set to `nullptr`.

#### **Construction and Destruction**:

- The class should have the following constructors:
  - **Constructor with Parameters**: A constructor that takes `Brand and Model`, `Serial Number`, and `RAM Size`. If the RAM size is not provided, it should default to 8.
  - **Default Constructor**: A constructor that initializes the laptop to an invalid, empty state when no information is provided.
  
- **Destructor**: The class should ensure that dynamically allocated memory for the brand and model is properly deallocated when the object goes out of scope.

#### **Operators**:

1. **Assignment Operator**: 
   - To assign an integer value to the Laptop, which sets its RAM size.
   - To assign a C-string value to the Laptop, which sets its brand and model.

2. **Casting to Boolean**: 
   - When cast to a boolean, it should return whether the laptop is in a valid state.

3. **Overload the `+` Operator**: 
   - The sum of two laptops should return the combined RAM size of both laptops.

#### **Input/Output**:

1. The class should provide the ability to:
   - **Read** laptop information from an input stream (`istream`).
   - **Display** laptop information to an output stream (`ostream`).

#### **Helper Function**:

- Provide a helper function named **`compare`** that compares two laptops' RAM sizes and returns a boolean value based on whether the first laptop has a greater or equal RAM size compared to the second. This function should be declared outside the class.

---
