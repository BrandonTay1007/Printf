/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:  24/07/01 22:12:31 by twei-yo-          #+#    #+#             */
/*   Updated:  24/07/15 15:09:12 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#include "../libft/libft.h"

int	speci_parser(char d_type, va_list args, struct format str_format)
{
	int		word_c;

	if (d_type == 'c')
		word_c = ft_putchar(va_arg(args, int));
	else if (d_type == 's')
		word_c = ft_putstr(va_arg(args, char *));
	else if (d_type == 'd' || d_type == 'i')
		word_c = ft_putint(va_arg(args, int));
	else if (d_type == 'u')
		word_c = ft_put_uint(va_arg(args, unsigned int));
	else if (d_type == 'x' || d_type == 'X')
		word_c = ft_hexa_uint(va_arg(args, unsigned int), d_type);
	else if (d_type == 'p')
		word_c = ft_put_ptr(va_arg(args, void *));
	else if (d_type == '%')
		word_c = ft_putchar('%');
	else
		return (-1);
	return (word_c);
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
}

int	format_parser(char *str, void *ptr)
{
	int				i;
	struct format	*str_format;

	i = 0;
	str_format = malloc(sizeof(struct format));
	//set all format to NULL/0 
	set_default(str_format);
	i += set_flags(str, str_format);
	i += set_width(str + i, str_format);
	i += set_precision(str + i, str_format);
	str_format->d_type = *(str + i);
	// printf("precision: %i\n", str_format->precision);
	// printf("width: %i\n", str_format->width);?
	// printf("-: %i\n", str_format->right_justify);
	// printf("0: %i\n", str_format->zero_pad);
	// printf("+: %i\n", str_format->plus);
	// printf(" : %i\n", str_format->space);
	// printf("#: %i\n", str_format->hash);
	// printf("d_tpye = %c\n", str_format->d_type);
	// printf("precision: %i\n", str_format->precision);
	int s = ft_put_ptr_flags(ptr, str_format);
	printf("\n");
	printf("%i\n", s);

	// s = ft_hexa_uint_flags(INT_MAX , str_format, str_format->d_type);
	// printf("\n");
	// printf("%i\n", s);
	
	// s = ft_hexa_uint_flags(INT_MIN, str_format, str_format->d_type);
	// printf("\n");  
	// printf("%i\n", s);

}


int main(int argc, char const *argv[])
{
	int *ptr;
	format_parser("p", ptr);
	printf("--------------\n");
	
	int a = printf("%p", ptr);
	printf("\n");
	printf("%i\n", a); 

	// a = printf("%+#-20x", INT_MAX);
	// printf("\n");
	// printf("%i\n", a); 
	
	// a = printf("%+#-20x", INT_MIN);
	// printf("\n");
	// printf("%i\n", a); 
	
	return 0;
}

