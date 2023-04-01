/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:57:23 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/01 20:55:43 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstfront(t_lst **lst, t_lst *new)
{
	t_lst	*s1;

	s1 = lst[0];
	lst[0] = new;
	lst[0]->next = s1;
}

void	ft_push_a(t_lst *a, t_lst *b)
{
	ft_lstfront(&a, b);
	b = b->next;
	ft_printf("pa\n");
}

void	ft_push_b(t_lst *a, t_lst **b)
{
	if (b[0] == NULL)
		b[0] = lstnew(0);
	ft_lstfront(b, a);
	a = a->next;
	ft_printf("pb\n");
}