/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:24:23 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/16 16:46:58 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (i >= 0)
	{
		free (s[i]);
		i--;
	}
	free (s);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	ft_free_lst(t_lst **a)
{
	t_lst	*aux;

	while (*a)
	{
		aux = (*a)->next;
		free (*a);
		(*a) = aux;
	}
	(*a) = NULL;
}

t_lst	*ft_exception(t_lst **a, t_lst **b)
{
	t_lst	*aux;

	if ((*a)->p == 4)
		*a = ft_rotate_a(*a, 0);
	aux = ft_swap(a, b);
	*a = aux;
	return (*a);
}

t_lst	*ft_exception_3(t_lst **a, t_lst **b)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = (*a)->next;
	aux1 = aux->next;
	if ((*a)->p == 2 && aux->p == 1 && aux1->p == 0)
	{
		*a = ft_rotate_a(*a, 0);
		ft_swap_a(*a, (*a)->next);
		ft_printf("sa\n");
	}
	else if ((*a)->p == 0 && aux->p == 2 && aux1->p == 1)
	{
		*a = ft_rrotate_a(*a, 0);
		ft_swap_a(*a, (*a)->next);
		ft_printf("sa\n");
	}
	else
	{
		aux = ft_exception4(a);
		*a = aux;
		if (ft_check_a(a) == 1)
			*a = ft_swap(a, b);
	}
	return (*a);
}
