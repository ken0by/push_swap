/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:00 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/27 17:19:32 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void ft_ord(lst *a, lst *b)
{
	lst	*aux;
	lst	*aux1;
	lst	*aux2;
	lst	*aux3;

	aux = a;
	aux1 = b;
	while (aux)
	{
		ft_printf("1\n");
		aux2 = aux->next;
		aux3 = aux2->next;
		if (aux->n > aux2->n && aux->n > aux3->n && ft_count(a) > 1)
			ft_swap_s(a, b);
		else if (aux->n > aux2->n && ft_count(a) > 1)
			ft_swap_a(aux, aux2);
		else if (aux->n > aux3->n && aux2->n > aux3->n && ft_count(a) > 1)
			ft_swap_b(aux, aux1);

		aux = aux->next;
	}
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
			if (s[j][i] < '0' || s[j][i] > '9' || s[j][i] != ' ' || s[j][i] != '-' || s[j][i] != '+')
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
	lst	*a;
	lst	*b;
	lst *aux;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	if (ft_comp(av, ac) == 0)
		return(0);
	a = fill_lst(a, av, ac);
	ft_ord(a, b);
	aux = a;
	while (aux)
	{
		ft_printf("%d\n", aux->n);
		aux = aux->next;
	}
	return (0);
}
