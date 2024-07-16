/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:16:45 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/07/08 13:52:38 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include "../libft/libft.h"


int	set_width(char *str, struct format *format)
{
	int	i;

	i = 0;
	format->width = get_num(str, &i);
	return (i);
}
