Assignment name  : brackets
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. 
For each argument, the program prints on the standard output "OK" followed by a newline if the expression is correctly bracketed, otherwise it prints "Error" followed by a newline.

Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' and ']'and braces '{' and '}'. Every other symbols are simply ignored.

1. An opening bracket must always be closed by the good closing bracket in the correct order. 
2. A string which not contains any bracket is considered as a correctly bracketed string.
3. If there is no arguments, the program must print only a newline.

Examples :

`$> ./brackets '(johndoe)' | cat -e`

`OK$`

`$> ./brackets '([)]' | cat -e`

`Error$`

`$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e`

`OK$`

`OK$`

`$> ./brackets | cat -e`

`$`

`$>`
