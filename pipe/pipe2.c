/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:35:53 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 21:42:14 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
pipe() System call

Conceptually, a pipe is a connection between two processes, such that the 
standard output from one process becomes the standard input of the other process. 
In UNIX Operating System, Pipes are useful for communication between related 
processes(inter-process communication).

* Pipe is one-way communication only i.e we can use a pipe such that One process 
write to the pipe, and the other process reads from the pipe. It opens a pipe, 
which is an area of main memory that is treated as a "virtual file".

* The pipe can be used by the creating process, as well as all its child processes, 
for reading and writing. One process can write to this "virtual file" or pipe 
and another related process can read from it.

* If a process tries to read before something is written to the pipe, the process 
is suspended until something is written.

* The pipe system call finds the first two available positions in the process's open 
file table and allocates them for the read and write ends of the pipe.

Syntax in C language:

int pipe(int fds[2]);

Parameters :

* fd[0] will be the fd(file descriptor) for the read end of pipe.

* fd[1] will be the fd for the write end of pipe.

* Returns : 0 on Success. -1 on error.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
    char inbuf[MSGSIZE];
    int p[2], i;

    if (pipe(p) < 0)
        exit(1);

    /* continued */
    /* write pipe */

    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);

    for (i = 0; i < 3; i++) {
        /* read pipe */
        read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
    }
    return 0;
}
