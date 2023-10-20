/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:45:50 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 16:55:29 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_stack_b(t_stack *stack_b, t_stack *stack_a,
		t_nbr_elem nbr_elem)
{
	initialize_sort_stack(stack_b, nbr_elem.back);
	if (nbr_elem.front + nbr_elem.back == stack_b->len)
	{
		nbr_elem.front = nbr_elem.front + nbr_elem.back;
		nbr_elem.back = 0;
	}
	if (stack_b->sort_elem[0] > stack_b->sort_elem[2])
		sort_three_stack_b_first_elem_larger_than_third(stack_b,
			stack_a, nbr_elem);
	if (stack_b->len > 3)
	{
		if (stack_b->sort_elem[0] < stack_b->sort_elem[1]
			&& stack_b->sort_elem[0] < stack_b->sort_elem[2])
			sort_three_stack_b_smallest_first_elem(stack_b, stack_a, nbr_elem);
		else if (stack_b->sort_elem[0] > stack_b->sort_elem[1]
			&& stack_b->sort_elem[1] < stack_b->sort_elem[2]
			&& stack_b->sort_elem[0] < stack_b->sort_elem[2])
			sort_three_stack_b_smallest_second_elem(stack_b, stack_a, nbr_elem);
	}
	else
	{
		if (stack_b->len > 0)
			sort_three_stack_b_small(stack_b, stack_a);
	}
}

void	sort_three_stack_b_first_elem_larger_than_third(t_stack *stack_b,
			t_stack *stack_a, t_nbr_elem nbr_elem)
{
	if (nbr_elem.back == 3)
		ft_reverse_rotate(*stack_b, 1);
	if (nbr_elem.back == 3 || nbr_elem.back == 2)
		ft_reverse_rotate(*stack_b, 1);
	if (nbr_elem.back == 3 || nbr_elem.back == 2 || nbr_elem.back == 1)
		ft_reverse_rotate(*stack_b, 1);
	ft_push(stack_a, stack_b, 1);
	if (stack_b->sort_elem[0] > stack_b->sort_elem[1]
		&& stack_b->sort_elem[1] < stack_b->sort_elem[2])
		ft_swap(*stack_b, 1);
	ft_push(stack_a, stack_b, 1);
	if (stack_b->sort_elem[0] < stack_b->sort_elem[1]
		&& stack_b->sort_elem[1] > stack_b->sort_elem[2])
		ft_swap(*stack_a, 1);
	ft_push(stack_a, stack_b, 1);
}

void	sort_three_stack_b_smallest_first_elem(t_stack *stack_b,
			t_stack *stack_a,
		t_nbr_elem nbr_elem)
{
	if (nbr_elem.back == 3)
	{
		ft_reverse_rotate(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		ft_reverse_rotate(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		if (stack_a->array[0] > stack_a->array[1])
			ft_swap(*stack_a, 1);
	}
	if (nbr_elem.back == 2 || nbr_elem.back == 1 || nbr_elem.back == 0)
	{
		if (nbr_elem.back == 2)
			ft_reverse_rotate(*stack_b, 1);
		if (nbr_elem.back == 0)
			ft_rotate(*stack_b, 1);
		if (stack_b->sort_elem[1] < stack_b->sort_elem[2])
			ft_swap(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		ft_push(stack_a, stack_b, 1);
	}
	ft_reverse_rotate(*stack_b, 1);
	ft_push(stack_a, stack_b, 1);
}

void	sort_three_stack_b_smallest_second_elem(t_stack *stack_b,
			t_stack *stack_a, t_nbr_elem nbr_elem)
{
	if (nbr_elem.back == 3 || nbr_elem.back == 2 || nbr_elem.back == 1)
	{
		if (nbr_elem.back == 3)
			ft_reverse_rotate(*stack_b, 1);
		if (nbr_elem.back == 1)
			ft_swap(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		ft_reverse_rotate(*stack_b, 1);
		if (nbr_elem.back == 3 || nbr_elem.back == 2)
			ft_reverse_rotate(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		ft_push(stack_a, stack_b, 1);
	}
	else
	{
		ft_push(stack_a, stack_b, 1);
		ft_swap(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		ft_swap(*stack_a, 1);
		ft_push(stack_a, stack_b, 1);
	}
}

void	sort_three_stack_b_small(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b->sort_elem[0] < stack_b->sort_elem[1])
		ft_rotate(*stack_b, 1);
	if (stack_b->sort_elem[0] < stack_b->sort_elem[1]
		&& stack_b->sort_elem[1] < stack_b->sort_elem[2])
		ft_swap(*stack_b, 1);
	if (stack_b->sort_elem[0] > stack_b->sort_elem[1]
		&& stack_b->sort_elem[1] < stack_b->sort_elem[2])
		ft_reverse_rotate(*stack_b, 1);
	ft_push(stack_a, stack_b, 1);
	ft_push(stack_a, stack_b, 1);
	ft_push(stack_a, stack_b, 1);
}
