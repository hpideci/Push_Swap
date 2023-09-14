/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <hpideci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:21:15 by hpideci           #+#    #+#             */
/*   Updated: 2023/09/10 18:03:12 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

void	ft_push_swap(char **av, int flag);
//Utils
char	**ft_split(char const *s, char c);
char	**ft_malloc_error(char **tab);
//checker
void	ft_checker(char **av, int flag);
void	ft_checkchecker(t_stack *stack);
void	free_error(t_stack *stack, int print);
void	exec_instruction(t_stack *stack, char *instruction);
//get_next_line
char	*get_next_line(int fd);
//functions
void	ft_error(int *stack, char **av, int flag);
int		ft_ps_strlen(char **str);
int		ft_ps_atoi(char *str, int *stack, char **av, int flag);
void	ft_check_repeat(int *stack, int size, char **av, int flag);
int		ft_strcmp(const char *s1, const char *s2);
//functions2
int		ft_push(t_stack *stack, int len, int operation);
void	ft_sort_three(t_stack *s);
void	ft_sort_bubble(int *tmp_stack, int size);
int		ft_checked_sorted(int *stack_a, int size, int flag);
void	ft_sort(t_stack *stack, int size);
//functions3
void	ft_sort_small_b(t_stack *s, int len);
void	ft_quicksort_3(t_stack *stack, int len);
int		ft_get_middle(int *pivot, int *stack_a, int size);
int		ft_quicksort_a(t_stack *stack, int len);
int		ft_quicksort_b(t_stack *stack, int len);
//rules a
void	sa(t_stack *stack, int print);
void	rra(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	pa(t_stack *stack, int print);
size_t	ft_strlen(const char *str);
//rules b
void	pb(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);

#endif