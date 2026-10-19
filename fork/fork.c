/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:38:26 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 18:40:02 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

In C, fork() creates a new process by duplicating the calling process, 
returning 0 to the child, the child’s PID to the parent, and –1 on failure.

What fork() Does
* fork() creates a child process that is an almost exact copy of the parent process.
* Both processes continue execution from the next instruction after fork(). 
* Parent and child have separate memory spaces, though initially identical. 

Return Values
–1 → Fork failed (no child created).
0 → Returned to the child process.
>0 → Returned to the parent, containing the child’s PID.

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process. PID=%d\n", getpid());
    } else if (pid > 0) {
        printf("Parent process. PID=%d, Child PID=%d\n", getpid(), pid);
    } else {
        perror("fork failed");
    }
    return 0;
}