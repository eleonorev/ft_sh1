/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:18:22 by evoisin           #+#    #+#             */
/*   Updated: 2015/02/05 16:20:10 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void			ft_setenv(char **env, char *line, int x, t_sh *t)
{
	int			i;
	int			y;

	y = -1;
	i = 0;
	while (env[++y])
	{
		while (env[y][i] == line[i])
		{
			if (env[y][i + 1] == '=' && x == 1)
			{
				t->env[y] = ft_strdup(line);
				return ;
			}
			if ((line[i + 1] == '=' || line[i + 1] == '\0') && x == 2)
			{
				t->env = ft_remove(env, y);
				return ;
			}
			i++;
		}
		i = 0;
	}
	if (x == 1 && y == tablen(env))
		t->env = filltab(env, line);
}

void			ft_affenv(char **env)
{
	while (*env)
		ft_putendl(*(env++));
}

void			ft_comp(char **line, t_sh *t)
{
	char		*tmp;

	tmp = 0;
	if (!(ft_strcmp("pwd", line[0])))
		ft_putendl(getcwd(tmp, 1024) + 13);
	else if (!(ft_strcmp(line[0], "cd")))
		ft_cd(line[1], t);
	else if (!(ft_strcmp(line[0], "env")))
		ft_affenv(t->env);
	else if (!(ft_strcmp(line[0], "setenv")))
		ft_setenv(t->env, line[1], 1, t);
	else if (!(ft_strcmp(line[0], "unsetenv")))
		ft_setenv(t->env, line[1], 2, t);
	else if ((line[0][0] == '.' && line[0][1] == '/') || line[0][0] == '/')
		try_exec(t, line);
	else
		ft_exect(t, line);
	return ;
}

int				ft_check(char *str)
{
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (-1);
	if ((i = (ft_strlen(str))) >= 1024)
		return (-1);
	if (ft_strcmp("exit", str) == 0)
		ft_error("Goodbye :(");
	return (1);
}

int				main(int ac, char **av, char **env)
{
	int			fd;
	char		*lines;
	t_sh		t;
	char		**tab;

	(void)ac;
	(void)av;
	t.path = getcwd(t.path, 1024);
	fd = 0;
	t.env = env;
	ft_signal();
	while (42)
	{
		ft_putcolor("[ft_minishell1] > ", BLUE);
		if ((fd = get_next_line(fd, &lines)) == 0)
			ft_error("exit");
		if (ft_check(lines) < 1)
			continue ;
		lines = ft_strtrim(lines);
		tab = ft_strsplit(lines, ' ');
		ft_comp(tab, &t);
		free(lines);
	}
	return (0);
}
