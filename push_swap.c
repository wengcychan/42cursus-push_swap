/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:59:18 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 17:48:31 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_nbr_elem	nbr_elem;

	if (argc < 2 || (argc == 2 && !ft_strncmp(argv[1], "", 1)))
	{
		ft_putstr_fd("Invalid Input\n", 2);
		return (1);
	}
	if (initialize_stack(&stack_a, &stack_b, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (is_sorted(stack_a))
	{
		free(stack_a.array);
		free(stack_b.array);
		return (0);
	}
	initialize_value(&stack_a, &stack_b, &nbr_elem);
	push_swap(&stack_b, &stack_a, nbr_elem);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}

void	push_swap(t_stack *stack_to, t_stack *stack_from, t_nbr_elem nbr_elem)
{
	int			check_a_len;
	t_nbr_elem	to_nbr_elem;

	stack_to->prev_lev = stack_to->len;
	if (nbr_elem.front + nbr_elem.back > 3)
		separate_half(stack_to, stack_from, &nbr_elem);
	if (stack_from->name == 'a')
		check_a_len = nbr_elem.front + nbr_elem.back;
	else
		check_a_len = stack_to->len - stack_to->prev_lev;
	to_nbr_elem.front = stack_to->len - stack_to->prev_lev;
	to_nbr_elem.back = 0;
	if (check_a_len <= 3)
	{
		sort_stack_a(stack_to, stack_from, nbr_elem, check_a_len);
		if (stack_from->name == 'a')
			handle_stack_b(stack_from, stack_to, to_nbr_elem);
		else
			handle_stack_b(stack_to, stack_from, nbr_elem);
		return ;
	}
	else
		separate_stack_a(stack_to, stack_from,
			nbr_elem, to_nbr_elem);
}

void	separate_half(t_stack *stack_to, t_stack *stack_from,
			t_nbr_elem *nbr_elem)
{
	int	push_elem_count;
	int	total_nbr_elem;
	int	median_pos;

	if (nbr_elem->front + nbr_elem->back == stack_from->len)
	{
		nbr_elem->front = nbr_elem->front + nbr_elem->back;
		nbr_elem->back = 0;
	}
	stack_from->median = get_median(*stack_from, *nbr_elem);
	total_nbr_elem = nbr_elem->front + nbr_elem->back;
	if (stack_from->name == 'b' && total_nbr_elem % 2 == 1)
		total_nbr_elem++;
	push_elem_count = 0;
	median_pos = find_median_pos(*stack_from,
			nbr_elem->front, stack_from->median);
	while (nbr_elem->front > median_pos && push_elem_count < total_nbr_elem / 2)
		push_elem_front(stack_to, stack_from, nbr_elem, &push_elem_count);
	while (nbr_elem->back > 0 && push_elem_count < total_nbr_elem / 2)
		push_elem_back(stack_to, stack_from, nbr_elem, &push_elem_count);
}

void	handle_stack_b(t_stack *stack_a, t_stack *stack_b,
		t_nbr_elem nbr_elem)
{
	if (nbr_elem.front + nbr_elem.back > 3)
		push_swap(stack_a, stack_b, nbr_elem);
	else
		push_and_sort_stack_b(stack_a, stack_b, nbr_elem);
}

void	separate_stack_a(t_stack *stack_to, t_stack *stack_from,
		t_nbr_elem nbr_elem, t_nbr_elem to_nbr_elem)
{
	if (stack_from->name == 'a')
	{
		push_swap(stack_to, stack_from, nbr_elem);
		handle_stack_b(stack_from, stack_to, to_nbr_elem);
	}
	else
	{
		push_swap(stack_from, stack_to, to_nbr_elem);
		handle_stack_b(stack_to, stack_from, nbr_elem);
	}
}
