## Dynamic Memory Allocation and the Rule of Three - `Tag` Class Implementation

### 📝 Objective
The task is to implement a class named **`Tag`**, ensuring it adheres to the **Rule of Three** while managing dynamic memory allocation. The class should also anticipate inheritance and provide a method for formatted display. Follow the points below for the implementation details.

---

### 🔧 Implementation Details

1. **Dynamic Memory Allocation**  
   - Implement a helper method named `cloneStr` for dynamic memory allocation within the class.  
   - Use this method for managing the **`m_tagData`** member to allocate and clone string data dynamically.

2. **Inheritance Ready**  
   - Code the solution to anticipate inheritance, as **`Tag`** will serve as a base class for future subclasses.

3. **Construct the Display Method**  
   - Create a method named **`present`** that takes an `ostream` reference as an argument.  
   - The **`present`** method should:
     - Insert the **`m_tagData`** into the output stream if **`m_tagData`** is not empty.
     - Be designed for potential overriding in subclasses.

4. **Insertion Operator Overloading**  
   - Overload the **`<<` operator** for **`Tag`** objects to replicate the functionality of the **`present`** method.

5. **Unified File Implementation**  
   - Assume all components of the class and testing code are implemented in a **single file**.

6. **Main Function Testing**  
   - Test your implementation using the provided main function (below).  
   - Ensure the output matches the **expected results** for both the console and file.

---

### 📂 Provided Code and Expected Output

```cpp
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class Tag {
    char* m_tagData;
protected:
    char* cloneStr(const char* tag) {
        char* newTagData{};
        if (tag) {
            newTagData = new char[strlen(tag) + 1];
            strcpy(newTagData, tag);
        }
        return newTagData;
    }
public:
    Tag(const char* tag) : m_tagData(cloneStr(tag)) {}
    // ... Additional code goes here ...
};

// ... Additional code goes here ...

int main() {
    ofstream file("tag.txt");
    Tag t1 = "Alice";
    Tag t2 = t1, t3 = "to be replaced";
    Tag t4;
    t3 = t1;
    cout << ">" << t1 << ":" << t4 << "<" << endl;
    file << t1 << endl;
    return 0;
}
```

---

### ✅ Expected Output

#### **Console Output**
```
>Alice:<
```

#### **File Output (`tag.txt`)**
```
Alice
```

---

### 💡 Key Notes
- Ensure proper **dynamic memory management** to avoid memory leaks.  
- Follow the **Rule of Three**, implementing the destructor, copy constructor, and copy assignment operator.  
- Design the **`present`** method to be easily overridden in subclasses.

---

# Question 2

Here’s the formatted question for your README file that you can use as a sample paper for GitHub:

---

## Template Function Implementation: `calcSum`

**Objective:**  
Implement a template function named `calcSum` in a C++ module (`calc.h`) to calculate the sum of elements in an array based on a specified condition. The function should be versatile and applicable to arrays of different types.

---

### **Problem Description**

1. **Dynamic Template Function:**
   - Create a template function `calcSum` that accepts three template parameters:
     - `classType`: Represents the type of elements in the array.
     - `dataType`: Represents the type of the sum to be calculated.
     - `idType`: Represents the type of an identifier used for comparison.

2. **Parameters of the Function:**
   - The function must accept the following arguments:
     - A pointer to an array of `classType`.
     - A reference to a `dataType` variable for storing the calculated sum.
     - An `idType` value to compare with the elements in the array.
     - The size of the array (`size_t`).

3. **Function Requirements:**
   - The function should iterate through the array and compare each element with the provided identifier (`id`).
   - If an element matches the identifier:
     - Add its value to a running total of type `dataType`.
     - Use type conversion (`static_cast`) to ensure type safety.
   - Update the `sum` parameter with the total sum calculated.
   - The function should not return any value.

4. **Assumptions:**
   - Array elements and the identifier can be compared using the `==` operator.
   - Array elements can be converted to the `dataType` for summation.

5. **Additional Requirements:**
   - Write the function in a module named `calc.h`.
   - Ensure that the module is standalone and ready to compile.
   - Test the function using the provided `main` function.

---

### **Provided Test Case**

You are provided with the following `main.cpp` file to test your implementation:

```cpp
#include <iostream>
#include "calc.h"
using namespace std;

// Sample class with required operators
class Container {
    int m_sku;
    double m_capacity;

public:
    Container(int sku, double capacity) : m_sku(sku), m_capacity(capacity) {};

    // Conversion operator to return the capacity as a double
    operator double() const { return m_capacity; }

    // Overloaded equality operator to compare the SKU
    bool operator==(int sku) const { return m_sku == sku; }
};

int main() {
    // Sample array of Container objects
    Container C[5] = { {10, 1000.1}, {20, 200.2}, {10, 2000.2}, {30, 100}, {10, 3000.3} };
    
    // Variable to hold the sum of capacities
    double sum{};
    
    // Identifier to compare elements with
    int sku = 10;

    // Call the calcSum template function
    calcSum(C, sum, sku, 5);

    // Output the result
    cout << "Total capacity of containers with sku " << sku << " is: " << sum << endl;

    return 0;
}
```

---

### **Expected Output**

When the program is executed, it should produce the following output:

```text
Total capacity of containers with sku 10 is: 6000.6
```

---

### **Hints for Implementation**

1. Use a `for` loop to iterate through the array.
2. Check each element using the `==` operator to see if it matches the identifier.
3. Convert the matching element's value to `dataType` before adding it to the total.
4. Use `static_cast` for type safety during conversion.

---

### **Deliverables**

1. The `calc.h` file containing the `calcSum` function implementation.
2. The `main.cpp` file provided above should work without modification when compiled with your `calc.h`.

--- 
