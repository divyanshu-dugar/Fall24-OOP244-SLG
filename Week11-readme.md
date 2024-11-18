# Derived Class with a Resource

## Learning Outcomes

Upon successful completion, you will have demonstrated the abilities to:

* Apply the rule of three and its derived class.
* Use the concept of inheritance and polymorphism to reuse functionality of parent in child classes
* Describe what you have learned in completing this workshop

# Part 1 - LAB (100%)

## LibraryItem Class
Create a LibraryItem class that represents different types of items in a library's inventory. The class should have the following data members:
* `char* m_title` - A pointer to store the title of the item.
* `int m_year` - An integer to store the publication year of the item.  

The LibraryItem class should include the following member functions:

* A default constructor - This constructor should set the title pointer to null and year to 0.  
* A parameterized constructor - This constructor should take two parameters: title and year. It should allocate memory for the title string on the heap and make the title pointer point to the appropriate heap memory. Also, set the year to the provided year value.  
* The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning LibraryItem objects.  
* `virtual ostream& display(ostream& ostr = cout) const` - This method should display the title and year of the library item as follows:
  ```text
  Title: The book Title (the year)<no new line>
 
  For example:
 
  Title: The Great Gatsby (1925)<no new line>
  ```

## Book Class  
Create a Book class that inherits from the LibraryItem class. The Book class should have an additional private data member:  
* `char* m_author` - A pointer to store the name of the author of the book.  

The Book class should include the following member functions:  
* A parameterized constructor - This constructor should take three parameters: title, year, and author. It should allocate memory for the title and author strings on the heap and make the respective pointers point to the appropriate heap memory. Also, set the year to the provided year value.  
* The rule of three - Implement the rule of three (copy constructor, copy assignment operator, and destructor) to manage the allocated memory properly when copying and assigning Book objects.  
  > Note that the copy constructor and copy assignment of the derived class must manage the copying and copy-assigning of the base class too.
* `ostream& display(ostream& ostr = cout) const` - This method should display the title, year, and author of the book as follows:
  ```text
  Title: The book Title (the year)<new line>
  Author: The Author Name<no new line>
 
  For example:
 
  Title: The Great Gatsby (1925)<new line>
  Author: F. Scott Fitzgerald<no new line>
  ```
* `bool operator >(const Book& other)const` - This method checks for non-null author names and checks to see if the object's author name is lexicographically greater than the other object's author name, it returns `true`; otherwise, it returns `false`.
  
## Tester Program
[main.cpp](main.cpp)

## Execution Sample
[correct_output.txt](correct_output.txt)
