/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 00:54:23 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/20 00:59:21 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *ar[])
{
  	printf("This is the first line\n");
  	char *binaryPath = "/bin/bash";
  	char name[80] = "/home/acer/42_code/myGit/pipex/execve/test";
  	strcat(name, ar[1]);
  	char *args[] = {binaryPath, "-c", name, NULL};
  	char *env_args[] = {"/bin/bash", (char *)0};
  	execve(binaryPath, args, env_args);
  	printf("This is the last line\n");
  	return 1;
}
