/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:52:10 by aeleimat          #+#    #+#             */
/*   Updated: 2024/09/16 18:52:16 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cheak(char par, va_list args)
{
	int	count;

	count = 0;
	if (par == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (par == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (par == 'd' || par == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (par == '%')
		count = ft_putchar('%');
	else if (par == 'u')
		count = ft_print_unsigned(va_arg(args, unsigned int));
	else if (par == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long long));
	else if (par == 'x' || par == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), par);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += cheak(str[i], arg);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
/*
int	main(void) {
    int d = 123;
    int i = -456;
    unsigned int u = 789;
    unsigned int x = 0xABCDEF;
    unsigned int X = 0xabcdef;
    char c = 'A';
    char *s = "Hello, World!";
    void *p = &d;
    int k;
   
    ft_printf("Testing %%d\n");
    printf("Original printf: ");
    k = printf("%d\n", d);
    printf("the value of the original printf = %d\n",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%d\n", d);
    printf("the value of the ft_printf = %d\n",k);

    ft_printf("\nTesting %%i\n");
    printf("Original printf: ");
    k = printf("%i\n", i);
    printf("the value of the original printf = %d\n",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%i\n", i);
    printf("the value of the ft_printf = %d\n",k);
   
    printf("\nTesting %%u\n");
    ft_printf("Original printf: ");
    k = printf("%u\n", u);
    printf("the value of the original printf = %d",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%u\n", u);
    printf("the value of the ft_printf = %d",k);
 

    ft_printf("\nTesting %%x\n");
    printf("Original printf: ");
    k = printf("%x\n", x);
    printf("the value of the original printf = %d",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%x\n", x);
    printf("the value of the ft_printf = %d",k);

    ft_printf("\nTesting %%X\n");
    printf("Original printf: ");
    k = printf("%X\n", X);
    printf("the value of the original printf = %d",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%X\n", X);
    printf("the value of the ft_printf = %d",k);


    ft_printf("\nTesting %%p\n");
    printf("Original printf: ");
    k = printf("%p\n", p);
    printf("the value of the original printf = %d",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%p\n", p);
    printf("the value of the ft_printf = %d",k);

    ft_printf("Testing %%c\n");
    printf("Original printf: ");
    k = printf("%c\n", c);
    printf("the value of the original printf = %d",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%c\n", c);
    printf("the value of the ft_printf = %d",k);

    ft_printf("Testing %%s\n");
    printf("Original printf: ");
    k = printf("%s\n", s);
    printf("the value of the original printf = %d",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%s\n", s);
    printf("the value of the ft_printf = %d",k);

    ft_printf("Testing %%\n");
    printf("Original printf: ");
    k = printf("%%\n");
    printf("the value of the original printf = %d",k);
    ft_printf("Custom ft_printf: ");
    k = ft_printf("%%\n");
    printf("the value of the ft_printf = %d",k);

    return (0);
}*/
