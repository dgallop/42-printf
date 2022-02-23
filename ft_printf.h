/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallo-p <dgallo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:09:23 by dgallo-p          #+#    #+#             */
/*   Updated: 2021/12/10 20:14:07 by dgallo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
---------------PRINTF
*/

/*
	ft_printf
*/

int					ft_printf(const char *s, ...);
int					ft_start(const char *s,
						va_list args, int char_count, int i);
int					ft_study_string(const char *s,
						va_list args, int char_count);

/*
		ft_print_chr
*/

int					ft_write_char(va_list args, int char_count);
int					ft_write_str(va_list args, int char_count);
int					ft_write_per(int char_count);

/*
		ft_print_nb
*/

int					ft_treat_ptr(va_list args, int char_count);
int					ft_write_ptr(unsigned long int nb, int char_count,
						char *base, int len);
int					ft_write_int(va_list args, int char_count);
int					ft_write_dec(va_list args, int char_count);
int					ft_write_unt(va_list args, int char_count);

/*
			ft_hexadecimal
*/

int					ft_treat_hexa(va_list args, int char_count, char c);
int					ft_write_hexadecimal(unsigned long int nb, int char_count,
						char *base, int len);

/*
	ft_libft
*/

char				*ft_strchr(const char *s, int c);
unsigned long int	ft_strlen(char const	*s);
int					ft_putchar(char c, int char_count);
int					ft_putnbr(int nb, int char_count);
int					ft_putnbr_unt(unsigned int nb, int char_count);
char				*ft_strdup(const char *s1);

#endif
