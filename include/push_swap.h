/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:59:06 by rofuente          #+#    #+#             */
/*   Updated: 2023/04/01 20:56:15 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

/* NO SE SI IMPLEMENTAR LA LIBFT O NO */
# include "../libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/gnl/include/get_next_line.h"

typedef struct t_lst
{
	int				n;
	int				p;
	struct t_lst	*next;
}	t_lst;

/* FILL_LST.C */
t_lst	*fill_lst(t_lst *a, char **b, int x);
t_lst	*lstnew(int content);
int		ft_count(t_lst *a);
void	lstadd_back(t_lst **a, t_lst *new);

/* SS.C */
void	lstdelone(t_lst *lst);
void	ft_swap_a(t_lst *a, t_lst *aux);
void	ft_swap_b(t_lst *a, t_lst *b);
void	ft_swap_s(t_lst *a, t_lst *b);

/* PP.C */
void	ft_push_a(t_lst *a, t_lst *b);
void	ft_push_b(t_lst *a, t_lst **b);
void	ft_lstfront(t_lst **lst, t_lst *new);

/* ORD.C */
void	ft_swap(t_lst *a, t_lst *b);

/* FT_CHECK.C */
int		ft_check(t_lst *a);

#endif
