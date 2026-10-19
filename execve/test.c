/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 00:48:26 by vorhansa          #+#    #+#             */
/*   Updated: 2026/10/20 00:48:38 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) 
{
	int i;
  	int count = atoi(args[1]);
  	for (i = 1; i <= count; i++) 
		printf("[%d]", i);
  	printf("\n");
  	return 0;
}
