/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 00:07:35 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/20 00:07:41 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() 
{
    char *binaryPath = "/bin/bash";
    char *args[] = {binaryPath, "-c", "echo visit $HOSTNAME:Fun with your browser", NULL};
    char *const env[] = {"HOSTNAME=www.delftstack.com", "PORT=8080", NULL};
    if (execve(binaryPath, args, env) == -1) {
        perror("execve failed");
    }
    return 1;
}
