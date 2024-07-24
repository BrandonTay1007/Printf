/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:50:17 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/23 10:30:26 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	set_precision(char *str, struct format *format) //chcked
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (str[i] == '.')
		i++;
	else
		return (0);
	format->precision = get_num(str + i, &count);
	return(i + count);
}