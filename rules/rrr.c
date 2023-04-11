/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:04:34 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/11 13:28:20 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rrotate_a(t_lst *a)
{
	t_lst	*aux;
	t_lst	*aux1;
	t_lst	*aux2;

	aux = lstlast(a);
	aux1 = a;
	while (aux1)
	{
		aux2 = aux1->next;
		if (aux2->n == aux->n)
			break ;
		aux1 = aux1->next;
	}
	aux1->next = NULL;
	ft_lstfront(&a, aux);
}

void	ft_rrotate_b(t_lst *b)
{
	t_lst	*aux;
	t_lst	*aux1;
	t_lst	*aux2;

	aux = lstlast(b);
	aux1 = b;
	while (aux1)
	{
		aux2 = aux1->next;
		if (aux2->n == aux->n)
			break ;
		aux1 = aux1->next;
	}
	aux1->next = NULL;
	ft_lstfront(&b, aux);
}

void	ft_rrotate_r(t_lst *a, t_lst *b)
{
	ft_rrotate_a(a);
	ft_rrotate_b(b);
}
