/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:01:16 by akhmetsha         #+#    #+#             */
/*   Updated: 2019/08/07 16:06:10 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_getmin.h"

void            terminate(char *error_message)
{
	ft_putendl(error_message);
	exit(1);
}

static void      parse_operation(t_head *head)
{
	t_stack *pop_stack;
	char    *line;
	int     result;
	
	result = 0;
	while ((result = get_next_line(0, &line)) > 0)
	{
		if (!ft_strcmp(line, "push"))
		{
			free(line);
			if ((result = get_next_line(0, &line)) > 0)
			{
				if (!ft_isint(line, 0))
					terminate(ERR_WRVALUE);
				else
					push(ft_atoi(line), head);
			}
		}
		else if (!ft_strcmp(line, "pop"))
			pop_stack = pop(head);
		else if (!ft_strcmp(line, "peek"))
			peek(head);
		else if (!ft_strcmp(line, "getmin"))
			get_min(head);
		else if (!ft_strcmp(line, "exit"))
			terminate(CODE_EXIT);
		else
			terminate(ERR_WROP);
		free(line);
	}
}

static void     show_man(void)
{
	ft_putendl("\e[32mGetmin O(1)\e[0m");
	ft_putendl("Test implementation of getmin function of O(1) running time \
requiring O(n) memory to operate.");
	ft_putendl("Instructions:");
	ft_putendl(" - type \"push\" and then the value on the new line to place \
a new element containing the specified value on the top of the stack;");
	ft_putendl(" - \"pop\" to remove the top element from the stack;");
	ft_putendl(" - \"peek\" to display the value of the top element;");
	ft_putendl(" - \"getmin\" to display the minimal value contained \
in the stack;");
	ft_putendl(" - \"exit\" to terminate the program.");
	ft_putendl("\e[31mPlease note: invalid input will lead to the program \
being terminated.\e[0m");
	ft_putendl("\e[90mVersion 0.1 (C) Timur Akhmetshin, 2019. \
Licensed under GNU General Public License v3.\e[0m");
}

int             main(void)
{
	t_head  head;

	head.main = NULL;
	head.aux = NULL;
	show_man();
	parse_operation(&head);
	return (0);
}