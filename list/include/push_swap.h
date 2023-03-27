/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:59:06 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/27 17:19:53 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

/* NO SE SI IMPLEMENTAR LA LIBFT O NO */
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"

typedef struct caca
{
	int			n;
	int			p;
	struct caca	*next;
}	lst;

/* FILL_LST.C */
lst		*fill_lst(lst *a, char **b, int	x);
lst		*lstnew(int	content);
int		ft_count(lst *a);
void	lstadd_back(lst **a, lst *new);
/* SS.C */
void	ft_swap_a(lst *a, lst *aux);
void	ft_swap_b(lst *a, lst *b);
void	ft_swap_s(lst *a, lst *b);

#endif
