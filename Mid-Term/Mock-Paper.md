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

