/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:22:14 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/03 15:26:38 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_printnbr(int n)
{
	int		len;
	char	*nb;

	nb = ft_itoa(n);
	if (!nb)
		return (0);
	len = ft_printstr(nb);
	free(nb);
	return (len);
}

int	ft_printunbr(unsigned int n)
{
	int		len;
	char	*nb;

	nb = ft_uitoa(n);
	if (!nb)
		return (0);
	len = ft_printstr(nb);
	free(nb);
	return (len);
}

int	ft_printhex(unsigned long long n, const char f)
{
	int		len;
	char	*nb;

	len = 0;
	if (f == 'p' && n == 0)
		return (write(1, "(nil)", 5));
	else if (f == 'p')
		len = write(1, "0x", 2);
	nb = ft_uitohexa(n, f);
	if (!nb)
		return (0);
	len += ft_printstr(nb);
	free(nb);
	return (len);
}
