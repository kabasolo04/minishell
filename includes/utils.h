/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:28:39 by kabasolo          #+#    #+#             */
/*   Updated: 2024/09/25 15:46:25 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <wait.h>
# include <signal.h>
# include <stdbool.h>
# include <termios.h>

# define RESET "\001\e[0m\002"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"

// Status errors
# define MALLOC_ERROR 42
# define EXIT_STATUS 66

enum
{
	READ,
	EDIT,
	DEL,
	FREE,
	MEM
};

int		len_for(char *line, char c);
int		closest(char *line, char *limits);
void	free_tokens(t_tokens **tokens);
void	add_token_back(t_tokens **lst, t_tokens *new);
char	**mod_split(char *line, char c);
int		blank(char *line);
char	*get_env(char **envp, char *name);
char	*mod_join(char *s1, char *s2);
char	*copy_n(char *line, int n);
char	*stringify(char c);

#endif //UTILS_H