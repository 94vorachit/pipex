/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 22:05:33 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 22:35:15 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MSGSIZE 16

int main() 
{
    
    char* msg1 = "hello, world #1";
    char* msg2 = "hello, world #2";
    char* msg3 = "hello, world #3";
    char inbuf[MSGSIZE];
    int p[2], pid, nbytes;

    if (pipe(p) < 0)
        exit(1);

    /* continued */
    if ((pid = fork()) > 0) {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);

        // Adding this line will
        // not hang the program
        // close(p[1]);
        // wait(NULL);
    }

    else {
        // Adding this line will
        // not hang the program
        close(p[1]);
        while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
            printf("%s\n", inbuf);
        if (nbytes != 0)
            exit(2);
        printf("Finished reading\n");
    }
    return 0;
}

/*
Output :

hello world, #1
hello world, #2
hello world, #3
(hangs)         //program does not terminate but hangs

Here, In this code After finishing reading/writing, both parent and child 
block instead of terminating the process and that’s why program hangs. 
This happens because read system call gets as much data it requests or as 
much data as the pipe has, whichever is less.

* If pipe is empty and we call read system call then Reads on the pipe will 
return EOF (return value -1) if no process has the write end open.

* If some other process has the pipe open for writing, read will block in 
anticipation of new data so this code output hangs because here write ends 
parent process and also child process doesn’t close.

*/