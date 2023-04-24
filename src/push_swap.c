/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:00 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/24 18:13:48 by rofuente         ###   ########.fr       */
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

static int	ft_cmp(char *s)
{
	char	*aux;

	if (s[0] == '-')
	{
		aux = ft_itoa(INT_MIN);
		if (ft_strncmp(s, aux, 11) > 0)
		{
			free (aux);
			return (0);
		}
	}
	else
	{
		aux = ft_itoa(INT_MAX);
		if (ft_strncmp(s, aux, 10) > 0)
		{
			free (aux);
			return (0);
		}
	}
	return (1);
}

static int	ft_check_maxmin(char **s)
{
	int		i;
	int		j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
			j++;
		if (j == 10 || (j == 11 && s[i][0] == '-'))
		{
			if (ft_cmp(s[i]) == 0)
				return (0);
		}
		else if (j >= 11)
			return (0);
		i++;
	}
	return (1);
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
				return (0);
		}
		if (neg > 1 || p > 1)
			return (0);
		j--;
	}
	return (1);
}
void ft_leaks(void)
{
	system("leaks push_swap");
}
int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	atexit(ft_leaks);
	if (ac <= 2)
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
	ft_conditions(&a, &b, ac);
	return (0);
}

/* LOS LEAKS QUE ME DAN SON LOS NUMEROS QUE PASO COMO PARAMETRO, PERO CON LOS INT MIN/MAX CUANO DA ERROR
TAMBIEN DAN LEAKS POR QUE NO SE LIBERAN NS XQ Y CREO QUE YA */
