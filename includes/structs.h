/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:36:39 by kabasolo          #+#    #+#             */
/*   Updated: 2024/08/13 17:55:13 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tokens
{
	char			**cmd;
	char			*path;
	char			**files;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_data
{
	char			**pipe_split;
	struct s_tokens	*tokens;
}	t_data;

typedef struct s_directory
{
	char			*directory;
	struct s_directory	*next;
}	t_directory;

#endif //STRUCTS_H