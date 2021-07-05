#ifndef PASSING_H
# define PASSING_H
# include "head.h"

void		ft_del_blank(t_built *built);
void		ft_del_blank2(t_built *built);
void		ft_del_lastblank(t_built *built);
void		ft_del_quotes(t_list *list);
int			ft_isenv(char c);
void		ft_envswap(t_list *list, t_list *env_list);
void		ft_init_get_line(int *cursor, int *len);
void		ft_get_line(void);
void		ft_put_blank(t_built *built);
int			ft_split_built(t_built *built, char *str);
int			ft_check_syntax(char *str);
int			ft_check_quotes(char c, int *q_tmp);
t_list		*ft_token_split(char *str);

#endif
