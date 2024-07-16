/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:50:17 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/14 17:01:29 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	set_precision(char *str, struct format *format) //chcked
{
	int	i;

	i = 0;
	if (str[i] == '.')
		i++;
	else
		return (-1);
	format->precision = get_num(str + i, &i);

	return(i);
}