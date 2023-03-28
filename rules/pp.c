/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:52:51 by rodro             #+#    #+#             */
/*   Updated: 2023/03/28 19:11:42 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_lstfront(t_lst **lst, t_lst *new)
{
	t_lst	*s1;

	s1 = lst[0];
	lst[0] = new;
	lst[0]->next = s1;
}

void	ft_push_a(t_lst *a, t_lst *b)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a;
	aux1 = b;
	b = b->next;
	ft_lstfront(&aux, aux1);
	ft_printf("pa\n");
}

void	ft_push_b(t_lst *a, t_lst *b)
{
	t_lst	*aux;

	aux = a->next;
	ft_lstfront(&b, a);
	lstdelone(a);
	a = aux;
	ft_printf("pb\n");
}
