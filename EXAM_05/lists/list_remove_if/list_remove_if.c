/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_remove_if.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 21:57:13 by djoyke        #+#    #+#                 */
/*   Updated: 2025/07/03 22:32:53 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// - begin_list: a pointer to the beginning of the list.
// - data_ref: a reference value to compare each node's data against.
// - cmp: a function that takes two void* arguments and returns 0 if they are considered equal.

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) {
	t_list *curr;
	t_list *next;
	t_list *prev;

	if (!begin_list || !*begin_list) //why?
		return;

	curr = *begin_list;
	prev = NULL;

	while (curr) {
		next = curr->next;
		if ((*cmp) (curr->data, data_ref) == 0) {
			if (prev == NULL) {
				*begin_list = next;
			}
			else
				prev->next = next;
			free(curr);
		}
		else
			prev = curr;
		curr = curr->next;
	}
}


