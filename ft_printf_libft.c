/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:46:27 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/10 18:08:57 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	ft_strlen(char const	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (0);
}

int	ft_putnbr(int nb, int char_count)
{
	if (nb == -2147483648)
	{
		char_count = ft_putchar('-', char_count);
		char_count = ft_putchar('2', char_count);
		nb = 147483648;
	}
	if (nb < 0)
	{
		char_count = ft_putchar('-', char_count);
		nb *= -1;
	}
	if (nb >= 10)
	{
		char_count = ft_putnbr(nb / 10, char_count);
		char_count = ft_putnbr(nb % 10, char_count);
	}
	else
		char_count = ft_putchar(nb + 48, char_count);
	return (char_count);
}

int	ft_putnbr_unt(unsigned int nb, int char_count)
{
	if (nb >= 10)
	{
		char_count = ft_putnbr(nb / 10, char_count);
		char_count = ft_putnbr(nb % 10, char_count);
	}
	else
		char_count = ft_putchar(nb + 48, char_count);
	return (char_count);
}

char	*ft_strdup(const char *s1)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str2)
		return (0);
	while (s1[i])
	{
		str2[i] = ((char *)s1)[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
