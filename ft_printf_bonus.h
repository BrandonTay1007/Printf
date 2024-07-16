/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:44:59 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/15 22:41:08 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

struct format
{
	char	d_type;
	int		width;
	int		precision;
	int		zero_pad;
	int		right_justify;
	int		space;
	int		plus;
	int		hash;
};


void	ft_putnbr_helper(long nb, int *count);
int		ft_put_uint(unsigned int nb);
int		ft_put_ptr(void *ptr);
int		ft_hexa_uint(unsigned int nb, char format);
int		ft_hexa_ulong(unsigned long nb, char format);
int		ft_putint(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int 	get_num(char  *str, int	*i);
int		set_precision(char *str, struct format *str_format);
int		set_flags(char *str, struct format *str_format);
int		set_width(char *str, struct format *format);
int		ft_pad_width(int width, char c);
int		ft_putchar_flags(char c, struct format *str_format);
int		format_parser(char *str);
int		ft_putstr_flags(char *str, struct format *str_format);
int		ft_putint_flags(int nb, struct format *s_f);
int		ft_put_uint_flags(unsigned int nb, struct format *s_f);






#endif