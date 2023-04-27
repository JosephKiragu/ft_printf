# ft_printf

ft_printf is a C project that aims to recreate the C standard library function `printf()`. This project is part of the 42 coding school curriculum and helps students understand variadic functions, string manipulation, and memory management in C.

## Features

- Supports basic format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%n`.
- Handles flags: `-`, `0`, `.` and `*`.
- Handles field width and precision.
- Implements a custom buffer for efficient output.

## Getting Started

### Prerequisites

- A Unix-based operating system (macOS, Linux, or WSL on Windows)
- GCC compiler
- `make` utility

### Installation

1. Clone the repository:
```
git clone https://github.com/JosephKiragu/ft_printf.git
```

2. Change into the project directory:
```
cd ft_printf
```

3. Compile the project using the provided `Makefile`:
```
make
```

### Usage

1. Include the header file `ft_printf.h` in your C source files where you want to use the `ft_printf` function.

```c
#include "ft_printf.h"
```

2. Use the `ft_printf` function in the same way as the standard `printf()` function. Here's an example:

```c
#include "ft_printf.h"

int main(void)
{
    int number = 42;
    char *string = "Hello, World!";

    ft_printf("This is an integer: %d\n", number);
    ft_printf("This is a string: %s\n", string);

    return 0;
}
```

3. Compile your program with the ft_printf object files:

```
gcc -Wall -Wextra -Werror -I./ -o your_program your_program.c libftprintf.a
```

4. Run your program:

```
./your_program
```

## Testing

The project comes with a test suite. To run the tests, follow these steps:

1. Compile the test program:
```
make test
```

2. Run the test program:
```
./test_ft_printf
```
