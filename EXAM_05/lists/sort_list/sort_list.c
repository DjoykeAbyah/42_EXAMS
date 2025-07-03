/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 22:55:57 by djoyke        #+#    #+#                 */
/*   Updated: 2025/07/03 23:02:25 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// - lst: a pointer to the beginning of the list.
// - cmp: a comparison function that returns 1 if the order is correct, or 0 if the elements must be swapped.

t_list  *sort_list(t_list *lst, int (*cmp)(int, int)) {

	int temp = NULL;
	t_list *head = lst;

	if (!lst)
		return (NULL);
	
	while (lst && lst->next) {
		if ((*cmp)(lst->data, lst->next->data) == 0) {
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = head; //reset to start to loop again
		}
		else
			lst = lst->next;
	}
	return (head);
}