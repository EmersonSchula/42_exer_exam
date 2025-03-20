/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:29:04 by eschula           #+#    #+#             */
/*   Updated: 2025/03/20 14:32:35 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int    ft_printchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int    ft_putstr(char *s)
{
    int        len;

    len = 0;
    if (!s)
        return (write (1, "(null)", 6));
    while(*s)
        len += ft_printchar(*s++);
    return (len);
}

int    ft_putnbr(int n)
{
    unsigned int    nb;
    int                len = 0;

    if (n < 0)
    {
        len += ft_printchar('-');
        nb = -n;
    }
    else
        nb = n;
    if (nb >= 10)
        len += ft_putnbr(nb / 10);
    len += ft_printchar(nb % 10 + '0');
    return (len);
}

int    ft_printhex(unsigned int n)
{
    int        len = 0;
    char    *hex = "0123456789abcdef";

    if (n >= 16)
        len += ft_printhex(n / 16);
    len += ft_printchar(hex[n % 16]);
    return (len);
}

int    ft_printf(const char *format, ...)
{
    va_list    args;
    int        len = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 's')
                len += ft_putstr(va_arg(args, char *));
            if (*format == 'd')
                len += ft_putnbr(va_arg(args, int));
            if (*format == 'x')
                len += ft_printhex(va_arg(args, unsigned int));
        }
        len += ft_printchar(*format);
        format++;
    }
    va_end(args);
    return (len);
}

int    main(void)
{
    ft_printf("teste 1: %s\n", "teste");
    ft_printf("teste 2: %d\n", 123);
    ft_printf("teste 3: %x\n", 255);
}
