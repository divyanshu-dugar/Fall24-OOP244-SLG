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

## Question 3

---

## **Class Inheritance and Rule of Three: `ExtendedName` Class Implementation**

**Objective:**  
In this task, you are required to create a class named **`ExtendedName`** that inherits from the **`IndividualName`** class. This class should manage dynamic memory for both a first name and a last name, following the **Rule of Three** for safe object management.

### **Problem Description:**

1. **Inheritance:**
   - The **`ExtendedName`** class must inherit from the **`IndividualName`** class.
   - The **`IndividualName`** class already manages a dynamic C-string for the first name.
   - The **`ExtendedName`** class should extend this by adding a last name (another dynamic C-string) specific to the class.

2. **Copy Management:**
   - Use the **`copyString`** method from the **`IndividualName`** class to manage dynamic memory for the last name in the **`ExtendedName`** class.
   - Implement the **Rule of Three** to handle the copy constructor, copy assignment operator, and destructor for safe memory management of **`ExtendedName`** objects.

3. **Class Initialization:**
   - The **`ExtendedName`** class should be initialized with two C-strings:
     - The first name will be passed to the **`IndividualName`** base class.
     - The second C-string (last name) will be specific to the **`ExtendedName`** class.
   - If no last name is provided, it should be treated as `nullptr`.

4. **Print Function:**
   - Implement a **`print`** function in the **`ExtendedName`** class that outputs the full name (first name + last name) to a given `ostream`. The first and last name should be separated by a space.
   - If the last name is `nullptr`, only print the first name.

5. **File and Screen Output:**
   - In your **`main`** function, create instances of **`ExtendedName`** and test the functionality by printing to both the screen and a file (`extended_names.txt`).
   - Ensure the output follows the format specified below.

---

### **Provided Code**

You are provided with the following **`IndividualName`** class that you do not need to modify. You are required to implement the **`ExtendedName`** class as described:

```cpp
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class IndividualName {
    char* m_name{};
protected:
    char* copyString(const char* content) {
        char* newContent{};
        if (content) {
            newContent = new char[strlen(content) + 1];
            strcpy(newContent, content);
        }
        return newContent;
    }
public:
    IndividualName(const char* content = nullptr);
    IndividualName(const IndividualName& other);
    IndividualName& operator=(const IndividualName& other);
    virtual ~IndividualName();
    virtual ostream& print(ostream& ostr) const;
};

ostream& operator<<(ostream& ostr, const IndividualName& name);

// DO NOT COMPLETE THE IMPLEMENTATION OF THE ABOVE CLASS. We assume the IndividualName class is fully implemented and works perfectly.

// Implement the ExtendedName class below to satisfy the question's requirements.
```

### **Main Function:**

```cpp
int main() {
    ofstream file("extended_names.txt");

    // Create ExtendedName objects
    ExtendedName ename1("Alice", "Green");
    ExtendedName ename2 = ename1, ename3("Michael", "");

    // Output to console
    cout << ">" << ename1 << "-" << ename3 << "<" << endl;

    // Output to file
    file << ename1 << endl;

    return 0;
}
```

---

### **Expected Output**

#### **Screen Output:**
```
>Alice Green-Michael<
```

#### **File Output (`extended_names.txt`):**
```
Alice Green
```

---

### **Tasks:**
1. **Class Design**:
   - Create the **`ExtendedName`** class that inherits from **`IndividualName`**.
   - Add the necessary constructors, copy constructors, copy assignment operator, and destructor to handle dynamic memory.
   
2. **Print Function**:
   - Implement the **`print`** function that displays the full name or just the first name if the last name is `nullptr`.

3. **Ensure Proper Memory Management**:
   - Follow the **Rule of Three** to ensure memory is correctly managed during object copying and destruction.

4. **Test the Functionality**:
   - Use the provided `main` function to test the class and ensure the output is as expected.

---

### **Hints:**

- The **`copyString`** method in **`IndividualName`** will help in managing dynamic memory for both first and last names.
- Ensure that you implement the **copy constructor**, **copy assignment operator**, and **destructor** in **`ExtendedName`** to properly manage memory and avoid leaks.
- You can assume that the **`IndividualName`** class is fully implemented and you only need to focus on the **`ExtendedName`** class.

---
## Question 4 - Template Function

Construct a template function named **`filterAndSum`** in a C++ template file named **`filter_tools.h`**. This function filters elements from an array that meet a specified condition and accumulates their sum. It should be designed to handle arrays of various data types.

### **Guidelines:**

1. The template file should be fully prepared for compilation.
2. Your template function should use the following template arguments:
   - **ElementType**: The type of elements in the array.
   - **SumType**: The type used to calculate and store the sum.
   - **ConditionType**: The type used to define the filtering condition.

3. The function should take the following parameters:
   - An array of **ElementType**.
   - A reference to **SumType** for accumulating the sum.
   - A condition value of **ConditionType**.
   - The size of the array (an integer).

4. Iterate through the array of **ElementType**, comparing each element to the **ConditionType** value. 
5. If an element matches the condition, add its value (converted to **SumType**) to the sum.
6. Assign the accumulated value to the sum reference parameter.
7. Assume that the `==` operator is suitable for comparisons and that conversion to **SumType** is valid for array elements.

### **Example Main Function**:
```cpp
#include <iostream>
#include "filter_tools.h"
using namespace std;

class Item {
    int m_id;
    double m_value;

public:
    Item(int id, double value) : m_id(id), m_value(value) {}
    operator double() const { return m_value; }
    bool operator==(int id) const { return m_id == id; }
};

int main() {
    Item items[4] = { {1, 500.5}, {2, 300.3}, {1, 100.1}, {3, 200.2} };
    double total{};
    int filterId = 1;

    filterAndSum(items, total, filterId, 4); // <-- calling the template

    cout << "Total value of items with ID " << filterId << " is: " << total << endl;
    return 0;
}

// Output:
// Total value of items with ID 1 is: 600.6
```
---
