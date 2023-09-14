/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:38:02 by hpideci           #+#    #+#             */
/*   Updated: 2023/08/28 18:40:56 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_b(t_stack *s, int len)
{
	if (len == 1)
		pa(s, 0);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s, 0);
		while (len--)
			pa(s, 0);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				sa(s, 0);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ft_push(s, len, 1);
			else
				sb(s, 0);
		}
	}
}

void	ft_quicksort_3(t_stack *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ft_sort_three(stack);
	else if (len == 2 && stack->a[0] > stack->a[1])
		sa(stack, 0);
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack, 0);
			else if (len++)
				pa(stack, 0);
		}
	}
}

int	ft_get_middle(int *pivot, int *stack_a, int size)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = -1;
	while (++i < size)
		tmp[i] = stack_a[i];
	ft_sort_bubble(tmp, size);
	*pivot = tmp[size / 2];
	free (tmp);
	return (1);
}

int	ft_quicksort_a(t_stack *stack, int len)
{
	int	pivot;
	int	items;
	int	count;

	count = 0;
	if (ft_checked_sorted(stack->a, len, 0) == 1)
		return (1);
	items = len;
	if (len <= 3)
		return (ft_quicksort_3(stack, len), 1);
	if (!ft_get_middle(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, 0);
		else if (++count)
			ra(stack, 0);
	}
	while (items / 2 + items % 2 != stack->size_a && count--)
		rra(stack, 0);
	return (ft_quicksort_a(stack, items / 2 + items % 2)
		&& ft_quicksort_b(stack, items / 2));
}

int	ft_quicksort_b(t_stack *stack, int len)
{
	int	pivot;
	int	items;
	int	count;

	count = 0;
	if (!count && ft_checked_sorted(stack->b, len, 1) == 1)
		while (len--)
			pa(stack, 0);
	if (len <= 3)
		return (ft_sort_small_b(stack, len), 1);
	items = len;
	if (!ft_get_middle(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack, 0);
		else if (++count)
			rb(stack, 0);
	}
	while (items / 2 != stack->size_b && count--)
		rrb(stack, 0);
	return (ft_quicksort_a(stack, items / 2 + items % 2)
		&& ft_quicksort_b(stack, items / 2));
}
