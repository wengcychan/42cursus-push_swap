/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:55:12 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 17:48:31 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elem_front(t_stack *stack_to, t_stack *stack_from,
			t_nbr_elem *nbr_elem, int *push_elem_count)
{
	if (compare_median(*stack_from, stack_from->array[0],
			stack_from->median))
	{
		ft_push(stack_to, stack_from, 1);
		(*push_elem_count)++;
	}
	else if (nbr_elem->front == 2 && compare_median(*stack_from,
			stack_from->array[1], stack_from->median))
	{
		ft_swap(*stack_from, 1);
		ft_push(stack_to, stack_from, 1);
		(*push_elem_count)++;
	}
	else
	{
		ft_rotate(*stack_from, 1);
		if (nbr_elem->front + nbr_elem->back != stack_from->len)
			(nbr_elem->back)++;
	}
	if (nbr_elem->front + nbr_elem->back != stack_from->len)
		(nbr_elem->front)--;
}

void	push_elem_back(t_stack *stack_to, t_stack *stack_from,
		t_nbr_elem *nbr_elem, int *push_elem_count)
{
	if (compare_median(*stack_from,
			stack_from->array[stack_from->len - 1], stack_from->median))
	{
		ft_reverse_rotate(*stack_from, 1);
		(nbr_elem->back)--;
		ft_push(stack_to, stack_from, 1);
		(*push_elem_count)++;
	}
	else
	{
		ft_reverse_rotate(*stack_from, 1);
		(nbr_elem->back)--;
		(nbr_elem->front)++;
	}
}

int	compare_median(t_stack stack, int current_elem, int median)
{
	if (current_elem < median)
	{
		if (stack.name == 'a')
			return (1);
		else
			return (0);
	}
	else
	{
		if (stack.name == 'a')
			return (0);
		else
			return (1);
	}
}

void	push_and_sort_stack_b(t_stack *stack_a, t_stack *stack_b,
			t_nbr_elem nbr_elem)
{
	if (nbr_elem.front + nbr_elem.back == stack_b->len)
	{
		nbr_elem.front = nbr_elem.front + nbr_elem.back;
		nbr_elem.back = 0;
	}
	if (nbr_elem.front + nbr_elem.back == 3)
		sort_three_stack_b(stack_b, stack_a, nbr_elem);
	else if (nbr_elem.front + nbr_elem.back == 2)
	{
		if (nbr_elem.back == 2)
			ft_reverse_rotate(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		if (nbr_elem.back == 2 || (nbr_elem.front == 1 && nbr_elem.back == 1))
			ft_reverse_rotate(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
		if (stack_a->array[0] > stack_a->array[1])
			ft_swap(*stack_a, 1);
	}
	else if (nbr_elem.front + nbr_elem.back == 1)
	{
		if (nbr_elem.back == 1)
			ft_reverse_rotate(*stack_b, 1);
		ft_push(stack_a, stack_b, 1);
	}
}
