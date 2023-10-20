/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:52:11 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 16:45:56 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_sort_stack(t_stack *stack_a, int nbr_elem_back)
{
	int	i;

	if (nbr_elem_back >= 0 && nbr_elem_back <= 2)
	{
		i = 0;
		while (i < 3)
		{
			stack_a->sort_elem[i] = stack_a->array[(stack_a->len 
					+ i - nbr_elem_back) % stack_a->len];
			i++;
		}
	}
	else
	{
		stack_a->sort_elem[0] = stack_a->array[stack_a->len - 3];
		stack_a->sort_elem[1] = stack_a->array[stack_a->len - 2];
		stack_a->sort_elem[2] = stack_a->array[stack_a->len - 1];
	}
}

int	get_median(t_stack stack, t_nbr_elem nbr_elem)
{
	int	i;
	int	check;

	i = 0;
	if ((nbr_elem.front + nbr_elem.back) % 2 == 0)
		check = (nbr_elem.front + nbr_elem.back) / 2 - 1;
	else
		check = (nbr_elem.front + nbr_elem.back) / 2;
	while (i < nbr_elem.front)
	{
		if (check_median(stack, nbr_elem, i, check))
			return (stack.array[i]);
		i++;
	}
	i = stack.len - 1;
	while (i > stack.len - 1 - nbr_elem.back)
	{
		if (check_median(stack, nbr_elem, i, check))
			return (stack.array[i]);
		i--;
	}
	return (stack.array[i]);
}

int	check_median(t_stack stack, t_nbr_elem nbr_elem, int i, int check)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (j < nbr_elem.front)
	{
		if (stack.array[i] < stack.array[j])
			count++;
		j++;
	}
	j = stack.len - 1;
	while (j > stack.len - 1 - nbr_elem.back)
	{
		if (stack.array[i] < stack.array[j])
			count++;
		j--;
	}
	if (count == check)
		return (1);
	return (0);
}

int	find_median_pos(t_stack stack, int nbr_elem_front, int median)
{
	int	i;
	int	median_pos;

	median_pos = 0;
	i = 0;
	if (stack.name == 'a')
	{
		while (i < nbr_elem_front)
		{
			if (stack.array[i] <= median)
				median_pos = i;
			i++;
		}
	}
	else
	{
		while (i < nbr_elem_front)
		{
			if (stack.array[i] >= median)
				median_pos = i;
			i++;
		}
	}
	return (nbr_elem_front - median_pos - 1);
}

int	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.len - 1)
	{
		if (stack.array[i] > stack.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
