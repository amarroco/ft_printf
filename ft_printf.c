/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:03:09 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/02 18:41:29 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char			*d;
	int				i;
	unsigned int	nb;

	i = 1;
	nb = n;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	d = ft_calloc(i + 1, 1);
	if (!d)
		return (NULL);
	while (i != 0)
	{
		d[--i] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (d);
}

char	*ft_uitohexa(long long unsigned n, const char f)
{
	char				*d;
	int					i;
	long long unsigned	nb;

	i = 1;
	nb = n;
	while (nb > 15)
	{
		nb /= 16;
		i++;
	}
	d = ft_calloc(i + 1, 1);
	if (!d)
		return (NULL);
	while (i != 0)
	{
		i--;
		if (f == 'x')
			d[i] = "0123456789abcdef"[n % 16];
		else
			d[i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (d);
}

int	ft_print_arg(va_list args, const char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (f == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (f == 'p')
	{
		len = ft_putstr("0x");
		len += ft_puthex((unsigned long long)va_arg(args, void *), 'x');
	}
	else if (f == 'd' || f == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (f == 'u')
		len = ft_putunbr(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		len = ft_puthex(va_arg(args, unsigned int), f);
	else if (f == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			len += ft_print_arg(args, s[++i]);
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
