/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexDemo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 00:36:09 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/20 00:38:01 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//execDemo.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        //A null terminated array of character 
        //pointers
        char *args[]={"./exec",NULL};
        execvp(args[0],args);
    
        /*All statements are ignored after execvp() call as this whole 
        process(execDemo.c) is replaced by another process (EXEC.c)
        */
        printf("Ending-----");
    
    return 0;
}
