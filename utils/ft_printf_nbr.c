/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:01 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/15 16:18:23 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

int	get_nbr_len(char *nbr, struct format *s_f)
{
	int	len;

	len = ft_strlen(nbr);
	if (s_f->precision >= len)
		len = s_f->precision;
	if (nbr[0] && nbr[0] == '-')
		len++;
	if (nbr[0] != '-' && (s_f->plus || s_f->space))
		len++;
	return (len);
}

// create a new buffer for number with precision already ex: str = +0000123
int	print_num(char *temp, struct format *s_f)
{
	int	w_c;
	int	len;

	w_c = 0;
	len = get_nbr_len(temp, s_f);
	if (temp[0] && temp[0] != '-')
	{
		if (s_f->plus)
			w_c += ft_putchar('+');
		else if (s_f->space)
			w_c += ft_putchar(' ');
	}
	else
	{
		w_c += ft_putchar('-');
		temp++;
	}
	if (s_f->zero_pad && s_f->precision < 0)
		w_c += ft_pad_width(s_f->width - ft_strlen(temp) - w_c, '0');
	w_c += ft_pad_width(s_f->precision - ft_strlen(temp), '0');
	if (s_f->precision != 0 || *temp != '0')
		w_c += ft_putstr(temp);
	return (w_c);
}

int	ft_putint_flags(int nb, struct format *s_f)
{
	char	*temp;
	int		w_c;
	int		len;

	w_c = 0;
	temp = ft_itoa(nb);
	if (s_f->right_justify)
	{
		w_c += print_num(temp, s_f);
		w_c += ft_pad_width(s_f->width - w_c, ' ');
	}
	else
	{
		len = get_nbr_len(temp, s_f);
		if (!s_f->zero_pad || s_f->precision >= 0)
			w_c += ft_pad_width(s_f->width - len, ' ');
		w_c += print_num(temp, s_f);
	}
	free(temp);
	return (w_c);
}

int	ft_putint(int nb)
{
	char	*temp;
	int		w_c;

	w_c = 0;
	temp = ft_itoa(nb);
	w_c = ft_putstr(temp);
	free(temp);
	return (w_c);
}
/* int	ft_putint(int nb)
{
	long	nb_long;
	int		count;

	count = 0;
	nb_long = (long) nb;
	ft_putnbr_helper(nb_long, &count);
	return (count);
	
} */