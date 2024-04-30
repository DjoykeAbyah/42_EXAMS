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

$> ./html_anglebrackets '<htm><bla><body></body><newbody></newbody></bla></html>' | cat -e
OK$
$> ./html_anglebrackets '<bla gvngf></html><bla></html>' | cat -e
Error$
$> ./html_anglebrackets '' '<html><bla></html><html></bla></html>' | cat -e
OK$
OK$
$> ./html_anglebrackets | cat -e
$
$> ./html_anglebrackets '<html><img></html><img><html><img></html>' | cat -e
OK$

stack until closing is found, compare with last open, (either delete when linked list or --)




// bool tagvalidator(char *str1) 
// {
//     char stack[100];
// 	char tag[100];
// 	char end[100];
//     int top = -1;
//     int i = 0;
	
//     if (!str1)
// 	{
// 		write(1, "no string\n", 11);
// 		return (false);
// 	}
// 	if (str1[0] != '<')
// 	{
// 		return (true);
// 	}
//     while (str1[i] != '\0') 
// 	{
//         if (str1[i] == '<' && str1[i + 1] != '/') 
// 		{
//             int j = i + 1;
//             while (str1[j] != '\0' && str1[j] != '>') 
// 			{
//                 j++;
//             }
//             if (str1[j] == '>') 
// 			{
//                 strncpy(tag, &str1[i], j - i + 1);
//                 tag[j - i + 1] = '\0';
//                 if (tag[ft_strlen(tag) - 2] != '/') 
// 				{
// 					top++;
//                     ft_strcpy(&stack[top], tag);
//                 }
//                 i = j;
//             }
//         } 
// 		else if (str1[i] == '<' && str1[i + 1] == '/') 
// 		{
//             int j = i + 2;
//             while (str1[j] != '\0' && str1[j] != '>') 
// 			{
//                 j++;
//             }
//             if (str1[j] == '>') 
// 			{
//                 strncpy(end, str1 + i, j - i + 1);
//                 end[j - i + 1] = '\0';
// 				int k = 0;
//                 if (top == -1 || strcmp(&stack[top], &end[k + 2]) != 0) 
// 				{
// 					return (false);
//                 }
//                 top--;
//                 i = j;
//             }
//         }
//         i++;
//     }
//     return top == -1;
// }