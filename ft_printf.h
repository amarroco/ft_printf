#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

long long	ft_abs(long long int x);
int			ft_strlen(char *s);
void		*ft_bzero(void *s, int n);
void		*ft_calloc(int nmemb, int size);
char		*ft_itoa(int n);

int			ft_putchar(int c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_putunbr(unsigned int n);
int			ft_puthex(unsigned long long n, const char f);

char		*ft_uitoa(unsigned int n);
char		*ft_uitohexa(long long unsigned n, const char f);
int			ft_print_arg(va_list args, const char f);
int			ft_printf(const char *s, ...);

#endif