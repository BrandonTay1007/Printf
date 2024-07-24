/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:31 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/24 09:22:51 by twei-yo-         ###   ########.fr       */
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

int	ft_put_ptr_flags(void *ptr, struct format *s_f)
{
	unsigned long	address;
	int				len;

	address = (unsigned long) ptr;
	len = get_unb_len(address, s_f, 16);
	printf("len: %i", len);
	ft_put_ptr(ptr);
	
}