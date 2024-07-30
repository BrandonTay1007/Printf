/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:03 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/30 09:21:25 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"


void	ft_put_hexa(unsigned long nb, char format, int *count)
{
	if (nb >= 16)
		ft_put_hexa(nb / 16, format, count);
	nb %= 16;
	if (nb <= 9)
		*count += ft_putchar(nb + '0');
	else
	{
		if (format == 'x')
			*count += ft_putchar(nb + 87);
		else if (format == 'X')
			*count += ft_putchar(nb + 55);
	}
}

int	ft_hexa_uint(unsigned int nb, char format)
{
	int	count;

	count = 0;
	ft_put_hexa((unsigned long) nb, format, &count);
	return (count);
}

int	print_sign(char format, unsigned int nb)
{
	int	w_c;

	w_c = 0;
	if (nb == 0)
		return (0);
	w_c += ft_putchar('0');
	w_c += ft_putchar(format);
	return(w_c);
}
int	print_precision(unsigned int nb, struct format *s_f, int len)
{
	int	w_c;

	w_c = 0;
	if ((s_f->zero_pad != 1 || s_f->precision > -1) && s_f->hash)
		w_c += print_sign(s_f->d_type, nb);
	w_c += ft_pad_width(s_f->precision - len, '0');
	if (nb != 0 || s_f->precision != 0)
		w_c += ft_hexa_uint(nb, s_f->d_type);
	return (w_c);
}
//Tested
int	ft_hexa_uint_flags(unsigned int nb, struct format *s_f, char format)
{
	int	len;
	int	w_c;

	w_c = 0;
	s_f->hexa_format = format;
	len = get_unb_len((unsigned long) nb, s_f, 16);
	if (s_f->right_justify)
	{
		w_c += print_precision(nb, s_f, len);
		w_c += ft_pad_width(s_f->width - w_c, ' ');
	}
	else
	{
		if (s_f->zero_pad && s_f->precision < 0 && s_f->hash)
			w_c += print_sign(s_f->d_type, nb);
		w_c += print_width(s_f, len, (long long) nb);
		w_c += print_precision(nb, s_f, len);
	}
	return (w_c);
}
