Assignment name  : html_anglebrackets
Expected files   : *.c *.h
Allowed functions: strncpy, write, malloc, free, strcmp
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline
if the expression is correctly closed, otherwise it prints "Error" followed by
a newline.

<html> is an open
</html> is closed
<img> is ignored

An open must always be closed by the corresponding close in the
correct order. A string which not contains any angle brackets is considered as a
correct string. the string between the angle brackets can be anything not just html

If there is no arguments, the program must print only a newline.

Examples :

$> ./html_anglebrackets '<html></html>' | cat -e
OK$
$> ./html_anglebrackets '<bla></html><bla></html>' | cat -e
Error$
$> ./html_anglebrackets '' '<html><bla></html><html></bla></html>' | cat -e
OK$
OK$
$> ./html_anglebrackets | cat -e
$
$> ./html_anglebrackets '<html><html></html><img></html><html><img></html>' | cat -e
OK$

