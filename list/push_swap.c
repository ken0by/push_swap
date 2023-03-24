/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:00 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/24 17:47:37 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	comp(char **s, int ac)
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
				printf("Error\n");
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
	lst *aux;
	if (ac < 2)
	{
		printf("Error\n");
		return (0);
	}
	if (comp(av, ac) == 0)
		return(0);
	a = lstnew(0);
	a = fill_lst(a, av, ac);
	aux = a;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}

	return (0);
}
