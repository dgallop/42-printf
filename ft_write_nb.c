/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:48:22 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/10 19:53:29 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_int(va_list args, int char_count)
{
	int	nb;

	nb = va_arg(args, int);
	char_count = ft_putnbr(nb, char_count);
	return (char_count);
}

int	ft_write_dec(va_list args, int char_count)
{
	int	nb;

	nb = va_arg(args, int);
	char_count = ft_putnbr(nb, char_count);
	return (char_count);
}

int	ft_write_unt(va_list args, int char_count)
{
	unsigned int	nb;

	nb = va_arg(args, int);
	if (nb > 0)
		nb = 4294967295 + 1 + nb;
	char_count = ft_putnbr_unt(nb, char_count);
	return (char_count);
}

int	ft_treat_ptr(va_list args, int char_count)
{
	unsigned long int	nb;
	int					len;
	unsigned long int	temp;
	char				*base;

	nb = (unsigned long int)va_arg(args, void *);
	base = ft_strdup("0123456789abcdef");
	write(1, "0x", 2);
	char_count += 2;
	len = 1;
	temp = nb / 16;
	while (temp != 0)
	{
		len++;
		temp /= 16;
	}
	char_count = ft_write_ptr(nb, char_count, base, len);
	return (char_count);
}

int	ft_write_ptr(unsigned long int nb, int char_count, char *base, int len)
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
