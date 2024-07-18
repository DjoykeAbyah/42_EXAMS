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

`$> ./html_brackets '<html><bla><body></body><newbody></newbody></bla></html>' | cat -e`

`$ OK`

`$> ./html_brackets '<bla gvngf></html><bla></html>' | cat -e`

`$ Error`

`$> ./html_brackets '' '<html><bla></html><html></bla></html>' | cat -e`

`$ OK`

`$ OK`

`$> ./html_brackets | cat -e`

`$`

`$> ./html_brackets '<html><img></html><img><html><img></html>' | cat -e`

`$ Error`


stack until closing is found, compare with last open, (either delete when linked list or --)

<head><html> = 1;

<div><a><html><div><body><head><head><html></html></head></head></span></body></div></html></a></div> = 1;

<custom-element attribute="value"></custom-element> = 0;

<hello attribute="haha!"></hello> = 0;

