/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:56:39 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/30 22:03:40 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
int	ft_putchar_flags(char c, struct format *str_format)
{
	int	word_c;

	word_c = 0;
	if (str_format->right_justify)
	{
		word_c += ft_putchar(c);
		word_c += ft_pad_width((str_format->width) - word_c, ' ');
	}
	else
	{
		word_c += ft_pad_width((str_format->width) - 1, ' ');
		word_c += ft_putchar(c);
	}
	return (word_c);	
}

int	ft_putstr_flags(char *str, struct format *str_format)
{
	int		word_c;
	char	*temp;

	word_c = 0;
	if ((int) ft_strlen(str) < str_format->precision || str_format->precision < 0)
		str_format->precision = ft_strlen(str);
	temp = malloc(str_format->precision + 1);
	ft_strlcpy(temp, str, str_format->precision + 1);
	if (str_format->right_justify)
	{
		word_c += ft_putstr(temp);	
		word_c += ft_pad_width((str_format->width) - word_c, ' ');
	}
	else
	{
		word_c += ft_pad_width((str_format->width) - ft_strlen(temp), ' ');
		word_c += ft_putstr(temp);
	}
	free(temp);
	return (word_c);
}

int ft_print_percent(struct format *s_f)
{

}
