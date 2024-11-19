/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:58:31 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/19 19:12:26 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	detect_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')		
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'p')
		return 0;
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1));
	if (c == 'x')
		return (ft_puthexanbr_fd(va_arg(args, int), 1, 'x'));
	if (c == 'X')
		return (ft_puthexanbr_fd(va_arg(args, int), 1, 'X'));
	return (0);
}

void	ft_printf(const char *val, ...)
{
    va_list args;
    va_start(args, val);
	int i = 0;
    while (val[i])
	{
		if (val[i] == '%' && val[i + 1] == '%')
		{	
			write(1, "%", 1);
			i++;
		}
		else if (val[i] == '%' && detect_format(val[i + 1], args))
			i = i + 2;
		else if (val[i])
			write(1, &val[i], 1);
		i++;
	}
    va_end(args);
}

// int main() {
// 	int n = 8;
// 	int s = 1813;
//    	ft_printf("test d: %d\n\n", n);
// 	ft_printf("test x: %x\n\n", s);
// 	ft_printf("test %%: %%");
//     return 0;
// }