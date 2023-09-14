/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <hpideci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:35:41 by hpideci           #+#    #+#             */
/*   Updated: 2023/09/10 17:21:37 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int *stack, char **av, int flag)
{
	if (flag)
		ft_malloc_error(av);
	free (stack);
	write(1, "Error", 5);
	exit (1);
}

int	ft_ps_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ps_atoi(char *str, int *stack, char **av, int flag)
{
	unsigned int		i;
	int					sign;
	unsigned long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack, av, flag);
		n = n * 10 + str[i] - '0';
		i++;
	}
	if ((n > 2147483648 && sign == -1) || (n > 2147483647 && sign == 1))
		ft_error(stack, av, flag);
	return (n * sign);
}

void	ft_check_repeat(int *stack, int size, char **av, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				ft_error(stack, av, flag);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
