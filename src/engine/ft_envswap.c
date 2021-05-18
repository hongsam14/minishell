/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:31:31 by hopark            #+#    #+#             */
/*   Updated: 2021/05/18 12:56:32 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	ft_envlen(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (ft_strchr("$ ><|;", str[i]))
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strswap(t_list *list, char *old, char *new, int oldlen)
{
	char	*res;

	if (!ft_malloc(&res, sizeof(ft_strlen(list->str) \
									- oldlen + ft_strlen(new))))
		return (0);
	ft_memcpy(res, list->str, old - list->str);
	ft_memcpy(res + (old - list->str), new, ft_strlen(new));
	ft_memcpy(res + (old - list->str) + ft_strlen(new), old + oldlen + 1, \
												ft_strlen(old + oldlen));
	res[ft_strlen(list->str) - oldlen + ft_strlen(new)] = 0;
	ft_free(list->str);
	return (res);
}

int	*ft_envswap(t_list *env, t_list *list)
{
	t_list	*temp_l;
	char	*temp_c;
	char	len;
	char	*new;

	temp_l = list;
	while (temp_l)
	{
		temp_c = ft_strchr(temp_l->str, '$');
		if (temp_c)
		{
			len = ft_envlen(temp_c);
			while (--len)
			{
				new = ft_getenv(env, temp_c + 1, len);
				if (new)
					break ;
			}
			temp_l->str = ft_strswap(temp_l, temp_c, new, len);
		}
		else
			temp_l = temp_l->next;
	}
	return (0);
}
