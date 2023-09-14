/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <hpideci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:28:48 by hpideci           #+#    #+#             */
/*   Updated: 2023/09/10 17:10:16 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **av, int flag)
{
	t_stack	stack;
	int		size;
	int		i;

	i = -1;
	size = ft_ps_strlen(av);
	stack.a = malloc(sizeof(int) * size);
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = ft_ps_atoi(av[i], stack.a, av, flag);
	ft_check_repeat(stack.a, size, av, flag);
	stack.b = malloc(sizeof(int) * size);
	if (!stack.b)
		return (free(stack.a));
	ft_sort(&stack, size);
	free (stack.a);
	free (stack.b);
}

int	main(int ac, char **av)
{
	int	flag;

	if (ac > 1)
	{
		flag = 0;
		av++;
		if (ac == 2)
		{
			av = ft_split(*av, ' ');
			flag++;
		}
		ft_push_swap(av, flag);
		if (ac == 2)
			ft_malloc_error(av);
	}
}
