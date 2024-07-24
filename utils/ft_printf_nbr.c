/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:01 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/23 22:12:32 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

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

int	print_nbr_sign(int nb, struct format *s_f)
{
	if (nb < 0)
		return (ft_putchar('-'));		
	else if (s_f->plus)
		return (ft_putchar('+'));		
	else if (s_f->space)
		return (ft_putchar(' '));		
	return (0);    
}

//get how long the number is (exclude sign)
int	get_nbr_len(int nbr, struct format *s_f)
{
	int		len;
	long	long_nbr;
	
	len = 0;
	long_nbr = (long) nbr;
	if (long_nbr == 0)
	{
		if (s_f->precision == 0)
			return (0);
		else
			return (1);
	}
	if (long_nbr < 0)
		long_nbr *= -1;
	while (long_nbr != 0)
	{
		long_nbr /= 10;
		len++;
	}
	return (len);
}

//print the number with number sign and the precision of number 
int	print_num_precison(int num, int len, struct format *s_f)
{
	int		w_c;
	char	*num_str;
	char	*temp;

	w_c = 0;
	num_str = ft_itoa(num);
	temp = num_str;
	if (!s_f->zero_pad || s_f->precision >= 0)
		w_c += print_nbr_sign(num, s_f);
	if (temp[0] == '-')
		temp++;
	w_c += ft_pad_width(s_f->precision - len, '0');
	if (num != 0 || s_f->precision != 0)
		w_c += ft_putstr(temp);
	free(num_str);
	return (w_c);
}

//lack of testing yet.
// i still need to fix this part on the logic on line 66++	
int	ft_putint_flags(int nb, struct format *s_f)
{
	int		w_c;
	int		len;

	w_c = 0;
	len = get_nbr_len(nb, s_f);
	if (s_f->right_justify)
	{
		w_c += print_num_precison(nb, len, s_f);
		w_c += ft_pad_width(s_f->width - w_c, ' ');
	}
	else
	{
		if (s_f->zero_pad && s_f->precision < 0)
			w_c += print_nbr_sign(nb, s_f);
		len += w_c;
		w_c += print_width(s_f, len, (long long) nb);
		w_c += print_num_precison(nb, len, s_f);
	}
	return (w_c);
}
