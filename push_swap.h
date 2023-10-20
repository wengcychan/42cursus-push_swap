/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:43 by wchan             #+#    #+#             */
/*   Updated: 2023/09/20 17:58:55 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int		*array;
	int		len;
	char	name;
	int		median;
	int		sort_elem[3];
	int		prev_lev;
}			t_stack;

typedef struct s_nbr_elem
{
	int		front;
	int		back;
}			t_nbr_elem;

void		push_swap(t_stack *stack_to, t_stack *stack_from,
				t_nbr_elem nbr_elem);
void		separate_half(t_stack *stack_to, t_stack *stack_from,
				t_nbr_elem *nbr_elem);
void		handle_stack_b(t_stack *stack_a, t_stack *stack_b,
				t_nbr_elem nbr_elem);
void		separate_stack_a(t_stack *stack_to, t_stack *stack_from,
				t_nbr_elem nbr_elem, t_nbr_elem to_nbr_elem);
int			initialize_stack(t_stack *stack_a, t_stack *stack_b,
				int argc, char **argv);
int			initialize_stack_a(t_stack *stack_a, int nbr_elem,
				char **argv, char **split);
int			is_valid_nbr(int i, char **input);
int			check_fill_input(t_stack *stack, int nbr_elem, char **input);
int			initialize_stack_b(t_stack *stack_a, t_stack *stack_b,
				int nbr_elem, char **split);
long		ft_atoi_long(const char *str);
int			count_split(char **begin);
void		free_split(char **begin);
void		initialize_value(t_stack *stack_a, t_stack *stack_b,
				t_nbr_elem *nbr_elem);
void		push_elem_front(t_stack *stack_to, t_stack *stack_from,
				t_nbr_elem *nbr_elem, int *push_elem_count);
void		push_elem_back(t_stack *stack_to, t_stack *stack_from,
				t_nbr_elem *nbr_elem, int *push_elem_count);
int			compare_median(t_stack stack, int current_elem, int median);
void		push_and_sort_stack_b(t_stack *stack_a, t_stack *stack_b,
				t_nbr_elem nbr_elem);
void		sort_stack_a(t_stack *stack_to, t_stack *stack_from,
				t_nbr_elem nbr_elem, int check_a_len);
void		sort_three_stack_a(t_stack *stack_a, t_stack *stack_b,
				int nbr_elem_back_stack_a);
void		sort_three_stack_a_larger_second_elem(t_stack *stack_a,
				int nbr_elem_back);
void		sort_three_stack_a_larger_first_elem(t_stack *stack_a,
				t_stack *stack_b, int nbr_elem_back);
void		sort_three_stack_a_small(t_stack *stack);
void		sort_three_stack_b(t_stack *stack_b, t_stack *stack_a,
				t_nbr_elem nbr_elem);
void		sort_three_stack_b_first_elem_larger_than_third(t_stack *stack_b,
				t_stack *stack_a, t_nbr_elem nbr_elem);
void		sort_three_stack_b_smallest_first_elem(t_stack *stack_b,
				t_stack *stack_a, t_nbr_elem nbr_elem);
void		sort_three_stack_b_smallest_second_elem(t_stack *stack_b,
				t_stack *stack_a, t_nbr_elem nbr_elem);
void		sort_three_stack_b_small(t_stack *stack_b, t_stack *stack_a);
void		initialize_sort_stack(t_stack *stack_a, int nbr_elem_back);
int			get_median(t_stack stack, t_nbr_elem nbr_elem);
int			check_median(t_stack stack, t_nbr_elem nbr_elem,
				int i, int check);
int			find_median_pos(t_stack stack, int nbr_elem_front, int median);
int			is_sorted(t_stack stack);
void		ft_swap(t_stack stack, int print);
void		ft_push(t_stack *stack_to, t_stack *stack_from, int print);
void		ft_rotate(t_stack stack, int print);
void		ft_reverse_rotate(t_stack stack, int print);
void		print_instruction(char *instruction, t_stack stack);

#endif