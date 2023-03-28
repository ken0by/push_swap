/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:00 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 17:05:15 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ord1(t_lst *a, t_lst *b)
{
	t_lst	*aux;
	t_lst	*aux1;

	aux = a;
	aux1 = b;
	ft_printf("Primero arregla la otra antes de empezar con esta\n");
}

static void	ft_ord(t_lst *a, t_lst *b)
{
	t_lst	*aux;
	t_lst	*aux1;
	t_lst	*aux2;
	t_lst	*aux3;

	aux = a;
	aux1 = b;
	while (aux)
	{
		if (aux->next)
			aux2 = aux->next;
		if (aux2->next)
			aux3 = aux2->next;
		ft_printf("1\n");
		if (aux->n > aux3->n && aux2->n > aux3->n && ft_count(a) > 1)
		{
			ft_swap_s(a, b);
			ft_printf("ss\n");
		}
		else if (aux->n > aux2->n && ft_count(a) > 1)
		{
			ft_swap_a(aux, aux2);
			ft_printf("sa\n");
		}
		else if (aux->n > aux2->n && aux2->n > aux3->n && ft_count(a) > 1)
		{
			ft_swap_b(aux, aux1);
			ft_printf("sb\n");
		}
		else
		{
			ft_printf("123\n");
			ft_ord1(a, b);
		}
		if ((aux->next == NULL) && aux1->next == NULL)
			break ;
		ft_printf("2\n");
		aux = aux->next;
		ft_printf("3\n");
	}
	ft_printf("cojones\n");
}

static int	ft_comp(char **s, int ac)
{
	int	i;
	int	j;

	j = ac - 1;
	while (j < 0)
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] < '0' || s[j][i] > '9' || s[j][i] != ' '
				|| s[j][i] != '-' || s[j][i] != '+')
			{
				ft_printf("Error\n");
				return (0);
			}
			i++;
		}
		j--;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	if (ft_comp(av, ac) == 0)
		return (0);
	a = fill_lst(a, av, ac);
	ft_ord(a, b);
	return (0);
}
