/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <sfroidev@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:42:15 by sfroidev          #+#    #+#             */
/*   Updated: 2023/10/03 12:31:44 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/push_swap.h"

int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	convert(char *str)
{
	char	*tmp;
	int		diff;

	tmp = ft_itoa(ft_atoi(str));
	diff = ft_strcmp(tmp, str);
	free(tmp);
	if (diff)
		return (0);
	return (1);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (!convert(num))
		return (0);
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Erreur !!!!");
		if (ft_contains(tmp, args, i))
			ft_error("Erreur !!!!");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Erreur !!!!");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
