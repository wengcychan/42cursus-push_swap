/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_read_input_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:29:10 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 16:30:56 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	long		res;
	int			sign;
	const char	*ptr_str;

	res = 0;
	sign = 1;
	ptr_str = str;
	while (*ptr_str == 32 || (*ptr_str >= 9 && *ptr_str <= 13))
		ptr_str++;
	if (*ptr_str == '-')
		sign *= -1;
	if (*ptr_str == '-' || *ptr_str == '+')
		ptr_str++;
	while (*ptr_str >= '0' && *ptr_str <= '9')
	{
		res = res * 10 + *ptr_str - '0';
		ptr_str++;
	}
	return (res * sign);
}

int	count_split(char **begin)
{
	int	count;

	count = 0;
	while (*begin != NULL)
	{
		count++;
		begin++;
	}
	return (count);
}

void	free_split(char **begin)
{
	int	i;

	i = 0;
	while (i < count_split(begin) + 1)
	{
		free(begin[i]);
		i++;
	}
	free(begin);
}

void	initialize_value(t_stack *stack_a, t_stack *stack_b,
			t_nbr_elem *nbr_elem)
{
	nbr_elem->front = stack_a->len;
	nbr_elem->back = 0;
	stack_b->len = 0;
	stack_a->name = 'a';
	stack_b->name = 'b';
}
