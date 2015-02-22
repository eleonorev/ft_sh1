/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:19:20 by evoisin           #+#    #+#             */
/*   Updated: 2015/02/05 16:19:55 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>

typedef struct	s_sh
{
	char		*path;
	char		*prompt;
	char		**env;
}				t_sh;

int				ft_exect(t_sh *t, char **av);
int				ft_cd(const char *path, t_sh *t);
void			ft_comp(char **mline, t_sh *t);
char			**filltab(char **env, char *line);
void			ft_setenv(char	**env, char *line, int x, t_sh *t);
char			**ft_remove(char **env, int asupp);
int				tablen(char **line);
char			*ft_varpath(t_sh *t, char *str);
int				ft_error(char *str);
char			*ft_search_cmd(char **argss, char **list_env);
void			try_exec(t_sh *t, char **line);
void			reaff(int a);
void			ft_signal(void);

#endif
