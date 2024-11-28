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

Here’s the implementation for the requested **`calcSum`** template function and its corresponding `calc.h` module. The implementation is versatile, adhering to the given requirements, and works with arrays of various types.

---

### File: `calc.h`

```cpp
#ifndef CALC_H
#define CALC_H

#include <type_traits> // For type safety and conversions

// Template function to calculate the sum of array elements based on a condition
template <typename classType, typename dataType, typename idType>
void calcSum(const classType* array, dataType& sum, const idType& id, size_t size) {
    // Ensure the sum is initialized to zero
    sum = static_cast<dataType>(0);

    // Iterate through the array
    for (size_t i = 0; i < size; ++i) {
        // Check if the current element matches the provided ID
        if (array[i] == id) {
            // Add the value of the element (converted to dataType) to the sum
            sum += static_cast<dataType>(array[i]);
        }
    }
}

#endif // CALC_H
```

---

### Explanation of `calc.h`:
1. **Template Parameters**:
   - `classType`: Specifies the type of elements in the array.
   - `dataType`: Specifies the type of the sum to be calculated.
   - `idType`: Specifies the type of the identifier used for comparison.

2. **Function Parameters**:
   - **`array`**: A pointer to an array of type `classType`.
   - **`sum`**: A reference to a variable of type `dataType` where the calculated sum is stored.
   - **`id`**: An identifier of type `idType` to compare with elements in the array.
   - **`size`**: The number of elements in the array.

3. **Functionality**:
   - Iterates through the array and compares each element with `id`.
   - If an element matches the `id`, its value (converted to `dataType`) is added to the `sum`.
   - Ensures type safety using `static_cast`.

---

### File: `main.cpp`

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

### Output:
When you compile and run the program, the output will be:

```
Total capacity of containers with sku 10 is: 6000.6
```

---

### Key Notes:
1. The template function is written in a separate header file (`calc.h`) to be reused in other projects.
2. The `Container` class demonstrates:
   - Overloading the equality operator (`==`) to compare `m_sku` with an integer ID.
   - A conversion operator to convert `Container` objects into a `double` for summation.
3. The function adheres to the principle of dynamic type handling, ensuring safe conversions and calculations.

This design is clean, reusable, and extensible for other data types and scenarios.
