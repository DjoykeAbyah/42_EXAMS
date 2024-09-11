#include <unistd.h>

int bracket_compare(char a, char b) {
	if ((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']'))
		return (0);
	else
		return (1);
}

int search_bracket_pair(char *str) {
	int i = 0;
	int top = 0;
	int stack[4096];

	while (str[i]) {
		if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
			stack[top] = str[i];
			top++;
		}
		if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
			if (top == 0 || bracket_compare(stack[top - 1], str[i]) == 1)
				return (1);
			top--;
		}
		i++;
	}
	if (top != 0)
		return (1);
	return (0);
}

int main(int argc, char **argv) {
	int i = 1;

	if (argc == 1)
		return (write(1, "\n", 1));
	while (argv[i]) {
		if (search_bracket_pair(argv[i]) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}