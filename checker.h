/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:59:18 by wchan             #+#    #+#             */
/*   Updated: 2023/03/22 15:09:17 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		ft_get_instruction(t_stack *stack_a, t_stack *stack_b);
int		ft_do_operation(char *s, t_stack *stack_a, t_stack *stack_b);
void	ft_do_combine_operation(char *s, t_stack *stack_a, t_stack *stack_b);
void	ft_check_answer(t_stack stack_a, t_stack stack_b);

#endif