/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:53:56 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/10 20:12:43 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_start(const char *s, va_list args, int char_count, int i)
{
	if (s[i + 1] == 'c')
		char_count = ft_write_char(args, char_count);
	if (s[i + 1] == 's')
		char_count = ft_write_str(args, char_count);
	if (s[i + 1] == 'i')
		char_count = ft_write_int(args, char_count);
	if (s[i + 1] == 'd')
		char_count = ft_write_dec(args, char_count);
	if (s[i + 1] == 'u')
		char_count = ft_write_unt(args, char_count);
	if (s[i + 1] == 'p')
		char_count = ft_treat_ptr(args, char_count);
	if (s[i + 1] == 'X')
		char_count = ft_treat_hexa(args, char_count, 'X');
	if (s[i + 1] == 'x')
		char_count = ft_treat_hexa(args, char_count, 'x');
	if (s[i + 1] == '%')
		char_count = ft_write_per(char_count);
	return (char_count);
}

int	ft_study_string(const char *s, va_list args, int char_count)
{
	int	i;

	i = -1;
	while (s[++i] && i < (int)ft_strlen(s))
	{
		while (s[i] && s[i] == '%')
		{
			char_count = ft_start(s, args, char_count, i);
			i += 2;
		}
		if (s[i] && s[i] != '%')
			char_count = ft_putchar(s[i], char_count);
	}
	return (char_count);
}

int	ft_printf(const char *s, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	if (s[0] == '%' && s[1] == '\0')
		return (0);
	va_start(args, s);
	if (!ft_strchr(s, '%'))
		char_count += write(1, s, ft_strlen(s));
	else if (ft_strchr(s, '%'))
		char_count = ft_study_string(s, args, char_count);
	va_end(args);
	return (char_count);
}
