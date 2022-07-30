/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:45:49 by msaydam           #+#    #+#             */
/*   Updated: 2022/07/28 21:02:01 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_print_checker(char c, va_list args, int *len, int *i)
{
	if (c == 'c')
		ft_putcharacter_len(va_arg(args, int), len);
	else if (c == 's')
		ft_string(va_arg(args, char *), len);
	else if (c == 'p')
		ft_pointer(va_arg(args, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_number(va_arg(args, int), len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_hexadecimal(va_arg(args, unsigned int), len, 'x');
	else if (c == 'X')
		ft_hexadecimal(va_arg(args, unsigned int), len, 'X');
	else if (c == '%')
		ft_putcharacter_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print_checker(str[i], args, &len, &i);
			i++;
		}
		else
		{
			ft_putcharacter_len((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
#include <stdio.h>
int	main()
{
	char k[] = "selin";
	printf("%d", ft_printf("%s", k));
}