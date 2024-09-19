# Coding Question: Overloading and Dynamic memory allocation

In this, you will be able to modify the content of variables in other scopes, overload functions, allocate memory at run-time, and deallocate that memory when it is no longer required.

## Learning Outcomes
Upon successful completion of this question, you will have demonstrated the abilities to:
-  reading from files
-  allocate and deallocated dynamic memory for an array and a single object
-  overload functions;
-  Use references;

# Instructions

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

[main.cpp](./main.cpp)

## Expected output

[correct_output.txt](./correct_output.txt)
