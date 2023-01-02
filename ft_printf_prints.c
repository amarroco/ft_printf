/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:22:14 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/02 19:13:46 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;
    
    len = 0;
    if (s)
    {
        len = ft_strlen(s);
    }
	write(1, s, len);
	return (len);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*nb;

	nb = ft_itoa(n);
	if (!nb)
		return (0);
	len = ft_putstr(nb);
	free(nb);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int		len;
	char	*nb;

	nb = ft_uitoa(n);
	if (!nb)
		return (0);
	len = ft_putstr(nb);
	free(nb);
	return (len);
}

int	ft_puthex(unsigned long long n, const char f)
{
	int		len;
	char	*nb;

	nb = ft_uitohexa(n, f);
	if (!nb)
		return (0);
	len = ft_putstr(nb);
	free(nb);
	return (len);
}
