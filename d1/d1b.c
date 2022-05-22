/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:09:25 by leng-chu          #+#    #+#             */
/*   Updated: 2022/05/22 09:59:35 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	c;
	int	psum;
	int	nsum;

	i = 0;
	c = -1;
	psum = 0;
	nsum = 0;
	if (argc <= 1)
		return (0);
	while (argv[++i] && argv[i + 1] && argv[i + 2])
	{
		nsum = atoi(argv[i]) + atoi(argv[i + 1]) + atoi(argv[i + 2]);
		if (psum < nsum)
			c++;
		psum = nsum;
	}
	printf("COUNT: %d\n", c);
}
