/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <hpideci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:53:24 by hpideci           #+#    #+#             */
/*   Updated: 2023/09/10 18:03:30 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int print)
{
	int	tmp;

	tmp = 0;
	if (stack->size_a < 2)
		return ((void)write(1, "A few argument", 14));
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (!print)
		write(1, "sa\n", 3);
}

void	rra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	i = stack->size_a;
	tmp = stack->a[i - 1];
	while (--i)
		stack->a[i] = stack->a[i - 1];
	stack->a[i] = tmp;
	if (!print)
		write(1, "rra\n", 4);
}

void	ra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	if (!print)
		write (1, "ra\n", 3);
}

void	pa(t_stack *stack, int print)
{
	int	i;

	i = 0;
	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
			stack->b[i] = stack->b[i + 1];
		if (!print)
			write(1, "pa\n", 3);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
