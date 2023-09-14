/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <hpideci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:04:40 by hpideci           #+#    #+#             */
/*   Updated: 2023/09/10 17:55:47 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack *stack, int print)
{
	free(stack->a);
	free(stack->b);
	if (print)
		write (1, "Error\n", 6);
	exit(1);
}

void	exec_instruction(t_stack *stack, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa(stack, 1);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(stack, 1);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(stack, 1);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(stack, 1);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(stack, 1);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(stack, 1);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(stack, 1);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(stack, 1);
	else
		free_error(stack, 1);
}

void	ft_checkchecker(t_stack *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		exec_instruction(stack, str);
		free(str);
		str = get_next_line(0);
	}
	if (ft_checked_sorted(stack->a, stack->size_a, 0) && stack->size_b == 0)
		write(1, "\033[0;32mOK\n", 10);
	else
		write(1, "\033[0;32mKO\n", 10);
	free_error(stack, 0);
}

void	ft_checker(char **av, int flag)
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
	ft_checkchecker(&stack);
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
		ft_checker(av, flag);
		if (ac == 2)
			ft_malloc_error(av);
	}
}
