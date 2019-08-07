/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:21:38 by akhmetsha         #+#    #+#             */
/*   Updated: 2019/08/07 15:49:29 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_getmin.h"

void        push(int x, t_head *head)
{
	t_stack     *new_main;
	t_stack     *new_aux;

	if (!(new_main = (t_stack *)ft_memalloc(sizeof(t_stack))) || \
		!(new_aux = (t_stack *)ft_memalloc(sizeof(t_stack))))
		terminate(ERR_MEMALLOC);
	if (head->main == NULL || head->aux == NULL)
	{
		new_main->value = x;
		head->main = new_main;
		new_aux->value = x;
		head->aux = new_aux;
	}
	else
	{
		new_main->value = x;
		new_main->next = head->main;
		head->main = new_main;
		if (x <= head->aux->value)
			new_aux->value = x;
		else
			new_aux->value = head->aux->value;
		new_aux->next = head->aux;
		head->aux = new_aux;
	}
}

t_stack     *pop(t_head *head)
{
	t_stack *tmp_main;
	t_stack *tmp_aux;
	
	tmp_main = NULL;
	tmp_aux = NULL;
	if (head->main == NULL || head->aux == NULL)
		terminate(ERR_ESTACK);
	else
	{
		tmp_main = head->main;
		tmp_aux = head->aux;
		head->main = head->main->next;
		head->aux = head->aux->next;
		free(tmp_aux);
	}
	return (tmp_main);
}

void        peek(t_head *head)
{
	if (head->main == NULL || head->aux == NULL)
		terminate(ERR_ESTACK);
	else
	{
		ft_putstr("Top element value: ");
		ft_putnbr(head->main->value);
		ft_putchar('\n');
	}
}

void        get_min(t_head *head)
{
	if (head->main == NULL || head->aux == NULL)
		terminate(ERR_ESTACK);
	else
	{
		ft_putstr("Minimal value: ");
		ft_putnbr(head->aux->value);
		ft_putchar('\n');
	}
}