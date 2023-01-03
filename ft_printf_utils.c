/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:24:21 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/03 14:33:50 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_abs(long long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_bzero(void *s, int n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n--)
		*(tmp++) = 0;
	return (s);
}

void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	if (size > 0 && nmemb > 2147483647 / size)
		return (NULL);
	if (nmemb < 1 || size < 1)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char		*d;
	int			i;
	long long	nb;

	i = 1;
	nb = (long long)n;
	while (nb > 9 || nb < 0)
	{
		nb /= 10;
		i++;
	}
	nb = ft_abs((long long)n);
	d = ft_calloc(i + 1, 1);
	if (!d)
		return (NULL);
	while ((n < 0 && i != 1) || (n >= 0 && i != 0))
	{
		d[--i] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	if (n < 0)
		d[0] = '-';
	return (d);
}
