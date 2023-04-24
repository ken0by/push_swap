/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:42 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/24 15:59:46 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lstsize(t_lst *a)
{
	int		i;
	t_lst	*aux;

	i = 0;
	aux = a;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	ft_swap_a(t_lst *a, t_lst *aux)
{
	t_lst	*aux2;

	aux2 = lstnew(0);
	aux2->n = aux->n;
	aux->n = a->n;
	a->n = aux2->n;
	free (aux2);
}

void	ft_swap_b(t_lst *b, t_lst *aux)
{
	t_lst	*aux2;

	aux2 = lstnew(0);
	aux2->n = aux->n;
	aux->n = b->n;
	b->n = aux2->n;
	free (aux2);
}

void	ft_swap_s(t_lst *a, t_lst *b)
{
	t_lst	*aux;

	aux = a->next;
	ft_swap_a(a, aux);
	aux = b->next;
	ft_swap_b(b, aux);
}
