/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:54:45 by aeleimat          #+#    #+#             */
/*   Updated: 2024/09/18 15:51:08 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
	{
		count++;
	}
	return (count);
}

int	ft_putchar(char x)
{
	write(1, &x, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return ((write(1, "(null)", 6)));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_putnbr(int nb)
{
	int	length;

	length = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		length = 2 + ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		length = 1 + ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			length += ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		length += 1;
	}
	return (length);
}
