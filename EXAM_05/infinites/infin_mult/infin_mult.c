/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 23:14:15 by djoyke        #+#    #+#                 */
/*   Updated: 2025/07/04 00:30:26 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"

int ft_strlen(char *str) {
	int len = 0;
	while (str[len]) 
		len++;
	return (len);
}

int is_negative(char *str) {
	if (str[0] == '-')
		return 1;
	else
		return 0;
}

char *strip_negative(char *str) {
	return str + 1;
}

int *malloc_result(int size){
	int *result_array = malloc(size * sizeof(int));
	if (!result_array)
		return NULL;
	return result_array;
}

void print_digit(int *result, int negative, int len) {
	int i = 0;
	int started = 0;
	char c;
	
	if (negative == 1) 
		write(1, "-", 1);
	
	while (i < len) {
		if (result[i] == 0 && started == 0)
			i++;
		else {
			started = 1;
			c = result[i] + '0'; //write char so convert
			write(1, &c, 1);
			i++;
		}
	}
	if (started == 0)
		write(1, "0", 1);
	write(1, "\n", 1);
}

void multiply(char *str_a, char *str_b, int *result_array) {

	int len_a= ft_strlen(str_a);
	int len_b= ft_strlen(str_b);

	for (int idx_a = len_a - 1; idx_a >=0; idx_a--) {
		for (int idx_b = len_b - 1; idx_b >=0; idx_b--) {
			int product = ((str_a[idx_a] - '0') * (str_b[idx_b]- '0'));
			
			int carry_pos = idx_a + idx_b; // for overflow
			int digit_pos = idx_a + idx_b + 1; //where current digit lands
			
			int sum = result_array[digit_pos] + product; //calculate with what is already there
			result_array[digit_pos] = sum % 10;
			result_array[carry_pos] += sum / 10; //accumulate carry
		}
	}
}

void infinite_mult(char *str_a, char *str_b) {
	int neg = 0;
		 		
	if (is_negative(str_a)) {
		neg = 1;
		str_a = strip_negative(str_a);
	}
	if (is_negative(str_b)) {
		if (neg == 1)
			neg = 0;
		else
			neg = 1;
		str_b = strip_negative(str_b);
	}
	
	int total_size_array = ft_strlen(str_a) + ft_strlen(str_b);
	int *result_array = malloc_result(total_size_array);
	multiply(str_a, str_b, result_array);
	print_digit(result_array, neg, total_size_array);
}

int main(int argc, char **argv) {

	if (argc == 3) {
		infinite_mult(argv[1], argv[2]);
	}
	return 0;
}