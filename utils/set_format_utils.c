/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:26:09 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/30 21:52:55 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	set_width(char *str, struct format *format)
{
	int	i;

	i = 0;
	format->width = get_num(str, &i);
	return (i);
}

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

int get_num(char  *str, int	*i)
{
	int		num;
	char	*temp;

	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	temp = malloc((*i) + 1);
	ft_strlcpy(temp, str, (*i) + 1);
	num = ft_atoi(temp);
	free(temp);
	return (num);
}

void	set_default(struct format *str_format)
{
	str_format->width = 0;
	str_format->precision = -1;
	str_format->zero_pad = 0;
	str_format->right_justify = 0;   
	str_format->plus = 0;
	str_format->hash = 0;
	str_format->space = 0;
    str_format->index = 0;
}

struct format	*format_parser(char *str)
{
	struct format	*str_format;
    int i;

    i = 0;
	str_format = malloc(sizeof(struct format));
	set_default(str_format);
	i += set_flags(str, str_format);
	i += set_width(str + i, str_format);
	i += set_precision(str + i, str_format);
	str_format->d_type = *(str + i);
    str_format->index = ++i;
    return (str_format); 
}
