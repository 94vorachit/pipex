/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:02:30 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 21:06:43 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd[3];
    
    if (pipe(fd) == -1) 
    {
        perror("pipe failed");
        exit(1);
    }

    char msg[] = "Hello, child!";
    write(fd[1], msg, sizeof(msg));

    char buffer[100];
    read(fd[0], buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    return (0);
}
