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

## Conclusion

 
