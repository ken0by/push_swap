/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:30:40 by rodro             #+#    #+#             */
/*   Updated: 2023/03/30 16:44:08 by rodro            ###   ########.fr       */
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
			break;
		aux1 = aux->next;
		if (aux->n != aux1->n)
			return (0);
		aux = aux->next;
	}
	return (1);
}
