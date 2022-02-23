/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:09:02 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/10 20:12:01 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_hexa(va_list args, int char_count, char x)
{
	int					nb;
	int					len;
	unsigned long int	temp;
	char				*base;

	nb = va_arg(args, int);
	if (x == 'x')
		base = ft_strdup("0123456789abcdef");
	else if (x == 'X')
		base = ft_strdup("0123456789ABCDEF");
	len = 1;
	temp = nb;
	temp = temp / 16;
	while (temp != 0 && temp != 4294967295)
	{
		len++;
		temp /= 16;
	}
	char_count = ft_write_hexadecimal(nb, char_count, base, len);
	return (char_count);
}

int	ft_write_hexadecimal(unsigned long int nb, int char_count,
		char *base, int len)
{
	char				*hexadecimal;

	hexadecimal = (char *)malloc(sizeof(char) * (len + 1));
	if (!hexadecimal)
		return (0);
	hexadecimal[len] = '\0';
	char_count += len;
	while (len-- > 0)
	{
		hexadecimal[len] = base[nb % 16];
		nb = nb / 16;
	}
	len = ft_strlen(hexadecimal);
	write(1, hexadecimal, len);
	free(base);
	free(hexadecimal);
	return (char_count);
}
