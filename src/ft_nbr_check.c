/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:17:40 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/09 12:52:05 by rofuente         ###   ########.fr       */
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
			if (aux1->p == aux->p)
				return (1);
			aux1 = aux1->next;
		}
		aux = aux->next;
	}
	return (0);
}

int	ft_check_nbr(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	ft_strlen_nbr(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			k++;
		i++;
	}
	return (k);
}
