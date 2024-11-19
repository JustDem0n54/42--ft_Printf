/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:14 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/19 18:49:58 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int 	i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
		i++;
	}
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthexanbr_fd(int n, int fd, char c)
{
	long	nb;
	int 	i;

	i = 0;
	nb = n;
	i++;
	if (nb > 16)
	{
		ft_puthexanbr_fd(nb / 16, fd, c);
		ft_puthexanbr_fd(nb % 16, fd, c);
	}
	else if (c == 'x' || (nb >= 0 && nb <= 9))
	{
		ft_putchar_fd(BASE16[nb], fd);
	}
	else if (c == 'X' && nb > 9)
	{
		ft_putchar_fd(BASE16[nb] -32, fd);
	}
	return (i);
}

