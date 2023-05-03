/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:59:06 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/03 17:10:09 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

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
t_lst	*lstlast(t_lst *a);

/* LST.C */
t_lst	*lstnew(int content);
void	lstadd_back(t_lst **a, t_lst *new);
t_lst	*lstlast(t_lst *a);

/* SS.C */
int		lstsize(t_lst *a);
void	ft_swap_a(t_lst *a, t_lst *aux);
void	ft_swap_b(t_lst *a, t_lst *b);
void	ft_swap_s(t_lst *a, t_lst *b);

/* PP.C */
void	ft_push_a(t_lst **a, t_lst *b);
void	ft_push_b(t_lst *a, t_lst **b);
void	ft_lstfront(t_lst **lst, t_lst *new);

/* RR.C */
t_lst	*ft_rotate_a(t_lst *a, int i);
t_lst	*ft_rotate_b(t_lst *b, int i);
void	ft_rotate_r(t_lst **a, t_lst **b);
t_lst	*ft_ra(t_lst **a, int i);

/* RRR.C */
t_lst	*ft_rrotate_a(t_lst *a, int i);
t_lst	*ft_rrotate_b(t_lst *b, int i);
void	ft_rrotate_r(t_lst **a, t_lst **b);

/* FT_MOVES.C */
t_lst	*ft_swap(t_lst **a, t_lst **b);
int		ft_check_revrot(t_lst **a, t_lst **b, t_lst *aux, t_lst *aux1);
int		ft_check_rotation(t_lst **a, t_lst **b, t_lst *aux, t_lst *aux1);
int		ft_check_push(t_lst **a, t_lst **b, t_lst *aux1, int flag);
int		ft_check_a(t_lst **a);

/* FT_MOVES2.C */
int		ft_ss(int flag, t_lst *aux, t_lst **a, t_lst **b);
t_lst	*ft_exception4(t_lst **a);
void	ft_check_moves(t_lst **a, t_lst **b, t_lst *aux, int flag);

/* FT_CHECKER.C */
int		ft_check_pa(t_lst **a);
void	ft_pa(t_lst **a, t_lst **b);
t_lst	*ft_iter(t_lst **a);

/* FT_CHECK.C */
int		ft_check(t_lst *a);

/* FT_NBR_CHECK.C */
int		nbr_check(t_lst *a);
int		ft_check_nbr(char *a);

/* FT_ERROR.C */
int		ft_error(void);
void	ft_free_arr(char **s);
void	ft_free_lst(t_lst **a);
t_lst	*ft_exception(t_lst **a, t_lst **b);
t_lst	*ft_exception_3(t_lst **a, t_lst **b);

/* RADIX.C */
t_lst	*ft_radix(t_lst **a, t_lst **b);
void	ft_plst(t_lst *a);

/* FT_CONDITIONS.C */
void	ft_conditions(t_lst **a, t_lst **b, int ac);

#endif
