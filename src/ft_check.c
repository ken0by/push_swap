/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:04:54 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/18 19:00:00 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check(t_lst *a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a;
	while (aux)
	{
		if (!aux->next)
			break ;
		aux1 = aux->next;
		if (aux->n != aux1->n)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	ft_no_argv(char *str)
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
	if (k == 0)
		return (1);
	return (0);
}
