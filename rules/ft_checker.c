/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:12:45 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/17 20:04:27 by rofuente         ###   ########.fr       */
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
