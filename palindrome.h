/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   palindrome.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 13:21:58 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/27 21:20:38 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PALINDROME_H
# define PALINDROME_H

# include <unistd.h>
# include <stdio.h>

int		ft_strlen(char *str);
void	ft_loop(char *str);
void	ft_printstr(char *str, int i, int j);
int		ft_check(char *str, int i, int j);

#endif