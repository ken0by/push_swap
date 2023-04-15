/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:42 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/15 23:10:49 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void lstdelone(t_lst *lst)
{
	if (!lst)
		return;
	lst->n = 0;
	free(lst);
	lst = 0;
}

void ft_swap_a(t_lst *a, t_lst *aux)
{
	t_lst *aux2;

	aux2 = lstnew(0);
	aux2->n = aux->n;
	aux->n = a->n;
	a->n = aux2->n;
}

void ft_swap_b(t_lst *b, t_lst *aux)
{
	t_lst *aux2;

	aux2 = lstnew(0);
	aux2->n = aux->n;
	aux->n = b->n;
	b->n = aux2->n;
}

void ft_swap_s(t_lst *a, t_lst *b)
{
	t_lst *aux;

	aux = a->next;
	ft_swap_a(a, aux);
	aux = b->next;
	ft_swap_b(b, aux);
}
