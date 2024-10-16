/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:52:39 by aeleimat          #+#    #+#             */
/*   Updated: 2024/09/16 18:56:44 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_strlen(char *str);
int		ft_putchar(char x);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_print_unsigned(unsigned int n);
int		ft_putnbr_hex_low(unsigned int num);
int		ft_putnbr_hex_up(unsigned int num);
void	ft_putnbr_hex(unsigned long num, int upper);
int		ft_putpointer(void *ptr);
int		ft_printf(const char *str, ...);
int		cheak(char par, va_list args);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_ptr(unsigned long long ptr);

#endif
