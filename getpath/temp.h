/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:23:16 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/22 16:27:40 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_H
# define TEMP_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <string.h>

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);

#endif