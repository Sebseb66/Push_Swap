/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <sfroidev@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:56:52 by sfroidev          #+#    #+#             */
/*   Updated: 2023/10/03 11:32:20 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_write_nbrber(char *dest, unsigned int n)
{
	if (n < 10)
		*dest = n + '0';
	else
	{
		*dest = n % 10 + '0';
		ft_write_nbrber(dest - 1, n / 10);
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*result;
	size_t			len;

	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		len = ft_count_digits(n);
		if (n < 0)
			len++;
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (!result)
			return (0);
		if (n < 0)
		{
			result[0] = '-';
			ft_write_nbrber(result + len - 1, -nbr);
		}
		else
			ft_write_nbrber(result + len - 1, nbr);
		result[len] = '\0';
	}
	return (result);
}

// int	main(void)
// {
// 	printf("\n%s\n", ft_itoa(1234567));
// }
