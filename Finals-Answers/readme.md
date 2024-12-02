### Question 1 - Answer

Below is the complete implementation of the `Tag` class, following the requirements of the Rule of Three, dynamic memory allocation, and inheritance readiness.

```cpp
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class Tag {
    char* m_tagData{}; // Dynamically allocated C-string for the tag data
protected:
    // Helper function to clone a string
    char* cloneStr(const char* tag) {
        char* newTagData{};
        if (tag) {
            newTagData = new char[strlen(tag) + 1];
            strcpy(newTagData, tag);
        }
        return newTagData;
    }
public:
    // Default constructor
    Tag() : m_tagData(nullptr) {}

    // Parameterized constructor
    Tag(const char* tag) : m_tagData(cloneStr(tag)) {}

    // Copy constructor
    Tag(const Tag& other) : m_tagData(cloneStr(other.m_tagData)) {}

    // Copy assignment operator
    Tag& operator=(const Tag& other) {
        if (this != &other) { // Avoid self-assignment
            delete[] m_tagData;
            m_tagData = cloneStr(other.m_tagData);
        }
        return *this;
    }

    // Destructor
    virtual ~Tag() {
        delete[] m_tagData;
    }

    // Display method to be overridden by derived classes
    virtual void present(ostream& os) const {
        if (m_tagData) {
            os << m_tagData;
        }
    }

    // Overload the insertion operator
    friend ostream& operator<<(ostream& os, const Tag& tag) {
        tag.present(os);
        return os;
    }
};

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
### Question 2 - Answer

Here is the implementation for the `calcSum` template function in a standalone module named `calc.h`. The function follows the given requirements for summing up elements in an array based on a specific condition.

---

### **`calc.h`**

```cpp
#ifndef CALC_H
#define CALC_H

#include <cstddef> // For size_t

// Template function implementation
template <typename classType, typename dataType, typename idType>
void calcSum(const classType* array, dataType& sum, const idType& id, size_t size) {
    sum = 0; // Initialize the sum to 0
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == id) { // Compare array element with the identifier
            sum += static_cast<dataType>(array[i]); // Add the value to sum after casting
        }
    }
}

#endif // CALC_H
```

---
