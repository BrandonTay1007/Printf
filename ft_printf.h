/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:44:59 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/06/26 13:45:39 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef DEF_DP
#  define DEF_DP 6
# endif

# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

int		ft_put_uint(unsigned int nb);
void	ft_put_hexa(unsigned long nb, char format, int *count);
int		ft_put_ptr(void *ptr);
int		ft_printf(const char *str, ...);
int		ft_hexa_uint(unsigned int nb, char format);
int		ft_hexa_ulong(unsigned long nb, char format);
int		ft_putint(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr_helper(long nb, int *count);

#endif