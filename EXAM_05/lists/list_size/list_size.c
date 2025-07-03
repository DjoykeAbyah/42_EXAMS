/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_size.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 22:30:12 by djoyke        #+#    #+#                 */
/*   Updated: 2025/07/03 22:33:12 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// - begin_list: a pointer to the beginning of the list.
// - The function should return the number of nodes in the list.

int     ft_list_size(t_list *begin_list) {
	int i = 0;
	
	while (begin_list) {
		begin_list = begin_list->next;
		i++;
	}
	return i;
	
}