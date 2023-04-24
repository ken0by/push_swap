/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:17:40 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/23 17:03:41 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	nbr_check(t_lst *a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a;
	while (aux)
	{
		aux1 = aux->next;
		while (aux1)
		{
			if (aux1->n == aux->n)
				return (1);
			aux1 = aux1->next;
		}
		aux = aux->next;
	}
	return (0);
}
