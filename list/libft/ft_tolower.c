/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:07:19 by rofuente          #+#    #+#             */
/*   Updated: 2023/01/17 19:50:15 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int main()
// {
//     char a;

//     a = 'd';
//     printf("%c\n", tolower(a));
//     printf("%c\n", ft_tolower(a));
//     return (0);
// }
