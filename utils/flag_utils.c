/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:52:03 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/12 19:04:24 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.c"

int	is_flag(char flag, struct format *str_format)
{
	if (flag == '-')
		str_format->right_justify = 1;
	else if (flag == '0')
		str_format->zero_pad = 1;			
	else if (flag == '+')
		str_format->plus = 1;			
	else if (flag == ' ')
		str_format->space = 1;			
	else if (flag == '#')
		str_format->hash = 1;
	else
		return (0);
}

int	set_flags(char *str, struct format *str_format)
{
	int i;

	i = 0;
	while (str[i] && is_flag(str[i], str_format))
		i++;
	return (i);
}

	
