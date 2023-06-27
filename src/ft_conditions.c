/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:59:01 by rofuente          #+#    #+#             */
/*   Updated: 2023/06/27 11:14:35 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_conditions(t_lst **a, t_lst **b, int ac)
{
	if (ac == 4)
		*a = ft_exception_3(a, b);
	else if (ac == 6)
		*a = ft_exception(a, b);
	else if (ac > 2 && ac <= 41)
		*a = ft_swap(a, b);
	else
		*a = ft_radix(a, b);
}

int	ft_space_check(char *s)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (s[++i])
		if (s[i] == ' ')
			k++;
	return (k);
}

static int	ft_cmpnbr(char *s)
{
	int	i;

	i = ft_strlen_no_s(s);
	if (i == 10 || (i == 11 && s[0] == '-'))
	{
		if (s[0] == '-')
		{
			if (ft_strncmp(s, ft_itoa(INT_MIN), 11) > 0)
				return (free(s), 0);
		}
		else
			if (ft_strncmp(s, ft_itoa(INT_MAX), 10) > 0)
				return (free(s), 0);
	}
	if (i > 11 || (i == 11 && s[0] != '-'))
		return (free(s), 0);
	return (free(s), 1);
}

static int	ft_skip_space(char *s, int i, int k)
{
	if (k == 0)
	{
		while (s[i] == ' ' && s[i + 1] == ' ')
				i++;
		return (0);
	}
	if (k == 1)
	{
		s[i] = '\0';
		if (!ft_cmpnbr(s))
			return (0);
	}
	return (1);
}

int	check_mm(char *s)
{
	int		i;
	int		k;
	char	*aux;

	i = -1;
	k = 0;
	aux = malloc(sizeof(char));
	while (s[++i])
	{
		if (s[i] == ' ')
		{
			aux[i] = '\0';
			if (!ft_cmpnbr(aux))
				return (0);
			aux = malloc(sizeof(char));
			k = ft_skip_space(s, i, 0);
		}
		else
			aux[k++] = s[i];
	}
	if (!ft_skip_space(aux, i, 1))
		return (0);
	return (1);
}
