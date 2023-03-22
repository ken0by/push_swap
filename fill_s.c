
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:36:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/22 17:37:51 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len(char **a)
{
	int		i;
	int		j;
	int		k;

	j = 1;
	k = 0;
	while (a[j])
	{
		i = 0;
		while (a[j][i])
		{
			if (a[j][i] >= '0' && a[j][i] <= '9')
				k++;
			if (a[j][i] == '-')
				k++;
			i++;
		}
		j++;
	}
	return (k);
}

static void	if_neg(char *a, int n, char *s)
{
	int	i;

	i = 0;
	while (a[n])
	{
		if (a[n] == '-')
			s[i] = '-';
		if (a[n] >= '0' && a[n] <= '9')
			s[i] = a[n];
		i++;
		n++;
	}
	s[i] = '\0';
}

char	**fill_s(char **a)
{
	int		i;
	int		j;
	int		k;
	char	**s;

	s = NULL;
	*s = malloc(sizeof(char *) * len(a));
	if (!s)
		return (NULL);
	j = 1;
	k = 0;
	while (a[j])
	{
		i = 0;
		while (a[j][i])
		{
			if (a[j][i] >= '0' && a[j][i] <= '9')
				s[k++] = &a[j][i];
			if (a[j][i] == '-')
				if_neg(a[j], i, s[k]);
			i++;
		}
		j++;
	}
	s[k] = NULL;
	return (s);
}
