/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:59:18 by wchan             #+#    #+#             */
/*   Updated: 2023/10/20 14:36:56 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2 && !ft_strncmp(argv[1], "", 1))
		return (0);
	if (initialize_stack(&stack_a, &stack_b, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit (255);
	}
	stack_b.len = 0;
	stack_a.name = 'a';
	stack_b.name = 'b';
	if (ft_get_instruction(&stack_a, &stack_b))
		exit (255);
	ft_check_answer(stack_a, stack_b);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}

int	ft_get_instruction(t_stack *stack_a, t_stack *stack_b)
{
	char	*s;

	s = get_next_line(0);
	if (!s)
		return (0);
	while (s)
	{
		if (ft_do_operation(s, stack_a, stack_b))
		{
			free(s);
			free(stack_a->array);
			free(stack_b->array);
			return (1);
		}
		free(s);
		s = get_next_line(0);
	}
	return (0);
}

int	ft_do_operation(char *s, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(s, "sa\n", 3))
		ft_swap(*stack_a, 0);
	else if (!ft_strncmp(s, "sb\n", 3))
		ft_swap(*stack_b, 0);
	else if (!ft_strncmp(s, "pa\n", 3))
		ft_push(stack_a, stack_b, 0);
	else if (!ft_strncmp(s, "pb\n", 3))
		ft_push(stack_b, stack_a, 0);
	else if (!ft_strncmp(s, "ra\n", 3))
		ft_rotate(*stack_a, 0);
	else if (!ft_strncmp(s, "rb\n", 3))
		ft_rotate(*stack_b, 0);
	else if (!ft_strncmp(s, "rra\n", 4))
		ft_reverse_rotate(*stack_a, 0);
	else if (!ft_strncmp(s, "rrb\n", 4))
		ft_reverse_rotate(*stack_b, 0);
	else if (!ft_strncmp(s, "ss\n", 3) || !ft_strncmp(s, "rr\n", 3)
		|| !ft_strncmp(s, "rrr\n", 4))
		ft_do_combine_operation(s, stack_a, stack_b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

void	ft_do_combine_operation(char *s, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(s, "ss\n", 3))
	{
		ft_swap(*stack_a, 0);
		ft_swap(*stack_b, 0);
	}
	else if (!ft_strncmp(s, "rr\n", 3))
	{
		ft_rotate(*stack_a, 0);
		ft_rotate(*stack_b, 0);
	}
	else
	{
		ft_reverse_rotate(*stack_a, 0);
		ft_reverse_rotate(*stack_b, 0);
	}
}

void	ft_check_answer(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.len != 0)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	i = 0;
	while (i < stack_a.len - 1)
	{
		if (stack_a.array[i] > stack_a.array[i + 1])
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		i++;
	}
	ft_putstr_fd("OK\n", 1);
}
