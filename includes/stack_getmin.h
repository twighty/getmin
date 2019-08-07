/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_getmin.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:03:51 by akhmetsha         #+#    #+#             */
/*   Updated: 2019/08/07 16:03:45 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define ERR_WRVALUE "Error: invalid value"
# define ERR_WROP "Error: invalid operation"
# define ERR_MEMALLOC "Error: could not allocate memory"
# define ERR_ESTACK "Error: could not perform the operation, the stack is empty"
# define CODE_EXIT "The program has been terminated by the user."

typedef struct      s_stack
{
	int             value;
	struct s_stack  *next;
}                   t_stack;

typedef struct      s_head
{
	t_stack         *main;
	t_stack         *aux;
}                   t_head;

/*
** operations.c
*/

void        push(int x, t_head *head);
t_stack     *pop(t_head *head);
void        peek(t_head *head);
void        get_min(t_head *head);

/*
** main.c 
*/

void        terminate(char *error_message);