/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:00 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/14 12:50:18 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_error(void)
{
	ft_printf("Error\n");
	return (0);
}

static int	ft_comp_arr(char **s, int j, int i)
{
	if ((s[j][i] >= '0' && s[j][i] <= '9')
		|| s[j][i] == ' ' || s[j][i] == '-' || s[j][i] == '+')
		i++;
	else
		return (0);
	return (i);
}

static int	ft_comp(char **s, int j)
{
	int	i;
	int	neg;
	int	p;

	while (j > 0)
	{
		neg = 0;
		p = 0;
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == '-')
				neg++;
			if (s[j][i] == '+')
				p++;
			i = ft_comp_arr(s, j, i);
			if (i == 0)
				return (ft_error());
		}
		if (neg > 1 || p > 1)
			return (ft_error());
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
	if (ft_comp(av, (ac - 1)) == 0)
		return (0);
	a = fill_lst(a, av, ac);
	if (!a)
		return (0);
	ft_swap(a, b);
	return (0);
}
