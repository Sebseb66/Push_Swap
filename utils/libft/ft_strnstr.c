/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:38:45 by sfroidev          #+#    #+#             */
/*   Updated: 2023/02/13 10:49:35 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;

	if ((!big || !little) && !len)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	llen = ft_strlen(little);
	while (*big && len-- >= llen)
	{
		if (*big == *little && ft_strncmp(big, little, llen) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
