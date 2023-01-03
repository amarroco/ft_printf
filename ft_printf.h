/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:07 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/03 15:36:08 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			ft_printchar(int c);
int			ft_printstr(char *s);
int			ft_printnbr(int n);
int			ft_printunbr(unsigned int n);
int			ft_printhex(unsigned long long n, const char f);

char		*ft_uitoa(unsigned int n);
char		*ft_uitohexa(long long unsigned n, const char f);
int			ft_printarg(va_list args, const char f);
int			ft_printf(const char *s, ...);

#endif