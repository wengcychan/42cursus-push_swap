/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:46:58 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 17:47:52 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stack *stack_to, t_stack *stack_from,
			t_nbr_elem nbr_elem, int check_a_len)
{
	if (stack_from->name == 'a')
	{
		if (check_a_len == 3)
			sort_three_stack_a(stack_from, stack_to, nbr_elem.back);
		if (check_a_len == 2 && nbr_elem.back == 2)
		{
			ft_reverse_rotate(*stack_from, 1);
			ft_reverse_rotate(*stack_from, 1);
		}
		if ((check_a_len == 1 || check_a_len == 2) && nbr_elem.back == 1)
			ft_reverse_rotate(*stack_from, 1);
		if (check_a_len == 2 && stack_from->array[0] > stack_from->array[1])
			ft_swap(*stack_from, 1);
	}
	else
	{
		if (check_a_len == 3)
			sort_three_stack_a(stack_to, stack_from, 0);
		if (check_a_len == 2 && stack_to->array[0] > stack_to->array[1])
			ft_swap(*stack_to, 1);
	}
}

void	sort_three_stack_a(t_stack *stack_a,
			t_stack *stack_b, int nbr_elem_back)
{
	initialize_sort_stack(stack_a, nbr_elem_back);
	if (stack_a->sort_elem[1] < stack_a->sort_elem[2]
		&& stack_a->sort_elem[0] < stack_a->sort_elem[2])
	{
		if (nbr_elem_back == 3)
			ft_reverse_rotate(*stack_a, 1);
		if (nbr_elem_back == 3 || nbr_elem_back == 2)
			ft_reverse_rotate(*stack_a, 1);
		if (nbr_elem_back == 3 || nbr_elem_back == 2 || nbr_elem_back == 1)
			ft_reverse_rotate(*stack_a, 1);
		if (stack_a->array[0] > stack_a->array[1])
			ft_swap(*stack_a, 1);
		return ;
	}
	if (stack_a->len > 3)
	{
		if (stack_a->sort_elem[0] < stack_a->sort_elem[1])
			sort_three_stack_a_larger_second_elem(stack_a, nbr_elem_back);
		else
			sort_three_stack_a_larger_first_elem(stack_a,
				stack_b, nbr_elem_back);
	}
	else
		sort_three_stack_a_small(stack_a);
}

void	sort_three_stack_a_larger_second_elem(t_stack *stack_a,
		int nbr_elem_back)
{
	if (nbr_elem_back == 3)
		ft_reverse_rotate(*stack_a, 1);
	if (nbr_elem_back == 3 || nbr_elem_back == 2)
		ft_reverse_rotate(*stack_a, 1);
	if (nbr_elem_back == 0)
		ft_rotate(*stack_a, 1);
	ft_swap(*stack_a, 1);
	ft_reverse_rotate(*stack_a, 1);
	if (stack_a->array[0] > stack_a->array[1])
		ft_swap(*stack_a, 1);
}

void	sort_three_stack_a_larger_first_elem(t_stack *stack_a,
			t_stack *stack_b, int nbr_elem_back)
{
	if (nbr_elem_back == 3)
		ft_reverse_rotate(*stack_a, 1);
	if (nbr_elem_back == 3 || nbr_elem_back == 2)
		ft_reverse_rotate(*stack_a, 1);
	if (nbr_elem_back == 3 || nbr_elem_back == 2
		|| nbr_elem_back == 1)
	{
		ft_push(stack_b, stack_a, 1);
		ft_reverse_rotate(*stack_a, 1);
		ft_swap(*stack_a, 1);
		ft_push(stack_a, stack_b, 1);
	}
	else
	{
		ft_swap(*stack_a, 1);
		ft_rotate(*stack_a, 1);
		ft_swap(*stack_a, 1);
		ft_reverse_rotate(*stack_a, 1);
	}
	if (stack_a->array[0] > stack_a->array[1])
		ft_swap(*stack_a, 1);
}

void	sort_three_stack_a_small(t_stack *stack)
{
	if (stack->array[0] < stack->array[1]
		&& stack->array[1] > stack->array[2]
		&& stack->array[0] < stack->array[2])
	{
		ft_reverse_rotate(*stack, 1);
		ft_swap(*stack, 1);
	}
	else if (stack->array[0] < stack->array[1]
		&& stack->array[1] > stack->array[2]
		&& stack->array[0] > stack->array[2])
		ft_reverse_rotate(*stack, 1);
	else if (stack->array[0] > stack->array[1]
		&& stack->array[1] < stack->array[2]
		&& stack->array[0] > stack->array[2])
		ft_rotate(*stack, 1);
	else
	{
		ft_swap(*stack, 1);
		ft_reverse_rotate(*stack, 1);
	}
}
