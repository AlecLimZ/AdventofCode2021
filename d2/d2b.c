/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:05:51 by leng-chu          #+#    #+#             */
/*   Updated: 2022/05/22 15:35:01 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward - increase horizontal position
// down - increase aim
// up - decrease aim
// depth = aim * new forward

int	main(int argc, char **argv)
{
	int	forward;
	int	depth;
	int	aim;
	int	i;

	forward = 0;
	depth = 0;
	aim = 0;
	i = 0;
	if (argc <= 1)
		return (0);
	while (argv[++i])
	{
		if (strcmp(argv[i], "forward") == 0)
		{
			forward += atoi(argv[++i]);
			depth += aim * atoi(argv[i]);
		}
		if (!strcmp(argv[i], "down"))
			aim += atoi(argv[++i]);
		if (!strcmp(argv[i], "up"))
			aim -= atoi(argv[++i]);
	}
	printf("forward: %d\n", forward);
	printf("aim: %d\n", aim);
	printf("depth: %d\n", depth);
	printf("Multiply both: %d\n", forward * depth);
	return (0);
}
