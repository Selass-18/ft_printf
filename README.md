*This project has been created as part of the 42 curriculum by idaitihy.*

# ft_printf

## Description

`ft_printf` is my own version of the C function `printf()`. The goal of the project is to build a static library, `libftprintf.a`, that contains a function with this prototype:

```c
int ft_printf(const char *format, ...);
```

Like the original, it writes formatted text on the standard output and returns the number of characters printed (or `-1` if an error happens). The main thing I learned in this project is how **variadic functions** work in C, with `<stdarg.h>`.

Only the mandatory part is implemented (no bonus).

### Supported conversions

| Conversion | What it prints |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a pointer in hexadecimal, with `0x` in front (`(nil)` for `NULL`, like glibc on Linux) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a percent sign |

### Project files

| File | Content |
|---|---|
| `ft_printf.h` | prototypes and the macros `HEX_LOW` and `HEX_UP` |
| `ft_printf.c` | `ft_printf` and two `static` helpers, `ft_handle` and `ft_convert` |
| `ft_putchar_len.c` | `ft_putchar_len` (prints one character) |
| `ft_putstr_len.c` | `ft_putstr_len` (prints a string) |
| `ft_putnbr_len.c` | `ft_putnbr_len` (prints a signed integer) |
| `ft_putunbr.c` | `ft_putunbr_len` (prints an unsigned integer) |
| `ft_puthex_len.c` | `ft_puthex_len` (prints a number in hexadecimal) |
| `ft_putptr.c` | `ft_putptr_len` (prints a pointer) |
| `Makefile` | builds `libftprintf.a` |

## Instructions

### Compilation

The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`.

```
make
```

This creates `libftprintf.a` at the root of the repository (with the `ar` command). The other rules are:

| Rule | What it does |
|---|---|
| `make all` | same as `make` |
| `make clean` | removes the object files (`.o`) |
| `make fclean` | removes the object files and `libftprintf.a` |
| `make re` | `fclean`, then `all` |

Running `make` a second time does nothing (no useless relink).


### Overview

`ft_printf` reads the format string once, from left to right, with an index.

1. If `format` is `NULL`, return `-1`.
2. Start the `va_list` with `va_start`.
3. For each character of the format:
   - if it is not a `%`, print it;
   - if it is a `%`, look at the next character (the conversion), read the matching argument with `va_arg` using the right type, and print it with the right function.
4. Add the number of characters printed to a total. If a function returns `-1`, call `va_end` and return `-1`.
5. A `%` is followed by one more character, so in that case the index moves by 2 instead of 1.
6. At the end, call `va_end` and return the total.

### Why it is built like this

**One function per conversion, each one returns a count.** Every `ft_put..._len` function returns the number of characters it printed, or `-1` if `write` failed. This way `ft_printf` only has to add the values to get its return value, and an error is passed up from the lowest function to `ft_printf` without any special case.

**Dispatch in a separate function.** `ft_convert` chooses the function from the conversion letter, and `ft_handle` decides if the current character is a normal one or a `%`. Both are `static` because only `ft_printf.c` uses them. This keeps every function under the 25 lines limit of the Norm and separates the reading of the format from the printing.

**Numbers are printed with recursion.** The last digit of a number is easy to get (`n % 10`) but it must be printed last. A recursive call on `n / 10` prints all the leading digits first, so the digits come out in the right order without a buffer and without `malloc`. The same idea is used for hexadecimal with `/ 16` and `% 16`.

**`INT_MIN` is handled with a `long`.** `-INT_MIN` does not fit in an `int`, so `ft_putnbr_len` copies the number in a `long` before changing its sign. The sign is printed once, then the digits are printed by the recursion.

**One hexadecimal function for `%x`, `%X` and `%p`.** `ft_puthex_len` receives the table of digits as a parameter (`HEX_LOW` or `HEX_UP`), so lowercase and uppercase use the same code. Its first parameter is an `unsigned long`: an address is 8 bytes on a 64-bit machine, and an `unsigned int` would cut half of it.

**No buffer.** The subject says not to recode the buffer of the original `printf()`, so every character is written with `write`. This makes more system calls than the real `printf()`, but the code stays simple. I also thought about building the number in a string with `malloc` (it needs a `free` on every exit path, even when `write` fails) and about a local array with a single `write` (it works, but the indexes are harder to follow). I kept the recursion.

**Special cases.**
- `%%` prints a `%` and does not read any argument. Calling `va_arg` here would shift all the following arguments.
- A `%` at the very end of the format, or an unknown conversion, returns `-1` (the behavior is undefined in the original `printf()`).
- `%s` with `NULL` prints `(null)` and `%p` with `NULL` prints `(nil)`, like glibc.

### Data structure

I do not use any structure of my own. The only one is the `va_list`, which works like a cursor over the arguments: `va_start` puts it on the first argument after `format`, and each `va_arg(args, type)` returns the argument under the cursor, read with the given type, then moves the cursor. The type must be given because the arguments have no label in memory: `va_arg` only knows what I tell it. The `va_list` is passed to the helpers by pointer (`va_list *`), so that they move the same cursor as `ft_printf`.

On x86-64 Linux (System V ABI), a `va_list` is an array of one small structure with four fields: `gp_offset` (position of the cursor among the saved registers for integers and pointers, from 0 to 48), `fp_offset` (same for floating point numbers), `overflow_arg_area` (address of the next argument when it was passed on the stack) and `reg_save_area` (address of the zone where the registers were copied at the beginning of the function). This is specific to this architecture, the C standard does not define it, so the code only uses `va_start`, `va_arg` and `va_end`.

## Resources

### References

- `man 3 printf`, `man 3 stdarg` and `man 2 write`
- cppreference, variadic functions: https://en.cppreference.com/w/c/variadic
- GNU Make manual: https://www.gnu.org/software/make/manual/
- System V AMD64 ABI (the document that defines how arguments are passed and how `va_list` is laid out on x86-64 Linux)
- The 42 Norm

### How AI was used

I used an AI assistant during this project to help me understand some concepts, as well as to get examples and explanations whenever I had difficulties understanding certain parts of the project.