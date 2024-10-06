## Coding Instructions

**JugRack:**

The following **Jug** class encapsulates the name of the liquid it holds and the Jug's size:

```cpp
class Jug {
    char m_name[21];
    int m_size; // in milliliters
public:
};
```

Complete the code of this class by adding a read and a write function as follows:

### 1. Read Function

- The read function reads a comma-separated value of name and size ending with a newline.
- We assume that the user will not make a mistake in data entry.
- Example Input: `Lemonade,1500<ENTER>`

This represents a 1500 ml Jug of Lemonade.

### 2. Write Function

- The write function displays the above input as follows:
- The size followed by the content name in 20 characters, right-justified, and spaces filled with dots.
  
Example Output:

```txt
1500 ..........Lemonade
```

### 3. Jug Object Initialization

- A Jug object is always constructed as an empty Jug with nothing in it.

---

**Tray:**

Complete the following **JugRack** class. A JugRack can come in different sizes, between 5 and 250.

```cpp
class JugRack {
    Jug* m_jugs;  // dynamic array of jugs
    int m_size;   // maximum number of jugs on the rack
    int m_num;    // number of jugs on the rack
public:
};
```

### 4. Construct a JugRack

- The constructor takes an integer for its size.
- If the size is less than 5 or more than 250, the JugRack should be set to an invalid empty state.

### 5. Memory Deallocation

- When a JugRack goes out of scope, all allocated memory should be deleted.

### 6. Set Empty State

- Add a `setEmpty()` method to set the JugRack to an invalid empty state.

### 7. Boolean Casting

- If a JugRack object is cast to a boolean, it should return `true` if the JugRack is valid, or `false` if it is invalid.

### 8. Overload the `+=` Operator

- Overload the `+=` operator, returning the reference of the JugRack object and receiving a Jug by value.
- This operator should add the Jug beside the last Jug that is already on the JugRack.
- Any attempt to add a Jug to an already full JugRack will render the JugRack invalid (set to a safe empty state).

### 9. Display Function

- Create a `display()` function that prints all the Jugs in the JugRack only if the JugRack is in a valid state; otherwise, nothing should be printed.

### 10. Read Function for Empty Jugs

- Create a `read()` function to read all the empty Jugs in the JugRack.
- For example, if the JugRack has 10 spaces and 8 non-empty Jugs, then the last 2 Jugs should be read from the keyboard, and the JugRack will be full afterward.

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
