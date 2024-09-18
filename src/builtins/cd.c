/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:34:13 by muribe-l          #+#    #+#             */
/*   Updated: 2024/09/18 13:31:19 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Change directory function */
void	built_cd(char *dir, int fd)
{
	char	*export;
	char	*old;

	old = getcwd(NULL, 0);
	if (!dir || ft_strcmp(dir, "~") == 0)
		dir = getenv("HOME");
	if (chdir(dir) != 0)
		ft_dprintf(fd, "%s\n", strerror(errno));
	dir = getcwd(NULL, 0);
	export = malloc(sizeof(char) * (ft_strlen(dir) + 5));
	if (!export)
		return ;
	ft_strlcpy(export, "PWD=", 5);
	ft_strlcat(export, dir, ft_strlen(dir) + ft_strlen(export) + 1);
	built_export(export, fd);
	export = malloc(sizeof(char) * (ft_strlen(old) + 8));
	if (!export)
		return ;
	ft_strlcpy(export, "OLDPWD=", 8);
	ft_strlcat(export, old, ft_strlen(old) + ft_strlen(export) + 1);
	built_export(export, fd);
	free(export);
}
