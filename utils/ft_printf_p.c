/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:31 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/06/30 15:37:39 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	address = (unsigned long) ptr;
	count += ft_putstr("0x");
	count += ft_hexa_ulong(address, 'x');
	return (count);
}