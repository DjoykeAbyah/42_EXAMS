/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clone_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 20:46:41 by djoyke        #+#    #+#                 */
/*   Updated: 2025/07/03 21:04:37 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

s_node *make_node(int data) {
	
	struct s_node *new_node = malloc(sizeof(struct s_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->other = NULL;
	return new_node;
}

struct s_node *clone_list(struct s_node *node) {
	
	struct s_node head = *node;
	struct s_node *new_list = malloc(sizeof(struct s_node));

	while (node->next) {
		new_list = make_node(node->data);
		new_
	}
	
}