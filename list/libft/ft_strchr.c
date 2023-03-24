/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:53 by rofuente          #+#    #+#             */
/*   Updated: 2023/01/17 17:24:05 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// int main()
// {
//     char src[50] = "Hola que tal?";
//     char src0[50] = "Hola que tal?";
//     int x;

//     x = 'z';
//     printf("%s\n", strchr(src, x));
//     printf("%s\n", ft_strchr(src0, x));
//     return (0);
// }
