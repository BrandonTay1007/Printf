/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:33 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/23 16:36:13 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void	ft_putnbr_helper(long nb, int *count)
{
	if (nb >= 10)
		ft_putnbr_helper(nb / 10, count);
	*count += ft_putchar((nb % 10) + '0');
}

int	ft_put_uint(unsigned int nb)
{
	long	nb_long;
	int		count;

	count = 0;
	nb_long = (long) nb;
	ft_putnbr_helper(nb_long, &count);
	return (count);
}

int	get_unb_len(unsigned long nb, struct format *s_f, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		if (s_f->precision == 0)	
			return (0);
		return (1);
	}
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}
//lack of testing yet need a full test case. 
int	ft_put_uint_flags(unsigned int nb, struct format *s_f)
{
	int	len;
	int	w_c;

	w_c = 0;
	len = get_unb_len((unsigned long) nb, s_f, 10);
	if (s_f->right_justify)
	{
		w_c += ft_pad_width(s_f->precision - len, '0');
		if (nb != 0 || s_f->precision != 0)
			w_c += ft_put_uint(nb);
		w_c += ft_pad_width(s_f->width - w_c, ' ');
	}
	else
	{
		w_c += print_width(s_f, len, 0);
		w_c += ft_pad_width(s_f->precision - len, '0');
		if (nb != 0 || s_f->precision != 0)
			w_c += ft_put_uint(nb);
	}
	return (w_c);
}
