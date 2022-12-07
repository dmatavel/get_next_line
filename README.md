# get_next_line

**Summary**: get_next_line returns the first line of an open file descriptor, if any, and the next lines in successive calls.

**How it works**: get_next_line is a function that reads `BUFFER_SIZE` bytes of an open file descriptor to a buffer until it reaches a new line character. It saves the exceeding bytes after the new line character in a static variable, returning just a new line and repeating the process in a next call until the end of the file. The next calls of get_next_line rescue the information stored in the static variable, if any.

**Return values**: return the first line of an open file descriptor, if any, and the next lines in successive calls. The function returns `NULL` if an error occurs, if the file is empty or if there is nothing else to read.

**What I've learned in this project**: How to open and read a file descriptor with proper functions; what a file descriptor is; static variable - a handful way to store information in variables that can be reused outside the scope of a function call where it was created; management of memory in stack and heap areas; Valgrind usage to track memory leaks and solve critical problems; code abstraction, buffer concept and string manipulation.

**Special thanks** to João Miguel (jogomes-) for his invaluable help in solving the memory leaks and general understanding of the problem.
