/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:49:06 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/23 22:17:36 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
/* 
Latest update: update print width to only print width
for i/d for flags (+, space, neg num) 
 */
int	ft_pad_width(int width, char c)
{
	int	i;

	i = 0;
	while (i < width)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int	print_width(struct format *s_f, int len, long long nb)
{
	int	w_c;

	w_c = 0;
	if (s_f->precision >= len)
			len = s_f->precision;
	if (s_f->d_type == 'x' || s_f->d_type == 'X')
		if (s_f->hash && nb > 0)
			len += 2;
	if (s_f->d_type == 'd' || s_f->d_type == 'i')
		if ((nb < 0 || s_f->plus || s_f->space))
			len++;
	if (s_f->zero_pad && s_f->precision < 0)
		w_c += ft_pad_width(s_f->width - len, '0');
	else
		w_c += ft_pad_width(s_f->width - len, ' ');
	return (w_c);
}

/* 
int main(int argc, char const *argv[])
{
	int i = ft_pad_width(-10, '0');
	printf("%i", i);
	return 0;
} */
