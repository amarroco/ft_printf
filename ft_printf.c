/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:03:09 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/03 15:43:33 by amarroco         ###   ########.fr       */
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

char	*ft_uitohexa(unsigned long long n, const char f)
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
		if (f == 'x' || f == 'p')
			d[i] = "0123456789abcdef"[n % 16];
		else
			d[i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (d);
}

int	ft_printarg(va_list args, const char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (f == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (f == 'p')
		len = ft_printhex(va_arg(args, unsigned long long), f);
	else if (f == 'd' || f == 'i')
		len = ft_printnbr(va_arg(args, int));
	else if (f == 'u')
		len = ft_printunbr(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		len = ft_printhex(va_arg(args, unsigned int), f);
	else if (f == '%')
		len = ft_printchar('%');
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
			len += ft_printarg(args, s[++i]);
		else
			len += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
