*This project has been created as part of the 42 curriculum by achancha.*

# get_next_line

## Description

The **get_next_line** project is part of the 42 curriculum. Its goal is to develop a function that reads a file descriptor and returns one line at a time.

The function reads from a file descriptor, such as a file or standard input, and returns the next line whenever it encounters a newline character (`\n`) or reaches the end of the file (EOF).

This project introduces important concepts in C programming, including file descriptors, the `read()` system call, static variables, dynamic memory allocation, and string manipulation.

## Bonus

The bonus part allows `get_next_line()` to handle multiple file descriptors simultaneously.

Each file descriptor has its own buffer and reading position, allowing the function to read from different files without mixing their contents or losing unread data.

It also handles end-of-file (EOF) and reading errors while preserving the remaining data between successive calls.

This implementation uses a static array of structures to maintain an independent state for each file descriptor.


## Instructions

### Compilation

Compile your source files with the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Replace `42` with the desired buffer size.

The `-D BUFFER_SIZE=42` option defines the buffer size during compilation.

If `BUFFER_SIZE` is not defined during compilation, its default value is `1122`(bonus : 2211).

### Running the Program

Run the compiled program with:

```bash
./gnl
```

The behavior depends on how the file descriptor is provided to `get_next_line()` in your test program.


### Return Value

The function returns:
- A pointer to the next line read from the file descriptor, including `\n` if a newline is encountered.
- The remaining characters if EOF is reached before a newline.
- `NULL` if there is nothing left to read or an error occurs.

The returned line is dynamically allocated and must be freed by the caller.

### Files

- `get_next_line.c`: Contains the main `get_next_line()` function.
- `get_next_line_utils.c`: Contains helper functions used for string manipulation and memory management.
- `get_next_line.h`: Contains the function prototypes and the `BUFFER_SIZE` definition.


### Details Description

The `get_next_line()` function reads from a file descriptor and returns one line at a time. It uses the `read()` system call to read data in chunks of `BUFFER_SIZE` bytes, allowing it to handle files of different sizes without reading the entire file at once.

A static buffer preserves the reading state between successive function calls, ensuring that unread characters are not lost when a line is returned. The function accumulates characters into a dynamically allocated string until it encounters a newline character (`\n`) or reaches the end of the file (EOF).

When a newline is found, the function returns the complete line, including the newline character. If EOF is reached and some characters remain, it returns those characters as the final line. If there is no more data to read, it returns `NULL`.

Helper functions are used to append characters to the line and manage allocated memory. Previously allocated strings are freed when replaced, and memory associated with an incomplete line is released if a reading error occurs. The caller is responsible for freeing each returned line after using it.

This project helps develop a better understanding of file descriptors, static variables, dynamic memory allocation, buffer management, and error handling in C.

### Algorithm Justification

The algorithm uses a fixed-size buffer to read data in chunks instead of loading the entire file into memory. A static buffer preserves unread characters between function calls, while dynamic memory allocation allows the function to return lines of different lengths.

This approach makes reading more memory-efficient and allows the function to handle files of different sizes without knowing their total size in advance.

## Resources

### Documentation

- [`read(2)` — Linux Manual Page](https://man7.org/linux/man-pages/man2/read.2.html): Official documentation explaining how the `read()` system call works.
- [W3Schools — C Static Variables](https://www.w3schools.com/c/c_static.php): Explains static variables in C and how their values are preserved between function calls.
- [GeeksforGeeks — Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/): Provides examples explaining static variables and their lifetime in C.

### AI Usage

AI tools were used as learning and development assistance during this project.

They helped with:
- Understanding the project requirements and the expected behavior of `get_next_line()`.
- Clarifying C concepts such as static variables, file descriptors, dynamic memory allocation, and the `read()` system call.
- Reviewing the algorithm and discussing possible approaches to handling errors and memory management.

The implementation was developed and reviewed as part of the learning process. The final code should be tested and understood by the author to ensure that it complies with the project requirements.
