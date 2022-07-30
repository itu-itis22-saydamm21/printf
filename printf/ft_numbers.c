/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:11:08 by msaydam           #+#    #+#             */
/*   Updated: 2022/07/28 21:01:26 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_pointer(size_t pointer, int *len)
{
	char	str[25];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (pointer == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	while (pointer)
	{
		str[i] = base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	str[i] = '\0';
	while (i--)
		ft_putcharacter_len(str[i], len);
}

void	ft_number(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
	}
	else if (num < 0)
	{
		ft_putcharacter_len('-', len);
		ft_number(num * -1, len);
	}
	else
	{
		if (num > 9)
			ft_number(num / 10, len);
		ft_putcharacter_len(num % 10 + 48, len);
	}
}

void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, len);
	ft_putcharacter_len(u % 10 + 48, len);
}

void	ft_hexadecimal(unsigned int hex, int *len, char x_or_X)
{
	char	str[25];
	char	*base;
	int		i;

	i = 0;
	if (x_or_X == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (hex == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	while (hex)
	{
		str[i] = base[hex % 16];
		hex = hex / 16;
		i++;
	}
	while (i--)
		ft_putcharacter_len(str[i], len);
}
