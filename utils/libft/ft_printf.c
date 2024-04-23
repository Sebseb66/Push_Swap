/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <sfroidev@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:42:06 by sfroidev          #+#    #+#             */
/*   Updated: 2023/09/19 11:35:07 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_putchar_printf(char a)
{
	return (write(1, &a, 1));
}

int	ft_all_types(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg((*args), int)));
	else if (c == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (c == 'p')
		return (ft_type_p(va_arg((*args), unsigned long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_type_di(va_arg((*args), int)));
	else if (c == 'u')
		return (ft_type_u(va_arg((*args), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_type_x(va_arg((*args), unsigned int), c));
	else if (c == '%')
		return (ft_string("%"));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_all_types(&args, str[i + 1]);
			i += 2;
		}
		else
		{
			len += ft_putchar_printf(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
