Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline
if the expression is correctly bracketed, otherwise it prints "Error" followed by
a newline.
Symbols considered as 'brackets' are brackets '(' and ')', square brackets '['
and ']'and braces '{' and '}'. Every other symbols are simply ignored.
An opening bracket must always be closed by the good closing bracket in the
correct order. A string which not contains any bracket is considered as a
correctly bracketed string.
If there is no arguments, the program must print only a newline.
Examples :
$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
$> '{ [ ( 0 + 0 )( 1 + 1 ) ] ( 3* ( -1 ) ) { ( ) } }'

{[(     
	
string [1000]

int len = 3

open bracket = ++;
close bracket = --;

while (str)
if i = 0 with close bracket
	error
check all indezes on 3 kinds brackets
	if open that add
	i++;
	len++;
	if close call function returns (1)
	len --



list = {[(

compare to
the last in the list (index[l-1])
function returns 0 means error
if not same then 
ERROR

{[())(](())){()}}

function(char list[l-1], char close) 
	if (list[l-1] == "(")
		if (close != ")")
			return (1);
	else if (list[l-1] == "[")
		if (close != "]")
			return (1);
	else if (list[l-1] == "{")
		if (close != "}")
			return (1);
	return (0);