/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 22:56:45 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/19 22:58:56 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
   // Open a file for writing
   int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
   if (fd < 0) {
       perror("open");
       return 1;
   }
   // Redirect stdout (fd = 1) to the file
   if (dup2(fd, STDOUT_FILENO) == -1) {
       perror("dup2");
       return 1;
   }
   // Now all stdout output goes to output.txt
   printf("This will be written into output.txt\n");
   close(fd); // Safe to close original fd
   return 0;
}
