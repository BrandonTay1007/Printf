/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:44:56 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/30 21:55:46 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
//saw % -> check flag -> width -> check precision
int speci_parser_flags(struct format *s_f, va_list args)  
{
	int		word_c;

	if (s_f->d_type == 'c')
		word_c = ft_putchar_flags(va_arg(args, int), s_f);
	else if (s_f->d_type == 's')
		word_c = ft_putstr_flags(va_arg(args, char *), s_f);
	else if (s_f->d_type == 'd' || s_f->d_type == 'i')
		word_c = ft_putint_flags(va_arg(args, int), s_f);
	else if (s_f->d_type == 'u')
		word_c = ft_put_uint_flags(va_arg(args, unsigned int), s_f);
	else if (s_f->d_type == 'x' || s_f->d_type == 'X')
		word_c = ft_hexa_uint_flags(va_arg(args, unsigned int), s_f, s_f->d_type);
	else if (s_f->d_type == 'p')
		word_c = ft_put_ptr_flags(va_arg(args, void *),s_f);
	else if (s_f->d_type == '%')
		word_c = ft_putchar('%');
	else
		return (-1);
	return (word_c);
}

int	check_valid_data(struct format *s_f, va_list args, int *word_c)
{
	int	temp;

	temp = speci_parser_flags(s_f, args);
	if (temp < 0)
        return (0);
	*word_c += temp;
    return (1);
}
int	ft_printf_bonus(const char *str, ...)
{
	va_list	args;
	struct format *str_format;
	int		i;
	int		word_c;

	i = 0;
	word_c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			str_format = format_parser(((char *) str) + i + 1);
			if(!check_valid_data(str_format, args, &word_c))
                word_c += ft_putchar(str[i]);
            else
                i += str_format->index;
		}
		else
			word_c += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (word_c);
}

int main()
{
	char			c = 'H';
	char			*str = "Im not gay";
	int				nb = 1230921;
	unsigned int	u_int = 1234;
	char			*ptr = "testing";
	int				a;
	a = printf("%cello World, %-20.13s, %+23.1i, %012d, %#10x, %X, %-30.1u, %10p, %% avc %r", 
			c, 
			str, 
			nb, 
			nb, 
			nb, 
			nb, 
			u_int, 
			ptr);
	printf("%i", a);
	printf("\n----------------------------------------------------\n");
	a = ft_printf_bonus("%cello World, %-20.13s, %+23.1i, %012d, %#10x, %X, %-30.1u, %10p, %% avc %r", 
			c, 
			str, 
			nb, 
			nb, 
			nb, 
			nb, 
			u_int, 
			ptr);
	printf("a %i a", a);

	return 0;
}