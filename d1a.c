/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d1a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:09:25 by leng-chu          #+#    #+#             */
/*   Updated: 2022/05/22 10:08:40 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	if (argc <= 1)
		return (0);
	while (argv[++i])
	{
		if (atoi(argv[i - 1]) < atoi(argv[i]))
			c++;
	}
	printf("COUNT: %d\n", c);
}
