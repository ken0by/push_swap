/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:56:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/23 17:42:30 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ord(int n, char **a, char **b)
{
	int		j;

	j = 0;
	while (a[j] && j < n)
	{

		if ((a[j] > a[j + 1]) && n > 1 && a[j + 1] != '\0')
			sa(a, j);
		if (a[j] > a[j + 2] && a[j + 1] > a[j + 2] && n > 1 && a[j + 1] != '\0')
			sb(a, b);
		if ((a[j] > a[j + 1]) && a[j] > a[j + 2] && a[j + 1] > a[j + 2] && n > 1 && a[j + 1] != '\0')
			ss(a, b, n);
		else
			j++;
	}
}

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

int main(int ac, char **av)
{
	char	**a;
	char	**b;

	/* if (ac < 2)
	{
		printf("Error\n");
		return (0);
	} */
	printf("1\n");
	if (comp(av, ac) == 0)
		return (0);
	a = NULL;
	a = fill_s(av);
	b = NULL;
	ord(ac, a, b);
	return (0);
}

/* HAY QUE CAMBIAR TODOS LOS PRINTF DEL PROYECTO POR MI FT_PRINTF */
/* DA EL SEGMENTATION FAULT EN FILL EN TEORIA */
