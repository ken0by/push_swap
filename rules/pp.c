/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:57:23 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/20 14:27:14 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_lstfront(t_lst **lst, t_lst *new)
{
	t_lst *s1;

	s1 = lst[0];
	lst[0] = new;
	lst[0]->next = s1;
}


void ft_push_a(t_lst **a, t_lst *b)
{
	ft_lstfront(a, b);
	ft_printf("pa\n");
}

void ft_push_b(t_lst *a, t_lst **b)
{
		if (!b[0])
		{
			*b = a;
			(*b)->next = NULL;
		}
		else
			ft_lstfront(b, a);
	ft_printf("pb\n");
}
