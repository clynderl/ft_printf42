# PRINTF
## Project Overview
This FT_PRINTF is a 42 Project that aims to mimic original c printf function

Basics, requested from subject:
* A) parsing for flags, field_width, precision, length_modifier.
* B) parsing for conversion specifier.
* C) displaying UTF-8 characters. (%C and %S).
* D) computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
* E) displaying signed numbers (%d %D %i).
* F) displaying pointer address (%p).
* G) displaying floats (%f).

## Sources
* https://linux.die.net/man/3/printf

## Installation & Tests
```
$> make
$> gcc libftprintf.a srcs/main.c && ./a.out
```
