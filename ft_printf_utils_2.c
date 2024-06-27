/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:28:52 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/06/26 13:57:34 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr_helper(long nb, int *count)
{
	if (nb < 0)
	{
		nb *= -1;
		*count += ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr_helper(nb / 10, count);
	*count += ft_putchar((nb % 10) + '0');
}

int	ft_putint(int nb)
{
	long	nb_long;
	int		count;

	count = 0;
	nb_long = (long) nb;
	ft_putnbr_helper(nb_long, &count);
	return (count);
}

/* int main(int argc, char const *argv[])
{
	ft_putstr("");
		
	return 0;
} */
