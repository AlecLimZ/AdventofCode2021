/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:05:51 by leng-chu          #+#    #+#             */
/*   Updated: 2022/05/22 15:25:25 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward - increase horizontal position
// down - increase depth
// up - decrease depth

int	main(int argc, char **argv)
{
	int	forward;
	int	depth;
	int	i;

	forward = 0;
	depth = 0;
	i = 0;
	if (argc <= 1)
		return (0);
	while (argv[++i])
	{
		if (strcmp(argv[i], "forward") == 0)
			forward += atoi(argv[++i]);
		if (!strcmp(argv[i], "down"))
			depth += atoi(argv[++i]);
		if (!strcmp(argv[i], "up"))
			depth -= atoi(argv[++i]);
	}
	printf("forward: %d\n", forward);
	printf("depth: %d\n", depth);
	printf("Multiply both: %d\n", forward * depth);
	return (0);
}
