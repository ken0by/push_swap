/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:00 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/01 20:31:25 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
static void ft_ord(t_lst *a, t_lst *b);

static void ft_ord1(t_lst *a, t_lst *b)
{
	t_lst	*aux;
	t_lst	*aux1;
	int		flag;

	aux = a;
	aux1 = aux->next;
	flag = 0;
	while (aux)
	{
		if (aux->n > aux1->n && ft_count(aux) > 0)
		{
			ft_push_b(a, b, aux);
			flag = 1;
		}
		if (flag == 1)
			break ;
		aux = aux1;
		aux1 = aux1->next;
	}
	if (flag == 1)
		ft_ord(a, b);
	else if (flag == 0)
	{
		aux = a;
		aux1 = b;
		while (ft_count(aux1) > 0)
		{
			ft_push_a(aux, aux1);
			aux1 = aux1->next;
		}
	}
}

static void ft_ord(t_lst *a, t_lst *b)
{
	t_lst *aux;
	t_lst *aux1;
	t_lst *aux2;
	t_lst *aux3;

	aux = a;
	aux1 = b;
	aux2 = NULL;
	aux3 = NULL;
	if (aux->next)
		aux2 = aux->next;
	if (aux2->next)
		aux3 = aux2->next;
	if (aux->n > aux3->n && aux2->n > aux3->n && ft_count(a) > 1)
	{
		ft_swap_s(a, b);
		ft_printf("ss\n");
	}
	if (aux->n > aux2->n && ft_count(a) > 1)
	{
		ft_swap_a(aux, aux2);
		ft_printf("sa\n");
	}
	if (aux->n > aux2->n && aux2->n > aux3->n && ft_count(a) > 1)
	{
		ft_swap_b(aux, aux1);
		ft_printf("sb\n");
	}
	else
		ft_ord1(a, b);
} */

static int ft_comp(char **s, int ac)
{
	int	i;
	int	j;
	int	neg;
	int	p;

	j = ac - 1;
	while (j < 0)
	{
		neg = 0;
		p = 0;
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] < '0' || s[j][i] > '9' || s[j][i] != ' ' || s[j][i] != '-' || s[j][i] != '+')
			{
				ft_printf("Error\n");
				return (0);
			}
			if (s[j][i] == '-')
				neg++;
			if (s[j][i] == '+')
				p++;
			i++;
		}
		if (neg > 1 || p > 1)
		{
			ft_printf("Error\n");
			return (0);
		}
		j--;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_lst *a;
	t_lst *b;

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
	ft_swap(a, b);
	return (0);
}
