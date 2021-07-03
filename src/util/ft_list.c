/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:01 by hopark            #+#    #+#             */
/*   Updated: 2021/07/03 19:18:48 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*ft_listnew(char *str, char *id)
{
	t_list		*res;

	if (!ft_malloc(&res, sizeof(t_list)))
	{
		return (0);
	}
	res->str = str;
	res->id = id;
	res->next = res;
	res->prev = res;
	return (res);
}

t_list	*ft_listnew2(char *str, char *id)
{
	t_list		*res;

	if (!ft_malloc(&res, sizeof(t_list)))
	{
		return (0);
	}
	res->str = str;
	res->id = id;
	res->next = 0;
	res->prev = 0;
	return (res);
}

void	ft_listadd_back(t_list **list, t_list **new)
{
	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*list) = (*new);
		(*list)->next = (*list);
		(*list)->prev = (*list);
	}
	else
	{
		(*list)->next->prev = (*new);
		(*new)->prev = (*list);
		(*new)->next = (*list)->next;
		(*list)->next = (*new);
	}
}

void	ft_listadd_tail(t_list **list, t_list **new)
{
	t_list		*temp;

	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*list) = (*new);
		(*list)->next = 0;
		(*list)->prev = 0;
	}
	else
	{
		temp = (*list);
		while (temp->next)
			temp = temp->next;
		if (temp->next)
			temp->next->prev = (*new);
		(*new)->prev = temp;
		(*new)->next = temp->next;
		temp->next = (*new);
	}
}

void	ft_listdelone(t_list **list)
{
	if ((*list) == 0)
		return ;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	if ((*list)->prev)
		(*list)->prev->next = (*list)->next;
	ft_free((*list)->id);
	ft_free((*list)->str);
	ft_free(*list);
	(*list) = 0;
}
