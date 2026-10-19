/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:07:36 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 19:21:54 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Example 2: Calculate the number of times hello is printed.

The number of times 'hello' is printed is equal to the number of processes created. 
Total Number of Processes = 2n, where n is the number of fork system calls. 
So here n = 3, 23 = 8 Let us put some label names for the three lines:

fork ();   // Line 1
fork ();   // Line 2
fork ();   // Line 3
       L1       // There will be 1 child process 
    /     \     // created by line 1.
  L2      L2    // There will be 2 child processes
 /  \    /  \   //  created by line 2
L3  L3  L3  L3  // There will be 4 child processes 
                // created by line 3

So there is a total of eight processes (new child processes and one original process). 
If we want to represent the relationship between the processes as a tree hierarchy 
it would be the following:

Main process: P0
Processes created by the 1st fork: P1
Processes created by the 2nd fork: P2, P3
Processes created by the 3rd fork: P4, P5, P6, P7

        P0
      / | \
     P1 |  \
    / | |   \
   P3 | P2   \
  /   | |     \
 P7  P5 P6    P4
 
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}