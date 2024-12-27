## Compile the source code into object code:

`clang -Wall -c mystring.c`

- This outputs the `mystring.o` file

## Use the archive utility to build the library

`ar -rcs libmystring.a mystring.o`

- This generates the library `libmystring.a`