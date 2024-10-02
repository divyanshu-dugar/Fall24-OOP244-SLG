# Week #4: Constructors, Destructors, and the this object

## Learning Outcomes

Upon successful completion of this question, you will have demonstrated the abilities to:

- The use of the default and overloaded constructors
- The use of destructors
- The use of the current object within the class's member functions
- The handling of dynamic resources via the constructor and destructor

# Instructions

This part of the workshop will involve creating a class called **Fridge** that contains some number of **Food** items up to a maximum capacity.

A Food item is defined by the following struct (see provided Fridge.h/.cpp):

```C++
// Header
#define NAME_LEN 20

  class Food{
    char m_name[NAME_LEN]{};
    int m_weight{};
  public:
    Food();
    Food(const char* nm, int wei);
    const char* name()const;
    int weight()const;
  };

// Implementation
   Food::Food() {}

   Food::Food(const char* nm, int wei){
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }
   const char* Food::name() const{
      return m_name;
   }
   int Food::weight() const{
      return m_weight;
   }

```

### Fridge Module

Design and implement a class named `Fridge` that stores the following information:

- A statically allocated array of Food items whose size is defined by the FRIDGE_CAP constant
- An integer representing the number of Food items currently stored by the Fridge
- A dynamic c-style string that represents the model name of the Fridge (Eg. FridgeMaster3000)

A Fridge object can be created in the following ways:

- By default construction where all the data is set to an empty state
- Providing all the data: an array of Food items, the number of Food items in the array and a model name to initialize the data
- Providing partial data: an array of Food items and the number of Food items in the array

A `Fridge` will have the ability to add more Food to itself after construction, change the model name, query for the state of the Fridge as a whole or if a certain Food is present and display to the standard output the details of the current object. Details of these functions will be provided below.

## Implementation

Define a constant `FRIDGE_CAP` to represent the maximum amount of Food that a Fridge can store (3 items)

Create a class named `Fridge` and have the following members:

### Private Member Variables
```C++
Food m_foods[FRIDGE_CAP]; 
int m_numFoods;
char* m_model;
```

### Constructors/Destructor

```C++
Fridge::Fridge();
```

The default constructor will initialize the data members to an empty state. The m_numFoods will be set to 0 and the m_model set to **nullptr**. The array of Food items will initialized by default from the provided Food struct code.

```C++
Fridge(Food farr[], int nf, const char* mod);
```

The 3-argument constructor will initialize the data members using the provided parameters based on the following process:

- First set the the empty state by utilizing the default constructor and assigning that to the current object
- Validate the parameters by checking if the nf value is greater than 0 and that mod c-string is not nullptr and not the empty string.
- If the above validation succeeds: 
  - set the m_numFoods to the nf value
  - allocate memory to m_model to store the string in the mod value
  - finally loop over the Food array argument (`farr`) and copy each Food to the `m_foods` array up till the `nf` value or the FRIDGE_CAP is met.

The mod parameter will have a default value of "Ice Age".

```C++
Fridge::~Fridge();
```

The destructor will deallocate the dynamic memory held by the m_model data member.

### Public Member Functions

### Modifiers

```C++
bool addFood(const Food& f);
```

This function will attempt to add a Food item to the m_foods array. If the m_numFoods is less than the FRIDGE_CAP then assign the parameter Food item to the m_foods array at the index of m_numFoods. Increment the m_numFoods by 1 to reflect the added Food item.

This function returns true if we have successfully added a Food item and false otherwise.

```C++
void changeModel(const char* m);
```
This function will modify the model_name of the Fridge using the parameter provided if it is valid (ie not nullptr or the empty string).

If it is valid then first deallocate the memory of the m_model then allocate enough memory to store the provided value and copy it to m_model.


### Queries
```C++
bool fullFridge() const; 
```

This function will return whether or not the Fridge is full. A Fridge is considered to be full if m_numFoods has reached FRIDGE_CAP.

```C++
bool findFood(const char* f) const;
```

This function will attempt to determine whether this Fridge holds a particular Food item by comparing its name to the parameter value. If a Food item is found with the same name then return true otherwise return false.

```C++
std::ostream& display(std::ostream& os = std::cout) const;
```

This function will display the details of the Fridge to the ostream parameter named **os**. Instead of printing to cout we will be using this os parameter as the destination (`cout << myvar` vs `os << myvar`). 

If the current object's m_model is in an empty state then this function will not print anything and only return.

Otherwise, print the following:

```Text
Fridge Model: [m_model]<newline>
Food count: [m_numFoods] Capacity: [FRIDGE_CAP]<newline>
List of Foods<newline>
```

If m_numFoods is greater than 0 then loop over the array m_foods and print out each Food item in the following format. The field width for the Food's name should be using the NAME_LEN constant.

```Text
[Food.m_name] | [Food.weight]<newline>
```

This function will return the parameter os.

Refer to the sample output for details on what this will look like.

## Tester Program

[main.cpp](./main.cpp)
