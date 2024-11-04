```markdown
# C++ Practice MCQs

## Question 1  
Which of the following is the correct way to overload the addition operator (`+`) for a class `MyClass`?  
A) `MyClass operator+(const MyClass& other);`  
B) `MyClass& operator+(const MyClass& other);`  
C) `void operator+(const MyClass& other);`  
D) `MyClass operator+(MyClass other);`  

## Question 2  
What will be the output of the following code?

#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Constructor called"; }
    Sample(const Sample&) { cout << "Copy constructor called"; }
};

int main() {
    Sample s1;
    Sample s2 = s1; // Copy constructor will be called here
    return 0;
}
```
A) Constructor called  
B) Constructor called Copy constructor called  
C) Copy constructor called  
D) No output  

---

## Question 3  
What is the main purpose of using the `const` keyword in a member function declaration?  
A) To make the function return a constant value  
B) To ensure that the function does not modify the object it is called on  
C) To allow the function to modify private data  
D) To restrict the function to only const objects  

---

## Question 4  
Which of the following statements about inheritance is true?  
A) A derived class cannot have more than one base class.  
B) A base class can be derived from multiple derived classes.  
C) A derived class inherits all members of the base class, including private members.  
D) A derived class can override public and protected members of the base class.  

---

## Question 5  
Which of the following is the correct way to define a destructor for a class `MyClass`?  
A) `void MyClass::~MyClass();`  
B) `~MyClass();`  
C) `MyClass::~MyClass() { /* code */ }`  
D) `MyClass::~MyClass;`  

---

## Question 6  
What will be the output of the following code?
```cpp
#include <iostream>
using namespace std;

class A {
public:
    virtual void show() { cout << "A"; }
};

class B : public A {
public:
    void show() { cout << "B"; }
};

int main() {
    A* a = new B();
    a->show();
    return 0;
}
```
A) A  
B) B  
C) Compilation error  
D) Runtime error  

---

## Question 7  
When overloading the subscript operator (`[]`), which of the following is the correct prototype?  
A) `Type& operator[](int index);`  
B) `Type operator[](int index);`  
C) `Type& operator[](const int index) const;`  
D) Both A and C  

---

## Question 8  
In the context of namespaces, which of the following statements is true?  
A) A namespace can be nested inside another namespace.  
B) You cannot have multiple namespaces with the same name in the same file.  
C) A namespace cannot contain functions.  
D) All of the above.  
```

You can paste this directly into your Markdown file. Let me know if you need any more help!
