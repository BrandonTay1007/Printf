/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:34:34 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/06/26 13:57:11 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_uint(unsigned int nb)
{
	long	nb_long;
	int		count;

	count = 0;
	nb_long = (long) nb;
	ft_putnbr_helper(nb_long, &count);
	return (count);
}

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

int	ft_hexa_uint(unsigned int nb, char format)
{
	int	count;

	count = 0;
	ft_put_hexa((unsigned long) nb, format, &count);
	return (count);
}

int	ft_hexa_ulong(unsigned long nb, char format)
{
	int	count;

	count = 0;
	ft_put_hexa(nb, format, &count);
	return (count);
}
/* int main(int argc, char const *argv[])
{
	char	*b = "SADSAD";
	
	int a = ft_put_uint(4294967295);
	printf("\n%u", 4294967295);
	printf("\n%i\n", a);
	a = ft_hexa_uint(4294967295, 'x');
	printf("\n%x", 4294967295);
	printf("\n%i\n", a);
	a = ft_put_ptr(b);
	printf("\n%p", b);
	printf("\n%i\n", a);
	return 0;
} */