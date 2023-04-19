/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:28:32 by rodro             #+#    #+#             */
/*   Updated: 2023/04/19 19:13:39 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_itob(int n)
{
	//int	bit[32];
	int	i;

	i = 0;
	while (n)
	{
		n = n >> 1;
		i++;
	}
	return (i);
}

static void	ft_plst(t_lst *a)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a;
	while (aux)
	{
		aux1 = a;
		while (aux1)
		{
			if (aux->n > aux1->n)
				aux->p += 1;
			aux1 = aux1->next;
		}
		aux = aux->next;
	}
}

static int	ft_max_size(t_lst *a)
{
	t_lst	*aux;
	t_lst	*max;

	aux = a->next;
	max = a;
	while (aux)
	{
		if (aux->p > max->p)
			max = aux;
		aux = aux->next;
	}

	return (ft_itob(max->p));
}

static void	ft_pr(t_lst **a, t_lst **b, int i)
{
	if (((a[0]->p)>>i & 1) == 0)
	{
		ft_push_b(a[0], b);
		a[0] = a[0]->next;
	}
	else
		ft_rotate_a(a[0], 0);
}

t_lst	*ft_radix(t_lst **a, t_lst **b)
{
	int	i;
	int	j;
	int	max;
	int	max_size;

	ft_plst(*a);
	max = lstsize(*a);
	max_size = ft_max_size(*a);
	i = 0;
	while (i < max_size)
	{
		j = 0;
		while (j < max)
		{
			ft_pr(a, b, i);
			j++;
		}
		while (*b)
		{
			ft_push_a(a, *b);
			b[0] = b[0]->next;
		}
		i++;
	}
	return (*a);
}
