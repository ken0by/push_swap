/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:12:45 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/24 16:00:05 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_pa(t_lst **a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a[0];
	while (aux)
	{
		if (aux->next)
			aux1 = aux->next;
		else
			return (0);
		if (aux->n > aux1->n)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	ft_pa(t_lst **a, t_lst **b)
{
	t_lst	*aux;

	aux = (*b)->next;
	ft_push_a(a, *b);
	*b = aux;
}

t_lst	*ft_iter(t_lst **a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = *a;
	while (aux)
	{
		if (aux->next)
			aux1 = aux->next;
		else
			break ;
		if (aux->n > aux1->n)
			break ;
		aux = aux->next;
	}
	return (aux);
}
