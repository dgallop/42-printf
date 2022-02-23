/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:29:05 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/10 14:50:38 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int char_count)
{
	write(1, &c, 1);
	char_count++;
	return (char_count);
}

int	ft_write_char(va_list args, int char_count)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	char_count++;
	return (char_count);
}

int	ft_write_str(va_list args, int char_count)
{
	int		i;
	char	*str;
	int		len;

	len = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "";
	len = ft_strlen(str);
	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		write(1, &*(str + i), 1);
	return (char_count + len);
}

int	ft_write_per(int char_count)
{
	char_count = ft_putchar('%', char_count);
	return (char_count);
}
