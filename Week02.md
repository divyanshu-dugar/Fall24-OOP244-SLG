# Coding Question: Overloading and Dynamic memory allocation

In this, you will be able to modify the content of variables in other scopes, overload functions, allocate memory at run-time, and deallocate that memory when it is no longer required.

## Learning Outcomes
Upon successful completion of this question, you will have demonstrated the abilities to:
-  allocate and deallocated dynamic memory for an array and a single object
-  overload functions;
-  Use references;

# Part 1

Your task is to create a module called **Assessments** (`Assessments.cpp and Assessments.h`) to implement multiple overloaded read functions to read a series of subject names and their average mark received by students that are saved in a file. 

The file is in the following format:
- The first line is only an integer that is the number of upcoming records
- The rest of the file is the records of subject marks.<br />Each subject mark record consists of:
  - a double number (the mark)
  - comma
  - name of the subject
  - newline character
  
Example:
```text
5
70.9,Applied Problem Solving
55.5,Computer Principles for Programmers
63.8,Communicating Across Contexts 
88,Introduction to Programming Using C
78.9,Introduction to UNIX/Linux and the Internet

```

## implementation

Use the following structure to hold an assessment record.
For practice, both fields should be kept dynamically:

```cpp
struct Assessment {
   double* m_mark;
   char* m_title;
};
```

- m_mark will hold the address of a single double value that is kept **dynamically** in memory
- m_title will hold the address of a cstring that is kept **dynamically** in memory but will not be more than 60 + 1(null) characters. 
> Although the dynamic title of the assessment will not be more than 60 characters, but when allocating memory make sure the size of the dynamic cString is equal to the exact size of the data read from the file and not more.

## Functions to implement:

> Refer to your IPC144 topics for "reading information from a file": https://intro2c.sdds.ca/E-Secondary-Storage/records-and-files

### `bool read(int& value, FILE* fptr);`
Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false

### `bool read(double& value, FILE* fptr);`
Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false

### `bool read(char* cstr, FILE* fptr);`
Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, `cstr`  and returns true if it was successful, otherwise, it will return false

> Use the following format in the fscanf to accomplish this:<br/> `",%60[^\n]\n"`

##### V1.1 correction
(Changed the argument name in the following read function form **asm** to **assess**; **asm** is a C keyword and cannot be used as an variable name)
### `bool read(Assessment& assess, FILE* fptr);`
First, it will try to read a double value for the mark and a string for the title into a temporary local double variable and a 60-character lone cString (+1 for null).

If the read is successful, it will then allocate a dynamic double and a dynamic cString to the exact size of the read cstring from the file into the fields of the assess structure (assess.m_mark and assess.m_title) and copies the values into them.<br />
In this case, the function will return true, otherwise, it will return false with no memory allocation.

### `void freeMem(Assessment*& aptr, int size);`
This function will receive a reference of a dynamic Assessment array and its size.
The function then will delete the dynamic Assessment array as follows:

The dynamic array will be deleted by first going through each element of the Assessment array in a loop, deleting the dynamic double and the dynamic cString of all Assessment elements and then it will delete the array itself.


### `int read(Assessment*& aptr, FILE* fptr);`

This read function receives a reference of an Assessment pointer (to hold a dynamic array) and a file pointer from which it will read the assessment records into a newly allocated dynamic array.

The function will first read one integer which is the number of upcoming records to read.

Then it will allocate a dynamic array of Assessments in the `aptr` pointer reference. After allocating the memory, in a loop, it will read each record of the file into the Assessment elements (use the proper read overload for this). 
This loop should stop either if the number of reads reaches the number of elements or if the read function fails.

When the loop is done compare the number of reads to the number of elements of the array. If the number is not a match, free the Memory of the dynamic array (`freeMem`) and return zero, otherwise, return the size of the array.



## The tester program.
Do not modify the main module.

[main.cpp](./lab/main.cpp)

## Expected output

[correct_output.txt](./lab/correct_output.txt)

# Part 2

## Implementation  
You task it to create a C++ program that manages hotel room reservations, including room and guest information. The program should consist of three modules: 
- Room.cpp
- Guest.cpp
- main.cpp (tester). 


Your task is to implement the functions in the respective modules.

> Note that all unused pointers should be kept as nullptr after deallocation and if any of the set functions have invalid values as arguments.

> We assume all user entries are valid and are done without any mistakes.

### Structs/modules to be used:

#### Guest
This structure holds the names dynamically. It also tracks if the guest is an adult or a child.

```c++
struct Guest {
   char* m_firstName;
   char* m_lastName;
   bool m_adult;
};
```

#### Mandatory Guest related functions:

```c++
// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
void set(Guest& guest, const char* first, const char* last, int age);

// Prints the guest name:
// "Name Surname(child)"
// The child flag is printed if the guest is not an adult
// and if the names are not set, "Vacated!" is printed.
void print(const Guest& guest);

// books the guest information from the console:
// Name: Jake<ENTER>
// Lastname: Doe<ENTER>
// Age: 10<ENTER>
void book(Guest& guest);

// vacates the guest by dallocating its memory.
void vacate(Guest& guest);
```

#### Room

```c++
struct Room {
   char m_roomNumber[6];    
   int m_noOfGuests;
   Guest* m_guests;
}
```
##### V1.2   
(Corrected the arguments from Guest to Room)
#### Mandatory Room related functions:

```c++
// sets the Room by allocating a dynamic array of guests and setting the room number 
// (no validation is done for room number)
void set(Room& room, int numberOfGuests, const char* roomNumber);

// Prints the room number and names of the guests in the following lines with four 
// spaces of indentaion 
// See correct_output.txt for the exact format
void print(const Room& room);

// Books a room by receiving the room number, number of guests and the guest information.
// See correct_output.txt for the exact format
void book(Room& room);

// vacates the room by dallocating all the memory used.
void vacate(Room& room);
```


## Tester program (main.cpp)
This module is fully provided. Please do not modify it. Review it and make sure you understand how the functions that you have developed are being used.
Make sure to include the safeguard in header files.

## The tester program.
[main.cpp](DIY/main.cpp)

## Expected output
[correct_output.txt](DIY/correct_output.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

### Files to submit:  

```reflect.txt``` and:
```Text
Room.cpp
Room.h
Guest.cpp
Guest.h
main.cpp 
```

### Data Entry

No data entry is required for this part. Check the execution sample.

### Submission Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```bash
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


