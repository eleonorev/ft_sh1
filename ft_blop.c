/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:56:42 by evoisin           #+#    #+#             */
/*   Updated: 2015/02/10 15:56:44 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		*ft_varpath(t_sh *t, char *str)
{
	int		i;

	i = 0;
	while (t->env[i])
	{
		if (ft_strnequ(str, t->env[i], ft_strlen(str)))
			return (t->env[i] + ft_strlen(str) + 1);
		i++;
	}
	return (0);
}

int			ft_error(char *str)
{
	ft_putcolor(str, RED);
	ft_putchar('\n');
	exit (-1);
	return (0);
}

void		reaff(int a)
{
	(void)a;
	ft_putcolor("\n[ft_minishell1] > ", BLUE);
}

char		*ft_search_cmd(char **argss, char **list_env)
{
	char			**path;
	int				i;
	DIR				*dir;
	struct dirent	*file;

	i = 0;
	if ((path = ft_strsplit(list_env[0], ':')) == NULL)
		return (0);
	while (path[++i] != 0)
	{
		if (!(dir = opendir(path[i])))
			break ;
		while ((file = readdir(dir)) != NULL)
		{
			if (!ft_strcmp(file->d_name, argss[0]))
				return (ft_strjoin(ft_strjoin(path[i], "/"), argss[0]));
		}
		closedir(dir);
	}
	return (0);
}

void		try_exec(t_sh *t, char **line)
{
	pid_t	father;

	if (access(line[0], X_OK) == -1 || access(line[0], F_OK) == -1)
	{
		ft_putstr("Unable to execute :");
		ft_putendl(line[0]);
		return ;
	}
	father = fork();
	if (father > 0)
		waitpid(father, NULL, 0);
	if (father == 0)
		execve(line[0], line, t->env);
	kill(father, SIGUSR1);
}
