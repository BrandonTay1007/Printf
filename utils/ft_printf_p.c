/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:31 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/30 09:21:28 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

int	ft_hexa_ulong(unsigned long nb, char format)
{
	int	w_c;

	w_c = 0;
	ft_put_hexa(nb, format, &w_c);
	return (w_c);
}

int	ft_put_ptr(void *ptr)
{
	unsigned long	address;
	int				w_c;

	w_c = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	address = (unsigned long) ptr;
	w_c += ft_putstr("0x");
	w_c += ft_hexa_ulong(address, 'x');
	return (w_c);
}

int	print_precision_ptr(unsigned long addy, struct format *s_f, int len)
{
	int w_c;

	w_c = 0;
	if (!addy)
		return (ft_putstr("(nil)"));
	if (s_f->zero_pad != 1 || s_f->precision > -1)
		w_c += ft_putstr("0x");
	w_c += ft_pad_width(s_f->precision - len, '0');
	w_c += ft_hexa_ulong(addy, 'x');
	return (w_c);
}

int	ft_put_ptr_flags(void *ptr, struct format *s_f)
{
	unsigned long	address;
	int				len;
	int				w_c;

	w_c = 0;
	address = (unsigned long) ptr;
	len = get_unb_len(address, s_f, 16);
	printf("len: %i", len);
	if (s_f->right_justify)
	{
		w_c += print_precision_ptr(address, s_f, len);
		w_c += ft_pad_width(s_f->width - w_c, ' ');
	}
	else
	{
		if (s_f->zero_pad && s_f->precision < 0)
		{
			w_c += ft_putstr("0x");
			s_f->width -= 2;
		}
		w_c += print_width(s_f, len + w_c, (long long) address);
		w_c += print_precision_ptr(address, s_f, len);
	}
	return (w_c);
}
