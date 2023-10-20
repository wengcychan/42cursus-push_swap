/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:21:46 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 16:58:17 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack stack, int print)
{
	int	tmp;

	if (stack.len != 0 && stack.len != 1)
	{
		tmp = stack.array[0];
		stack.array[0] = stack.array[1];
		stack.array[1] = tmp;
		if (print == 1)
			print_instruction("s", stack);
	}
}

void	ft_push(t_stack *stack_to, t_stack *stack_from, int print)
{
	int	i;

	if (stack_from->len != 0)
	{
		i = stack_to->len;
		while (i > 0)
		{
			stack_to->array[i] = stack_to->array[i - 1];
			i--;
		}
		stack_to->array[0] = stack_from->array[0];
		stack_to->len++;
		i = 0;
		while (i < stack_from->len - 1)
		{
			stack_from->array[i] = stack_from->array[i + 1];
			i++;
		}
		stack_from->len--;
		if (print == 1)
			print_instruction("p", *stack_to);
	}
}

void	ft_rotate(t_stack stack, int print)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack.array[0];
	while (i < stack.len - 1)
	{
		stack.array[i] = stack.array[i + 1];
		i++;
	}
	stack.array[stack.len - 1] = tmp;
	if (print == 1)
		print_instruction("r", stack);
}

void	ft_reverse_rotate(t_stack stack, int print)
{
	int	i;
	int	tmp;

	i = stack.len - 1;
	tmp = stack.array[stack.len - 1];
	while (i > 0)
	{
		stack.array[i] = stack.array[i - 1];
		i--;
	}
	stack.array[0] = tmp;
	if (print == 1)
		print_instruction("rr", stack);
}

void	print_instruction(char *instruction, t_stack stack)
{
	write(1, instruction, ft_strlen(instruction));
	write(1, &stack.name, 1);
	write(1, "\n", 1);
}
