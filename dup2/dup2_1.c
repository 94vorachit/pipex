/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 23:53:41 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 23:53:44 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program to illustrate dup2() 
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
    int file_desc = open("tricky.txt",O_WRONLY | O_APPEND);
    
    // here the newfd is the file descriptor of stdout (i.e. 1)
    dup2(file_desc, 1) ; 
        
    // All the printf statements will be written in the file
    // "tricky.txt"
    printf("I will be printed in the file tricky.txt\n");
    
return 0;
}
