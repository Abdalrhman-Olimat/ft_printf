/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:00:00 by aeleimat          #+#    #+#             */
/*   Updated: 2024/09/16 19:12:37 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*int	ft_putunsigned(unsigned int n)
{
	char	buffer[10];
	int		len;
	int		temp;
	int		i;

	len = 0;
	temp = n;
	if (n == 0)
		buffer[len++] = '0';
	else
	{
		while (temp > 0)
		{
			buffer[len++] = (temp % 10) + '0';
			temp /= 10;
		}
	}
	i = len;
	while (len > 0)
	{
		write(1, &buffer[--len], 1);
	}
	return (i);
}
*/
void	ft_putnbr_hex(unsigned long num, int upper)
{
	char	base[16];
	int		i;

	i = 0;
	while (i < 10)
	{
		base[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		if (upper)
			base[i] = 'A' + (i - 10);
		else
			base[i] = 'a' + (i - 10);
		i++;
	}
	if (num >= 16)
		ft_putnbr_hex(num / 16, upper);
	ft_putchar(base[num % 16]);
}
/*
int	ft_putpointer(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_hex(address, 0);
	return (14);
}
int	ft_putnbr_hex_low(unsigned int num)
{
	char	base[16] = "0123456789abcdef";
	char	buffer[8 * sizeof(unsigned int)];
	int		len;
	int		i;

	len = 0;
	if (num == 0)
		buffer[len++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[len++] = base[num % 16];
			num /= 16;
		}
	}
	i = len;
	while (len > 0)
		write(1, &buffer[--len], 1);
	return (i);
}

int	ft_putnbr_hex_up(unsigned int num)
{
	char	base[16] = "0123456789ABCDEF";
	char	buffer[8 * sizeof(unsigned int)];
	int		len;
	int		i;

	len = 0;
	if (num == 0)
		buffer[len++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[len++] = base[num % 16];
			num /= 16;
		}
	}
	i = len;
	while (len > 0)
		write(1, &buffer[--len], 1);
	return (i);
}*/
