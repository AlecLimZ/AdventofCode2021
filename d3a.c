/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d3a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:42:56 by leng-chu          #+#    #+#             */
/*   Updated: 2022/05/22 17:40:40 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_tablen(char **v)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (v[++i])
		c++;
	return (c);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		size;
	int		one;
	int		zero;
	char	**box;
	long	gam;
	long	eps;

	size = 1;
	gam = 0;
	eps = 0;
	if (argc <= 1)
		return (0);
	box = (char **)malloc(sizeof(char *) * (strlen(argv[1]) + 1));
	i = -1;
	while (++i < strlen(argv[1]))
		box[i] = calloc(size, sizeof(char));
	box[i] = '\0';
	i = 0;
	k = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			box[j] = realloc(box[j], ++size);
			box[j][k] = argv[i][j];
			j++;
		}
		k++;
	}
	i = -1;
	while (box[++i])
	{
		one = 0;
		zero = 0;
		j = -1;
		while (box[i][++j])
		{
			if (box[i][j] == '0')
				zero++;
			if (box[i][j] == '1')
				one++;
		}
		if (one > zero)
		{
			gam = gam * 2 + 1;
			eps *= 2;
		}
		else
		{
			gam *= 2;
			eps = eps * 2 + 1;
		}
	}
	printf("gamma: %ld\n", gam);
	printf("epsilon: %ld\n", eps);
	printf("power consumption: %ld\n", gam * eps);
	i = -1;
	while (box[++i])
		free(box[i]);
	free(box);
}
