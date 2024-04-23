/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <sfroidev@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:48:49 by sfroidev          #+#    #+#             */
/*   Updated: 2023/09/19 11:35:21 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type_di(int a)
{
	int	len;

	len = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		len += write(1, "-", 1);
		a *= -1;
	}
	if (a >= 10)
		len += ft_type_di(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (len + 1);
}

int	ft_type_p(unsigned long a, int cont)
{
	int	len;

	len = 0;
	if (!a)
		return (write(1, "(nil)", 5));
	if (cont == 1)
	{
		len += write(1, "0x", 2);
		cont = 0;
	}
	if (a >= 16)
		len += ft_type_p(a / 16, cont);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (len + 1);
}

int	ft_type_u(unsigned int a)
{
	int	len;

	len = 0;
	if (a >= 10)
		len += ft_type_u(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (len + 1);
}

int	ft_type_x(unsigned int a, char c)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_type_x(a / 16, c);
	if (c == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (len + 1);
}
