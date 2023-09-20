<h1 align="center">
	📖 get_next_line
</h1>

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br>
</p>
---

## 💡 About the project

> _The aim of this project is to make you code a function that returns a line, read from a file descriptor._

	You will understand how files are opened, read and closed in an OS,
	and how they are interpreted by a programming language for further analysis.
	This task is crucial to understand for a future programmer since much of the time is based
	on manipulating files for data management and persistence.
	This project consists of coding a function that returns one line at a time from a text file.


## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.
All the libraries required for the get_next_line function are already included in the .h header file.

### Instructions

**1. Using it in your code**

Modify de main.c file to use as you desire. Only pass an fd argument to the function "get_next_line()", it will return a string with the last line read.

## 📋 Testing
Simply run this command:

```shell
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c && ./a.out
```

