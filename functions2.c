/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:43:50 by hpideci           #+#    #+#             */
/*   Updated: 2023/08/31 15:11:48 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *stack, int len, int operation)
{
	if (operation == 0)
		pb(stack, 0);
	else
		pa(stack, 0);
	len--;
	return (len);
}

void	ft_sort_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s, 0);
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		rra(s, 0);
	}
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s, 0);
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		ra(s, 0);
	}
	else if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s, 0);
}

void	ft_sort_bubble(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_checked_sorted(int *stack_a, int size, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (++i < size)
			if (stack_a[i - 1] > stack_a[i])
				return (0);
		return (1);
	}
	else
	{
		while (++i < size)
			if (stack_a[i - 1] < stack_a[i])
				return (0);
		return (1);
	}
}

void	ft_sort(t_stack *stack, int size)
{
	if (ft_checked_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			sa(stack, 0);
		else if (size == 3)
			ft_sort_three(stack);
		else
			ft_quicksort_a(stack, size);
	}
}
