/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:40:29 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 20:43:18 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void forkexample()
{
    pid_t p;
    p = fork();
    if(p<0)
    {
      perror("fork fail");
      exit(1);
    }
    // child process because return value zero
    else if ( p == 0)
        printf("Hello from Child!\n");

    // parent process because return value non-zero.
    else
        printf("Hello from Parent!\n");
}
int main()
{
    forkexample();
    return 0;
}

/*
Note: In the above code, a child process is created. fork() returns 0 in the child process 
and positive integer in the parent process. Here, two outputs are possible because 
the parent process and child process are running concurrently. 
So we don’t know whether the OS will first give control to the parent process or the child process.
*/