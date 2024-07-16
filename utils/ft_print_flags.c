/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:49:06 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/14 15:38:33 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
int	ft_pad_width(int width, char c)
{
	int	i;

	if (width < 0)
		return (0);
	i = 0;
	while (i < width)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}



/* int main(int argc, char const *argv[])
{
	print_zero(17);
	return 0;
} */
