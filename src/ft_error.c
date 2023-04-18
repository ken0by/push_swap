/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:24:23 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/18 17:34:54 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (0);
}

t_lst	*ft_free_lst(t_lst *a)
{
	t_lst	*aux;

	while (a)
	{
		aux = a->next;
		a->n = 0;
		a->next = NULL;
		a = aux;
	}
	free (a);
	a = NULL;
	return (a);
}
