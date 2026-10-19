/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:04:06 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 19:06:54 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

The Fork system call is used for creating a new process in Linux, 
and Unix systems, which is called the child process, which runs concurrently 
with the process that makes the fork() call (parent process). 
After a new child process is created, both processes will execute the next 
instruction following the fork() system call.

The child process uses the same pc(program counter), same CPU registers, 
and same open files which use in the parent process. It takes no parameters 
and returns an integer value.

Below are different values returned by fork().

* Negative Value: The creation of a child process was unsuccessful, then it 
returns -1.
* Zero: Returned to the newly created child process.
* Positive value: Returned to parent or caller. The value contains the process 
ID of the newly created child process.

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    // make two process which run same
    // program after this instruction
    pid_t p = fork();
    if (p<0)
    {
      perror("fork fail");
      exit(1);
    }
    printf("Hello world!, process_id(pid) = %d \n",getpid());
    return 0;
}
