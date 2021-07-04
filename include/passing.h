#ifndef PASSING_H
# define PASSING_H
# include "head.h"

void		ft_del_blank(t_built *built);
void		ft_del_blank2(t_built *built);
void		ft_del_lastblank(t_built *built);
void		ft_del_blank3(t_built *built);
int			*ft_del_quotes(t_list *list);

void		ft_envswap(t_list *list, t_list *env_list);

void		ft_init_get_line(int *cursor, int *len);
void		ft_get_line(void);
void		ft_put_blank(t_built *built);
t_built		*ft_parse(char *line, t_list *env_list);
int			ft_split_built(t_built *built, char *str);
t_list		*ft_split2(char *str, char c);
int			ft_check_syntax(char *str);

#endif
// 'ab''"t"'"'t'"cd''ff
// 'ab''""'"''"ab''cc
// ab'""'"''"ab''cc
// ab"""''"ab''cc
// ab""''ab''cc
// ab""''abcc
// ab"t"'t'cdff
// ab't''t'cdff
// 'ab'@'"t"'@"'t'"cd''ff
// ab'""'''bc'""'
// 'ab'@'"t"'@"'t'"cd''ff
// ab@"t"@'t'cdff

// ab  ""    "''"   ab''  cc
// ab'  ['""']    "''"   ab''  cc

