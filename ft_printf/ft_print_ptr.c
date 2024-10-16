/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:14:14 by aeleimat          #+#    #+#             */
/*   Updated: 2024/09/17 12:14:33 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharrrr(char c)
{
	write(1, &c, 1);
}

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putcharrrr((num + '0'));
		else
			ft_putcharrrr((num - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	print_length += write(1, "0x", 2);
	ft_put_ptr(ptr);
	print_length += ft_ptr_len(ptr);
	return (print_length);
}
