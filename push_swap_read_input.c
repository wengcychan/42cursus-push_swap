/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_read_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:29:10 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 18:03:07 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_stack(t_stack *stack_a, t_stack *stack_b,
		int argc, char **argv)
{
	char	**split;
	int		nbr_elem;

	split = ft_split(argv[1], ' ');
	if (!split)
		return (1);
	if (count_split(split) > 1)
		nbr_elem = count_split(split);
	else
		nbr_elem = argc - 1;
	if (count_split(split) > 1 && argc > 2)
	{
		free_split(split);
		return (1);
	}
	if (initialize_stack_a(stack_a, nbr_elem, argv, split))
	{
		free_split(split);
		return (1);
	}
	if (initialize_stack_b(stack_a, stack_b, nbr_elem, split))
		return (1);
	free_split(split);
	return (0);
}

int	initialize_stack_a(t_stack *stack_a, int nbr_elem,
		char **argv, char **split)
{
	int	i;

	stack_a->array = (int *)malloc(sizeof(int) * nbr_elem);
	if (!stack_a->array)
		return (1);
	if (count_split(split) > 1)
		argv = split;
	else
		argv++;
	i = 0;
	while (i < nbr_elem)
	{
		if (!is_valid_nbr(i, argv))
		{
			free(stack_a->array);
			return (1);
		}
		i++;
	}
	if (check_fill_input(stack_a, nbr_elem, argv))
	{
		free(stack_a->array);
		return (1);
	}
	return (0);
}

int	is_valid_nbr(int i, char **input)
{
	int	j;
	int	s_len;

	j = 0;
	s_len = ft_strlen(input[i]);
	if (s_len == 0)
		return (0);
	while (j < s_len)
	{
		if (ft_isdigit(input[i][j]) == 0 &&
			!(input[i][j] == '-' || input[i][j] == '+'))
			return (0);
		if ((input[i][0] == '-' || input[i][0] == '+') && s_len == 1)
			return (0);
		if (input[i][j] == '-' || input[i][j] == '+')
		{
			if (j != 0)
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_fill_input(t_stack *stack, int nbr_elem, char **input)
{
	int		i;
	int		j;
	long	elem;

	i = 0;
	while (i < nbr_elem)
	{
		elem = ft_atoi_long(input[i]);
		if (elem < INT_MIN || elem > INT_MAX)
			return (1);
		stack->array[i] = elem;
		j = 0;
		while (j < i)
		{
			if (stack->array[j] == elem)
				return (1);
			j++;
		}
		i++;
	}
	stack->len = nbr_elem;
	return (0);
}

int	initialize_stack_b(t_stack *stack_a, t_stack *stack_b,
		int nbr_elem, char **split)
{
	stack_b->array = (int *)malloc(sizeof(int) * nbr_elem);
	if (!stack_b->array)
	{
		free(stack_a->array);
		free_split(split);
		return (1);
	}
	ft_bzero(stack_b->array, nbr_elem);
	return (0);
}
