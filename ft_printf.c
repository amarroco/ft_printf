#include "ft_printf.h"

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
    int     i;

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

long long int	ft_abs(long long int x)
{
	if (x < 0)
	{
		return (-x);
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char			*d;
	int			    i;
	long long int	nb;

	i = 1;
	nb = (long long int)n;
	while (nb > 9 || nb < 0)
	{
		nb /= 10;
		i++;
	}
	nb = ft_abs((long long int)n);
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

char	*ft_uitoa(unsigned int n)
{
	char			*d;
	int			    i;
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

char	*ft_uitohexa(unsigned int n, const char f)
{
	char			*d;
	int			    i;
	unsigned int	nb;

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
        if (f == 'x')
		    d[--i] = "0123456789abcdef"[n % 16];
        else
            d[--i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (d);
}

int	ft_putchar(int c)
{
    if (!c)
        return (0);
	write(1, &c, 1);
    return (1);
}

int	ft_putstr(char *s)
{
    int len;

    if (!s)
		return (0);
    len = ft_strlen(s);	
	write(1, s, len);
    return (len);
}

int ft_putnbr(int n)
{
    int     len;
    char    *nb;

    nb = ft_itoa(n);
    if (!nb)
        return (0);
    len = ft_putstr(nb)
    free(nb);
    return (len);
}

int ft_putunbr(unsigned int n)
{
    int     len;
    char    *nb;

    nb = ft_uitoa(n);
    if (!nb)
        return (0);
    len = ft_putstr(nb)
    free(nb);
    return (len);
}

int ft_puthex(unsigned int n, const char f)
{
    int     len;
    char    *nb;

    nb = ft_uitohexa(n, f);
    if (!nb)
        return (0);
    len = ft_putstr(nb)
    free(nb);
    return (len);
}

int ft_print_arg(va_list args, const char f)
{
    int len;

    len = 0;
    if (f == 'c')
        len = ft_putchar(va_arg(arg, int));
    else if (f == 's')
        len = ft_putstr(va_arg(args, char *));
    else if (f == 'p')
        len = ft_putptr();
    else if (f == 'd' || f == 'i')
        len = ft_putnbr(va_arg(args, int));
    else if (f == 'u')
        len = ft_putunbr(va_arg(args, unsigned int));
    else if (f == 'x' || f == 'X')
        len = ft_puthex(f, va_arg(args, unsigned int));
    else if (f == '%')
        len = ft_putchar('%');
    return(len);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    int     i;
    int     len;

    i = 0;
    len = 0;
    va_start(args, s);
    while(s[i])
    {
        if (s[i] == '%')
            len += ft_print_arg(args, str[++i]);
        else
            len += ft_putchar(s[i]);
        i++;
    }
    va_end(args);
    return (len);
}