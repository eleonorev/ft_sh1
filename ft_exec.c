/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:21:35 by evoisin           #+#    #+#             */
/*   Updated: 2015/02/06 17:21:41 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				ft_exect(t_sh *t, char **av)
{
	char *const *envp;
	int			rc;
	pid_t		father;
	char		*cmd;

	father = fork();
	envp = t->env;
	if (father > 0)
		waitpid(father, NULL, 0);
	if (father == 0)
	{
		if ((cmd = ft_search_cmd(av, t->env)) == NULL)
		{
			ft_putstr("zsh: command not found:");
			ft_putendl(av[0]);
			return (-1);
		}
		rc = execve(cmd, av, envp);
	}
	kill(father, SIGUSR1);
	return (rc);
}

int				ft_cd(const char *path, t_sh *t)
{
	int			i;
	char		*oldpwd;

	oldpwd = 0;
	oldpwd = getcwd(oldpwd, 1024);
	if (!path)
	{
		chdir(ft_varpath(t, "HOME"));
		i = 1;
	}
	else
		i = chdir(path);
	ft_setenv(t->env, ft_strjoin("OLDPWD=", oldpwd + 13), 1, t);
	oldpwd = getcwd(oldpwd, 1024);
	ft_setenv(t->env, ft_strjoin("PWD=", oldpwd + 13), 1, t);
	if (i < 0)
	{
		ft_putstr("cd:cd:13: no such file or directory:");
		ft_putendl(path);
	}
	return (i);
}

int				tablen(char **line)
{
	int			i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

char			**filltab(char **env, char *line)
{
	char		**tab;
	int			i;

	i = 0;
	while (env[i])
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (0);
	tab = env;
	if (!(tab[i] = (char *)malloc(sizeof(char) * ft_strlen(line))))
		return (0);
	tab[i] = line;
	tab[i + 1] = 0;
	return (tab);
}

char			**ft_remove(char **tab, int asupp)
{
	char		**tab2;
	int			i;
	int			x;

	x = 0;
	i = 0;
	if (!(tab2 = (char **)malloc(sizeof(char *) * tablen(tab))))
		return (0);
	while (i < tablen(tab))
	{
		if (i == asupp)
			i++;
		tab2[x] = tab[i];
		x++;
		i++;
	}
	tab2[x] = 0;
	return (tab2);
}
