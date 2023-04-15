/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:04:34 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/15 21:01:53 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_rrotate_a(t_lst *a, int i)
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
	if (i == 0)
		ft_printf("rra\n");
	return (a);
}

t_lst	*ft_rrotate_b(t_lst *b, int i)
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
	if (i == 0)
		ft_printf("rrb\n");
	return (b);
}

void	ft_rrotate_r(t_lst *a, t_lst *b)
{
	ft_rrotate_a(a, 1);
	ft_rrotate_b(b, 1);
	ft_printf("rrr\n");
}
