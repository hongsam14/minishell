/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:08:30 by hopark            #+#    #+#             */
/*   Updated: 2021/07/05 02:57:44 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "passing.h"

void	ft_del_lastblank(t_built *built)
{
	t_list	*temp_l;

	if (!built || !built->command)
		return ;
	temp_l = built->command;
	while (temp_l)
	{
		if (ft_strncmp(temp_l->str, " ", 1) && !(temp_l->next))
		{
			ft_listdelone(&temp_l);
			return ;
		}
		temp_l = temp_l->next;
	}
}

void	ft_del_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;

	if (!built)
		return ;
	temp_l = built->command;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (ft_strlen(temp_l->str) == 0)
			ft_listdelone(&temp_l);
		temp_l = temp_l2;
	}
}

void	ft_del_blank2(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;

	if (built)
		return ;
	temp_l = built->command;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (ft_strncmp(temp_l->str, " ", 1))
			ft_listdelone(&temp_l);
		temp_l = temp_l2;
	}
}
