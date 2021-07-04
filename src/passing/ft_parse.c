#include "head.h"

void	ft_put_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*new;
	char	*str;

	temp_l = built->command;
	while (temp_l)
	{
		if (!ft_strncmp(temp_l->str, " ", 1) && temp_l->next && \
			!ft_strncmp(temp_l->next->str, " ", 1))
		{
			str = ft_strndup(" ", 1);
			new = ft_listnew(str, 0);
			ft_listadd_back(&temp_l, &new);
		}
		temp_l = temp_l->next;
	}
}
