# ft_printf

## Introduction

Welcome to my implementation of printf! In this project, I have the task of recoding the `printf()` function from the C standard library (libc). This was a 42 project that was given to add to our personalised library of manually written functions, I have left alot of comments for reference.

## What is `printf()`?

The printf() function stands as a foundational element within C programming, serving as a pivotal tool for formatting and presenting data on the console. Whether you need to print a simple string, format numeric values, or display complex data structures, `printf()` has been the go-to function for programmers.

## Project Objective

The goal is to reimplement the `printf()` function, but with a twist: we must exclude the buffer management aspect. Here are the following requirements:

- Implement the `ft_printf()` function to handle various conversions, including `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
- Ensure that the implementation meets the standards set by the original `printf()` function from libc.
- Utilise the `ar` command to create our library, adhering strictly to best practices and avoiding shortcuts.
- Organise our project structure by creating the `libftprintf.a` library at the root of this repository for ease of access and maintenance.

## Implemented Conversions

Throughout the project, we will address the following conversions:

- `%c`: Print a single character.
- `%s`: Print a string according to the common C convention.
- `%p`: Print the void pointer argument in hexadecimal format.
- `%d`, `%i`: Print integers in base 10.
- `%u`: Print unsigned decimal numbers.
- `%x`: Print numbers in hexadecimal (lowercase) format.
- `%X`: Print numbers in hexadecimal (uppercase) format.
- `%%`: Print a percent sign.

We use the '%' symbol to indicate the beginning of our format specifier, the following character will then communicate the where in the string the conversion will happen and what format will be needed. To break it down more simply, for those who have not used the function; it's a command that is used to display to the screen a formatted string using various characters to indicate as mentioned above. For example:

```
#include <stdio.h>

int main()
{
	printf("Hello World! Let's re-build libc's function Printf in 1 day\n");
	printf("Hello World! Let's re-build libc's function %s in %d day\n", "Printf", 1);
}
```

Both these printf functions will give the same output to the screen, take note where in the sentence the format specifier sit and observe in the secoond line how the words that replace them are in the same order as they appear in the sentence as they are presented at the end of the string seperated by commas. This is the syntax needed. I have put the output in directly in the example, but you can also use this for functions and different data elements, making it great for testing your code and converting things such as a number to a character. 

## Notes

### Ft_printf Prototype
 The prototype printf is as follows:

 ```
 int	ft_printf(const char *format, ...);

 ```

The reason why the prototype uses 'int' as a return is for error handling, lets say you're using ft_printf to display a sentence, if all goes to plan it will return how many characters it wrote (a positive number) but what if some thing were to go wrong while writing it back to the display, it will then tell you there was an error with a negative number.

### Introduction to Variadic Functions
Lets start with the '...' we see above in the prototype, this is indicating a Variadic Function which means it will accept variable number of arguments. A variadic function must have at least one mandatory argument, in 'printf', it's the format string ('const char *format'). 

To handle these functions the stdarg Library is needed (include <stdarg.h>). This library provides macros such as 'va_list', 'va_start', 'va_arg', and 'va_end' (macros in C are shortcuts for text replacement, making coding easier and code more readable). Let's have a look at what these few can do as they will be used throughout this project.

| Macro   | Description                                                                           | Example Usage                           |
|---------|---------------------------------------------------------------------------------------|-----------------------------------------|
| va_list | VARIABLE - A list of all dynamic arguments, an object type holding the information needed by the following function macros. It is declared like any other variable.        | `va_list args(put_any_name_you_want);`                         |
| va_start| MACRO - Initialises the va_list. It must be called before any use of va_arg otherwisee your va_list (arguments) will be empty.             | `va_start(args, format);`               |
| va_arg  | MACRO - Accesses the next argument in the va_list. You specify the type of the argument.       | `va_arg(args, char*);`<br>`va_arg(args, int);` |
| va_end  | MACRO - Cleans up the object va_list when done. It should be called after using va_start then it is no longer usable.             | `va_end(args);`                         |
| va_copy  | MACRO - Copies the contents of one va_list object to another, creating a new independent list. Syntax duplicates the contents of src into dest, creating a separate va_list object for further independent usage.            | `va_copy(dest, src);`                         |


Basic visual example:
```
#include <stdio.h>
#include <stdarg.h>

// Function to calculate the sum of a variable number of integers
int sum(int count, ...) {
    // Declare a va_list variable to hold the arguments
    va_list args;
    // Initialise the va_list before accessing variable arguments
    va_start(args, count);

    // Initialise total to 0
    int total = 0;
    
    // Add up each integer argument using va_arg
    total += va_arg(args, int); // Add the first integer argument
    total += va_arg(args, int); // Add the second integer argument
    total += va_arg(args, int); // Add the third integer argument
    total += va_arg(args, int); // Add the fourth integer argument

    // Clean up the va_list when done
    va_end(args);

    // Return the total sum
    return total;
}

// Main function
int main() {
    // Call the sum function with 4 integer arguments
    int result = sum(4, 10, 20, 30, 40);

    // Print the result
    printf("Sum: %d\n", result);

    // Return 0 to indicate successful execution
    return 0;
}
```
```
Sum: 100
```

Keeping in mind the 4 in the line 'int result = sum(4, 10, 20, 30, 40);' is actually indicating the count of the variable arguments being passed (i.e., 4 integers: 10, 20, 30, and 40). It's not one of the values being added.

### Introduction to Hexadecimal

This was my first deep dive in what a Hexadecimal is, for those like myself that didn't know how to use it or what it is, a hexadecimal is just another numbering system like what we use on a daily basis but instead of using the just the symbols '0-9' to represent all our numbers we can use 16 symbols which are now '0-9' and continue onto 'a-f'. It will just continue on from 9, so now 10 will equal 'a', 11 will equal 'b' and so on. We generally use Hexadecimal when dealing with large values and wanting to compress them down. Memory addresses in computers are often represented in Hexadecimal. 

Here's a simple explanation of the most common numbering systems:

Decimal System (Base-10): This is the system we use every day, where each digit can be from 0 to 9. The place value of each digit increases by a power of 10 as you move from right to left.

Binary System (Base-2): In the binary system, there are only two digits: 0 and 1. Each digit's place value increases by a power of 2 as you move from right to left. It's widely used in computing because digital devices use on/off states, which can be represented by 0s and 1s.

Octal System (Base-8): The octal system uses eight digits, from 0 to 7. Each digit's place value increases by a power of 8 as you move from right to left. Octal is less common nowadays but used to be popular in computing.

Hexadecimal System (Base-16): Hexadecimal uses 16 digits, from 0 to 9 and then A to F (which represent values 10 to 15). Each digit's place value increases by a power of 16 as you move from right to left. Hexadecimal is widely used in computing because it's a convenient way to represent binary values in a shorter form.




 
