# get_next_line

**Description**: The get_next_line() function returns the first line of an open file descriptor (fd), if any, and the next lines in successive calls.

The function reads `BUFFER_SIZE` bytes of an open fd to a buffer until it reaches a new line character (`\n`). It saves the exceeding bytes after the `\n` character in a static variable, returning just one line at a time and repeating the process in a next call until the end of the file. The next calls of the get_next_line() function rescues the information stored in the static variable, if any. Get_next_line receives an int correspondent to a valid open fd and returns a pointer to the string created from the read bytes.

**Return values**: The get_next_line() function returns the first line of an open fd, if any, and the next lines in successive calls. The function returns `NULL` if an error occurs, if the file is empty or if there is nothing else to be read.

**What I've learned in this project**: How to open and read a file descriptor with proper functions; what a file descriptor is; static variable - a handful way to store information in variables that can be reused outside the scope of a function call where the variable was created; management of memory in stack and heap areas; Valgrind usage to track memory leaks and solve critical problems; code abstraction, buffer concept and string manipulation.

**Special thanks** to João Miguel (jogomes-) for his invaluable help in solving the memory leaks and general understanding of the problem.
