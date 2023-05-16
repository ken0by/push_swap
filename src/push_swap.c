/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:00 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/16 17:05:57 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_comp_arr(char **s, int j, int i)
{
	if ((s[j][i] >= '0' && s[j][i] <= '9')
		|| s[j][i] == ' ' || s[j][i] == '-' || s[j][i] == '+')
		i++;
	else
		return (0);
	return (i);
}

static int	ft_check_maxmin(char **s)
{
	int		i;
	int		j;

	i = 1;
	while (s[i])
	{
		j = ft_strlen_no_s(s[i]);
		if (j == 10 || (j == 11 && s[i][0] == '-'))
		{
			if (s[i][0] == '-')
			{
				if (ft_strncmp(s[i], ft_itoa(-2147483648), 11) > 0)
					return (0);
			}
			else
				if (ft_strncmp(s[i], ft_itoa(2147483647), 10) > 0)
					return (0);
		}
		if (j > 11)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_neg_p(char *s, int i, int neg, int p)
{
	if (s[i] == '-')
		neg++;
	if (s[i] == '+')
		p++;
	if ((s[i] == '-' || s[i] == '+') && i != 0 && s[i - 1] != ' ')
		s[i] = 'p';
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
			ft_neg_p(s[j], i, neg, p);
			i = ft_comp_arr(s, j, i);
			if (i == 0 || neg > 1 || p > 1)
				return (0);
			if (s[j][i] == ' ')
			{
				neg = 0;
				p = 0;
			}
		}
		j--;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac <= 1)
		return (0);
	if (ac == 2)
		if (ft_check_nbr(av[1]) >= 1 && ft_check_space(av, (ac - 1)) == 0)
			return (0);
	a = NULL;
	b = NULL;
	if (ft_comp(av, (ac - 1)) == 0 || ft_check_maxmin(av) == 0)
		return (ft_error());
	a = fill_lst(a, av, ac);
	if (!a)
		return (ft_error());
	if (ft_check_a(&a) == 0)
		return (0);
	if (ac == 2)
		ft_conditions(&a, &b, ft_strlen_nbr(av[1]) + 1);
	else
		ft_conditions(&a, &b, ac);
	ft_free_lst(&a);
	return (0);
}
