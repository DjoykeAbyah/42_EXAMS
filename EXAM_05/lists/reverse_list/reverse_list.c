/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 22:33:29 by djoyke        #+#    #+#                 */
/*   Updated: 2025/07/03 22:52:47 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list  *reverse_list(t_list *lst) {
	t_list *prev = NULL;
	t_list *curr = lst;
	t_list *next;

	// save, flip, move
	// save next, flip the pointer, move both pointers forward)
	
	while (curr) {
		next = curr->next; 	// 1. save
		curr->next = prev; 	// 2. flip
		prev = curr; 		// 3. move prev
		curr = next; 		// 4. move curr
	}
	return prev;
}